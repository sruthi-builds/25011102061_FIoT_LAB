# CAT 8 – GPIO Input/Output

**EXP CAT:** CAT 8  
**TASK:** TASK 8B  
**NAME:** Event-Based LED Control

## Objective
To control the onboard LED using a push button and implement event-based toggling with debouncing.

## Hardware and Software Requirements
- STM32F103C8T6 Blue Pill
- Push button
- STM32CubeMX
- Keil uVision

## Pin Connections

| Component | STM32 Pin | Configuration |
|---|---|---|
| Push Button | PA3 | Input, active LOW, internal pull-up |
| Onboard LED | PC13 | Output, active LOW |

## Circuit Diagram

![Circuit Diagram](circuit.png)

## Working Principle
- PA3 is configured as a GPIO input with an internal pull-up.
- When the button is pressed, PA3 reads LOW.
- A 20 ms delay is used to debounce the button.
- The button state is checked again to confirm a valid press.
- The onboard LED connected to PC13 toggles its state once for every valid button press.
- The program waits until the button is released before detecting another press.

## Algorithm
1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize PA3 as input with pull-up.
4. Initialize PC13 as output.
5. Continuously read the button state.
6. If the button is pressed, wait for 20 ms.
7. Check the button state again.
8. If the press is valid, toggle the LED.
9. Wait until the button is released.
10. Repeat continuously.

## HAL Functions Used
- `HAL_Init()`
- `HAL_GPIO_ReadPin()`
- `HAL_GPIO_WritePin()`
- `HAL_GPIO_TogglePin()`
- `HAL_Delay()`
- `HAL_RCC_OscConfig()`
- `HAL_RCC_ClockConfig()`
- `HAL_GPIO_Init()`

## Source Code
`Core/Src/main.c`

## Result
The onboard LED toggles once for every valid button press. Debouncing prevents unwanted multiple toggles caused by button bouncing.

## Inference
This experiment demonstrates event-based GPIO control and basic software debouncing using the STM32 microcontroller.
