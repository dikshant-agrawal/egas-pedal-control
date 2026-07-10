# E-Gas Pedal Control — Drive-by-Wire on Erika RTOS

A drive-by-wire accelerator-pedal system on PSoC 5LP: pedal position is sampled via ADC, processed through an AUTOSAR-style software-component architecture, and used to control engine speed — with brake override and RTE-based communication between components.

## What it does
Implements the classic automotive E-Gas concept as a layered real-time system. A generated Runtime Environment (RTE) decouples the application software components: `swc_egas` reads the pedal (ADC) and commands engine speed, while dedicated tasks handle control, I/O and the HMI, all scheduled by Erika (OSEK) tasks, events and alarms.

## Features
- AUTOSAR-style architecture: SWCs communicating only through generated RTE signals
- `swc_egas` — pedal acquisition (ADC) + engine speed control with brake interaction
- Task set: `tsk_control`, `tsk_io`, `tsk_hmi` + ISRs and ring-buffered messaging
- PID engine-speed evaluation (see `docs/PID.m` MATLAB analysis and `docs/motor_log.txt` captured data)
- Timing analysis of the RTE schedule (`docs/RTE_Timing.pdf`)

## Tech stack
Embedded C, Erika Enterprise (OSEK/VDX), RTE code generation, PSoC 5LP (Cortex-M3), ADC/PWM, MATLAB for control analysis.

## Build & run
1. Open `Lab_01.cydsn` in **PSoC Creator 4.x** (ErikaOS sources included)
2. Build and flash a PSoC 5LP development board
3. Pedal input via ADC channel; engine speed observable via PWM/log output

## Structure
- `Lab_01.cydsn/source/asw/` — application SWCs and tasks
- `Lab_01.cydsn/source/rte/` — generated RTE signal layer
- `Lab_01.cydsn/source/bsw/` — board support (TFT, logging, services, msg)
- `docs/` — PID analysis, motor log, timing documentation
