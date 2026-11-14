# CAT 8 – GPIO Input/Output

**EXP CAT:** CAT 8  
**TASK:** TASK 8C  
**NAME:** Short Press and Long Press Detection

## Objective
To distinguish between short and long button presses and control the onboard LED accordingly, using non-blocking long-press detection.

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
- PC13 is configured as a GPIO output to control the onboard LED.
- A 20 ms debounce interval is used to identify stable button states.
- A short press (less than 1 second) toggles the LED.
- A long press (1 second or more) activates blinking mode.
- In blinking mode, the LED toggles every 500 ms without using blocking delays.
- Blinking continues after the button is released.
- A subsequent short press stops blinking and turns the LED OFF.

## Algorithm
1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize PA3 as input with pull-up.
4. Initialize PC13 as output.
5. Read the button state continuously.
6. Apply 20 ms debounce to detect stable button states.
7. Record the time when the button is pressed.
8. If the button is held for 1 second or more, activate blinking mode.
9. If the button is released before 1 second, toggle the LED.
10. In blinking mode, toggle the LED every 500 ms.
11. If a short press occurs during blinking mode, stop blinking and turn the LED OFF.
12. Repeat continuously.

## HAL Functions Used
- `HAL_Init()`
- `HAL_GPIO_ReadPin()`
- `HAL_GPIO_WritePin()`
- `HAL_GPIO_TogglePin()`
- `HAL_GetTick()`
- `HAL_RCC_OscConfig()`
- `HAL_RCC_ClockConfig()`
- `HAL_GPIO_Init()`

## Source Code
`Core/Src/main.c`

## Result
The onboard LED toggles for a short press and enters blinking mode for a long press. Blinking is implemented using non-blocking time checks.

## Inference
This experiment demonstrates short-press and long-press detection, software debouncing, and non-blocking LED control using the STM32 microcontroller.
