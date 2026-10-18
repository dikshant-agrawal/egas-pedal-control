# E-Gas Electronic Throttle Control on Erika RTOS

An electronic throttle (E-Gas) system on PSoC 5LP: the accelerator input — a joystick acting as the pedal — is sampled via ADC, processed through an AUTOSAR-style software-component architecture, and used to control engine speed — with brake override and RTE-based communication between components.

## What it does
Implements the automotive E-Gas (throttle-by-wire) concept as a layered real-time system: the control signal travels purely electronically — joystick ADC in, engine PWM out, no mechanical linkage. A generated Runtime Environment (RTE) decouples the application software components: `swc_egas` reads the joystick 'pedal' (ADC) and commands engine speed, while dedicated tasks handle control, I/O and the HMI, all scheduled by Erika (OSEK) tasks, events and alarms.

## Live digital twin
**https://dikshant-agrawal.github.io/egas-pedal-control/** — an interactive browser twin of the `swc_egas` PID speed controller (`docs/index.html`).

| Mode | What it does |
|---|---|
| **Simulation** | Runs the firmware's control law (same gains Kp 0.6 / Ki 2.0 / Kd 0.01, 100 ms cycle, derivative-on-error, conditional-integration anti-windup) against a simulated motor plant. Move the throttle, retune the gains, hit *Load Kick* and watch the response. |
| **Hardware (serial)** | Connects to the board over the debug UART using the browser's Web Serial API (Chrome / Edge) — pick the baud rate and the COM port in the browser's dialog. Plots target / current / error live; the control output and P/I/D terms are recomputed by the twin from the measured data. |

### Serial stream from the firmware
`swc_egas.c` prints one line per control cycle (`EGAS_SERIAL_STREAM`, set to `0` to disable):

```
DEBUG   : T:3120 C:2011 E:1109
```

| Field | Meaning | Unit / sign |
|---|---|---|
| `T` | target speed (from the joystick) | rpm, `-` = reverse, `0` = neutral |
| `C` | current (measured) speed | rpm, same sign convention |
| `E` | error = `T - C` | rpm |

UART settings: 115200 baud, 8N1, lines end in `\n`. The page also accepts raw `target,current[,error]` lines. Samples whose `E` does not match `T - C` are dropped as corrupt (same filter as `docs/live_pid_plot.m`, the MATLAB live plot that reads the same stream).

> Status: simulation mode and the control-law port are verified against `swc_egas.c`. Hardware mode has been tested against a mock serial port; test on the board is pending.

## Features
- AUTOSAR-style architecture: SWCs communicating only through generated RTE signals
- `swc_egas` — joystick 'pedal' acquisition (ADC) + engine speed control with brake interaction
- Task set: `tsk_control`, `tsk_io`, `tsk_hmi` + ISRs and ring-buffered messaging
- PID engine-speed evaluation (see `docs/PID.m` MATLAB analysis and `docs/motor_log.txt` captured data)
- UART telemetry stream (`T/C/E` per 100 ms cycle) feeding the MATLAB live plot and the browser digital twin
- Timing analysis of the RTE schedule (`docs/RTE_Timing.pdf`)

## Tech stack
Embedded C, Erika Enterprise (OSEK/VDX), RTE code generation, PSoC 5LP (Cortex-M3), ADC/PWM, MATLAB for control analysis.

## Build & run
1. Open `Lab_01.cydsn` in **PSoC Creator 4.x** (ErikaOS sources included)
2. Build and flash a PSoC 5LP development board
3. Joystick input via ADC channel; engine speed observable via PWM/log output

## Structure
- `Lab_01.cydsn/source/asw/` — application SWCs and tasks
- `Lab_01.cydsn/source/rte/` — generated RTE signal layer
- `Lab_01.cydsn/source/bsw/` — board support (TFT, logging, services, msg)
- `docs/` — PID analysis, motor log, timing documentation, and the digital twin (`index.html`)
