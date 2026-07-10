/**
* \file main.c
* \author Dikshant Agrawal
* \date 20.03.2026
*
* \brief Main file — Erika OS tasks, ISRs, ring buffer init
*
* Task structure:
*   Task_Init            -> runs once at boot
*   Task_Background      -> handles button events via Menu_Handler
*   Task_ProtocolHandler -> handles UART RX events via XBee_ProtocolHandler
*
* ISR structure:
*   systick_handler    -> Erika OS 1ms counter tick
*   isr_button         -> maps button pins to Erika events
*   Coordinator_Rx_ISR -> fills CoordinatorBuffer
*   Node1_Rx_ISR       -> fills Node1Buffer
*   Node2_Rx_ISR       -> fills Node2Buffer
*
* Change Log:
*/
 

#include "project.h"
#include "global.h"

#include "watchdog.h"
#include "tft.h"
#include "joystick.h"
#include "log.h"

#include "tsk_control.h"
#include "tsk_hmi.h"

#include "sp_common.h"

//static function to initalize hardware.
static void hal_init(void);


//Task Init : Initialize variables, uart,
TASK(tsk_init){
    
    hal_init();
    
    WD_Start(WD_TIMEOUT_1024);  //Longest period
    

    if(WD_CheckResetBit()){
        LOG_D("Reboot: WATCHODG\n");
    }
    
    else{
        LOG_D("Reboot: Power-On Reset\n");
    }
    
    
    //Reconfigure ISR with the OS parameters
    EE_system_init();
    
    //Start the systick
    EE_systick_start();
    
    SetRelAlarm(Alarm_1ms, 1, 1);
    ActivateTask(tsk_background);
    ActivateTask(tsk_control);
    ActivateTask(tsk_errHandling);

    TerminateTask();
}

//Task Background : No operation
TASK(tsk_background){
    while(1){
        //do something with low prioroty
        __asm("nop");
            
        if(WDT_bitField == 0b00011111){
            WD_Trigger();
        }
    }
}

//Deadline Monitoring
TASK(tsk_errHandling){

    EventMaskType ev = 0;
        
    while(1){
        //Wait, read and clear the event
        WaitEvent(ev_timeout_IO | ev_timeout_CONTROL | ev_timeout_HMI);
        GetEvent(tsk_errHandling,&ev);
        ClearEvent(ev);
		
        if(ev & ev_timeout_IO){
            
            LOG_E("IO TASK TIMEOUT");
            
        }
        
        if(ev & ev_timeout_CONTROL){

            LOG_E("CONTROL TASK TIMEOUT");
            
        }
                
        if(ev & ev_timeout_HMI){

            LOG_E("HMI TASK TIMEOUT");
            
        }
    }
    
    TerminateTask();
}


void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}



//ISR which will increment the systick counter every ms (systick handler)
ISR(systick_handler) {
    CounterTick(Counter_Systick);
}


ALARMCALLBACK(Callback_Alarm1ms)
{   
    RTE_timertick_sp_common_tick(1);
    ActivateTask(tsk_hmi);
    ActivateTask(tsk_io);
    
}

int main(void)
{
    CyGlobalIntEnable;
    
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();

    
    for(;;)
        StartOS(OSDEFAULTAPPMODE); 
}


static void hal_init(void){
    //Initialization
    TFT_init();
    TFT_setBacklight(255);
    TFT_fillScreen(BLACK);
    TFT_setTextColor(WHITE);
    TFT_setTextSize(1);
    
    //Comparator Start
    Comp_Decoder_Start();
    
    //UART Debug Start
    UART_LOG_Start();
    
    //ADC Start
    JOYSTICK_Init();
    Engine_PWM_Start();
    
    //LED Start
    RGB_PWM_green_Start();
    RGB_PWM_blue_Start();
    RGB_PWM_red_Start();
    PWM_red_Start();
    PWM_yellow_Start();
    PWM_green_Start();
    
    //Turn OFF all the LEDs
    RGB_PWM_red_WriteCompare(0);
    RGB_PWM_green_WriteCompare(0);
    RGB_PWM_blue_WriteCompare(0);
    PWM_red_WriteCompare(0);
    PWM_green_WriteCompare(0);
    PWM_yellow_WriteCompare(0);
    
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;     // Activate the Trace unit
    DWT->CYCCNT = 0;                                    // Reset counter to 0
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;                // Activate the Cycle Counter
    
}


ISR2(isr_shutdown){
    
    //OS SHUTDOWN
    ShutdownOS(E_OK);

}


/* [] END OF FILE */
