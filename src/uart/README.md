====== UART ======
===== Overview =====
The UART is used for serial communication with a peripheral, modem (data carrier equipment, DCE) or data set. Data is
written from a master (CPU) over the APB bus to the UART and it is converted to serial form and transmitted to the
destination device. Serial data is also received by the UART and stored for the master (CPU) to read back. 

The UART contains registers to control the character length, baud rate, parity generation/checking, and interrupt
generation. Although there is only one interrupt output signal from the UART, there are several prioritized interrupt
types responsible for its assertion. Each of the interrupt types can be separately enabled/disabled with the control
registers.

The UART has 16450 and 16550 modes of operation, which are compatible with a range of standard software drivers.
In 16550 mode, transmit and receive operations are both buffered by FIFOs. In 16450 mode, these FIFOs are disabled.

The UART supports word lengths from five to eight bits, an optional parity bit and 1, 1.5 or 2 stop bits, and is fully
programmable by an AMBA APB CPU interface. A 16-bit programmable baud rate generator and an 8-bit scratch
register are included, together with separate transmit and receive FIFOs. Eight modem control lines and a diagnostic
loop-back mode are provided. 

Interrupts can be generated for a range of TX Buffer/FIFO, RX Buffer/FIFO, Modem Status and Line Status conditions. 

The UART includes the following features: 

  - Compatible with industry-standard 16550 UARTs
  - 64-Bytes Transmit and receive data FIFOs
  - DMA controller interface
  - Software/ Hardware Flow Control
  - Programmable Transmit Holding Register Empty interrupt
  - Interrupt support for FIFOs, Status Change 

===== UART Timing Diagram =====
TODO


