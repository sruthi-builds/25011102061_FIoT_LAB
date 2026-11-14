# CAT 10 – UART Communication

**EXP CAT:** CAT 10  
**TASK:** TASK 10A  
**NAME:** UART-to-UART Communication

## Objective
To configure two UART peripherals on the STM32F103C8T6 microcontroller and demonstrate data transmission between them.

## Hardware and Software Requirements
- STM32F103C8T6 Blue Pill
- Two UART-compatible serial devices
- STM32CubeMX
- Keil uVision

## Pin Connections

**USART1**

| UART Device 1 | STM32 Pin |
|---|---|
| TX | PA10 (USART1_RX) |
| RX | PA9 (USART1_TX) |
| GND | GND |

**USART2**

| STM32 Pin | UART Device 2 |
|---|---|
| PA2 (USART2_TX) | RX |
| PA3 (USART2_RX) | TX |
| GND | GND |

## Circuit Diagram

![Circuit Diagram](circuit.png)

## UART Configuration

| Parameter | USART1 | USART2 |
|---|---|---|
| Baud Rate | 115200 | 115200 |
| Word Length | 8 Bits | 8 Bits |
| Stop Bits | 1 | 1 |
| Parity | None | None |
| Mode | Transmitter and Receiver | Transmitter and Receiver |
| Hardware Flow Control | None | None |

## Working Principle
- USART1 and USART2 are initialized at 115200 baud.
- The program first transmits the string `AT` followed by a carriage return and newline through USART1.
- The STM32 then waits to receive one byte through USART1.
- Each received byte is transmitted through USART2.
- This process continues continuously.

## Algorithm
1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO.
4. Initialize USART1 and USART2.
5. Transmit the initial `AT` command through USART1.
6. Wait for one byte of data through USART1.
7. Transmit the received byte through USART2.
8. Repeat continuously.

## HAL Functions Used
- `HAL_Init()`
- `HAL_UART_Init()`
- `HAL_UART_Receive()`
- `HAL_UART_Transmit()`
- `HAL_RCC_OscConfig()`
- `HAL_RCC_ClockConfig()`

## Source Code
`Core/Src/main.c`

## Result
The STM32 receives data through USART1 and forwards each received byte through USART2.

## Inference
This experiment demonstrates the configuration and use of multiple UART peripherals for serial data communication using the STM32 microcontroller.
