# CAT2 – 8051 Tool Chain Setup and LED Blinking

## EXP
CAT2

## DATE
20/07/2026 (Week 2)

## NAME OF EXP
8051 Tool Chain Setup – Development Board – AT89S52

## HARDWARE SETUP / PLATFORM

- **Development Board:** 8051 Universal Development Board
- **Microcontroller:** AT89S52
- **Programming Environment:** Keil µVision
- **Programming Interface:** ISP Programming Connector
- **Operating Voltage:** +5V
- **External Component:** LED
- **GPIO Port:** Port 1
- **GPIO Pin:** P1.7
- **Power Supply:** USB-C (+5V)

## TASK NO

### Task 1: Hardware Board Bring-Up

- Identify the microcontroller, debugger/programmer, power source, user LED and relevant GPIO pin.
- Verify the board's power rails using a digital multimeter.
- Identify the LED GPIO port and pin from the datasheet and schematic.
- Establish communication between the host computer and the target MCU.

### Task 2: Bare-Metal LED Blink

- Configure the LED GPIO as an output using direct register access.
- Write a delay mechanism using a simple software loop.
- Blink the LED at approximately 1 Hz.

### Task 3: Custom Delay Library

Develop a custom library function for delay functionality.

## Hardware Bring-Up Sheet

| Parameter | Student Entry |
|---|---|
| MCU | AT89S52 |
| CPU Core | 8051-compatible |
| Operating Voltage | +5V |
| Debug / Programming Interface | ISP |
| LED GPIO Port | Port 1 |
| LED GPIO Pin | P1.7 |
| LED Active State | HIGH (based on code and connection) |
| LED Frequency (Hz) | Not measured |

*Note: The LED frequency has not been experimentally verified. The code uses a software delay loop.*

## Circuit Diagram

![Circuit Diagram](circuit.png)

### Hardware Connections

- P1.7 of the AT89S52 is connected to an external LED through a current-limiting resistor.
- The other terminal of the LED is connected to GND.
- The development board operates using a +5V supply.
- The resistor value was not recorded.

## Core Logic / Pseudocode / Code Base

### 1. Core Logic

The experiment demonstrates LED blinking using direct register access on the AT89S52 microcontroller.

- The `reg51.h` header provides access to 8051 registers.
- The `sbit` keyword is used to declare P1.7 as the LED control pin.
- A custom delay function is implemented using nested loops.
- The LED is switched ON and OFF continuously.
- The delay function creates an interval between successive state changes.

### 2. Pseudocode

1. Start the program.
2. Declare P1.7 as the LED control pin.
3. Enter an infinite loop.
4. Set the LED pin HIGH.
5. Call the custom delay function.
6. Set the LED pin LOW.
7. Call the custom delay function again.
8. Repeat continuously.

### 3. Source Files

| File | Description |
|---|---|
| `bled.c` | Main program controlling LED blinking |
| `delay.c` | Custom software delay implementation |
| `delay.h` | Header file containing delay function declaration |
| `STARTUP.A51` | 8051 startup assembly file |
| `Day1Task1.uvproj` | Keil project configuration |

### 4. Implementation

**bled.c**

The main program includes `reg51.h` and `delay.h`. It declares P1.7 as the LED control pin using the `sbit` keyword.

An infinite loop continuously switches the LED pin HIGH and LOW, with a delay between each transition.

**delay.c**

Implements a software delay using two nested loops. The delay function is called from the main program to create visible intervals between LED state changes.

**delay.h**

Contains the declaration of the custom delay function, allowing it to be accessed from the main program.

### 5. Programming Approach

- Bare-metal embedded C programming.
- Direct GPIO register manipulation.
- Custom software delay implementation.
- No Arduino APIs, HAL libraries or RTOS services are used.

## INFERENCE

The experiment demonstrates basic microcontroller programming using the AT89S52.

Direct port manipulation is used to control an external LED through P1.7. A custom software delay function is implemented using nested loops to introduce delays between LED state changes.

The experiment provides practical understanding of GPIO configuration, bare-metal programming, software delay generation and the development of reusable C functions and header files.