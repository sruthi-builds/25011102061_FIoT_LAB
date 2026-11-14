# CAT3 – Timer-Based LED Pattern Generator and Button Interrupt Controller

## EXP
CAT3

## DATE
27/07/2026 (Week 2)

## NAME OF EXP
Timer-Based LED Pattern Generator and Button Interrupt Controller

## HARDWARE SETUP / PLATFORM

- **Development Board:** 8051 Universal Development Board
- **Microcontroller:** AT89S52
- **Programming Environment:** Keil µVision
- **Operating Voltage:** +5V
- **Output Components:** Four LEDs
- **Output Port:** Port 1
- **LED Pins:** P1.1, P1.2, P1.3 and P1.4
- **Input Components:** Push-buttons
- **Input Pins:** P2.7 and P2.6

## TASK NO

### Activity: Timer-Based LED Pattern Generator and Button Interrupt Controller

Design and implement a register-level GPIO controller for a microcontroller development board.

Configure four LEDs as digital outputs and push-button inputs. Using bare-metal Embedded C and direct memory-mapped register access, implement a four-state LED control system.

The required operating modes are:

1. Running LED pattern.
2. Binary counter.
3. Alternating LED pattern.
4. All LED flashing.

Implement switch debouncing to ensure that one physical button press produces one state transition.

## Circuit Diagram

![Circuit Diagram](circuit.png)

## Core Logic / Pseudocode / Code Base

### 1. Core Logic

The program implements four LED operating modes using direct GPIO port manipulation on the AT89S52 microcontroller.

- Four LEDs are controlled through Port 1.
- Push-button inputs are checked through Port 2.
- A mode variable determines the current LED pattern.
- A software delay function controls the interval between LED changes.
- Button inputs are checked to change the operating mode.

### 2. Operating Modes

| Mode | Name | Implementation |
|---|---|---|
| Mode 1 | Running LED | LEDs are switched ON sequentially. |
| Mode 2 | Binary Counter | A counter iterates from 0 to 15. |
| Mode 3 | Alternating Pattern | Alternates between hexadecimal values 0x0A and 0x14. |
| Mode 4 | All LED Flash | Alternates between 0x1E and 0x00. |

### 3. Button Control

The program checks the push-button inputs using the `check_button()` function.

- P2.7 is used to increment the operating mode.
- P2.6 is used to decrement the operating mode.
- The program waits for the pressed switch to be released.
- The mode value is maintained between 1 and 4.

### 4. Source Files

| File | Description |
|---|---|
| `ledpatterns.c` | Main program implementing LED patterns and button control |
| `Day2Task1.uvproj` | Keil project configuration file |
| `STARTUP.A51` | 8051 startup assembly file |

### 5. Implementation

**ledpatterns.c**

The program uses the `reg51.h` header to access the 8051 registers.

The `sbit` keyword is used to define the push-button inputs on P2.7, P2.1, P2.6 and P2.2.

A global mode variable determines the LED operating pattern.

The `delay()` function uses nested loops to generate software delays.

The `check_button()` function detects button presses, waits for button release and updates the operating mode.

The main function continuously executes the selected LED pattern.

### 6. Programming Approach

- Bare-metal Embedded C programming.
- Direct GPIO register access.
- Port manipulation using the P1 and P2 registers.
- Software-based delay generation.
- Button polling and mode control.
- No Arduino APIs, HAL libraries or RTOS services.

## INFERENCE

The experiment demonstrates GPIO programming and basic embedded system control using the AT89S52 microcontroller.

Four LED operating patterns are implemented using direct port manipulation. Push-button inputs are used to change the operating mode, while software delay loops control the timing of the LED patterns.

The experiment provides practical understanding of digital input/output configuration, LED pattern generation, button handling and embedded C programming.

## OBSERVATIONS

- Four LED patterns are implemented.
- The operating mode is controlled using push-button inputs.
- The mode variable maintains the current operating state.
- Software delay loops provide intervals between LED transitions.