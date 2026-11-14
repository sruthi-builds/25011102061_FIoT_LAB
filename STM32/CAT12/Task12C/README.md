# CAT 12 – GPIO Button-Controlled LED

**EXP:** CAT 12 – TASK 12C

## Experiment Name
Short Press and Long Press LED Control

## Board
STM32 Development Board

## Components Used
- STM32 Development Board
- Push Button
- External LED
- Connecting wires

## Pin Connections

| Component | STM32 Pin |
|---|---|
| Push Button | PC13 |
| External LED | PA5 |
| LED GND connection | GND |

## Description
This experiment demonstrates controlling an external LED using short and long button presses. The STM32 reads the button state through PC13 and controls the LED connected to PA5.

## Working
1. Configure PC13 as a GPIO input.
2. Configure PA5 as a GPIO output.
3. Continuously monitor the button state.
4. Apply a 20 ms delay for button debouncing.
5. Measure the duration of the button press.
6. If the press duration is less than 1 second, toggle the LED state.
7. If the press duration is 1 second or more, activate continuous LED blinking with a 500 ms delay.

## Circuit Diagram

![Circuit Diagram](circuit.png)

## HAL Functions Used
- `HAL_GPIO_ReadPin()`
- `HAL_GPIO_WritePin()`
- `HAL_GPIO_TogglePin()`
- `HAL_GetTick()`
- `HAL_Delay()`

## Source File
`Core/Src/main.c`

## Inference
A short button press toggles the external LED ON or OFF. A long button press starts continuous blinking of the LED. The blinking continues until the board is reset.