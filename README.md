# Serial Sniffer

ESP-based device for snifferring serial communication between two devices. It redirects traffic from one serial port to another but
also redirecting to the debug serial port with adding comments like `#1 -> #2`.

## Connections

### ESP32

Device #1 | ESP32
----------|--------
RX        | GPIO19
TX        | GPIO18

Device #2 | ESP32
----------|--------
RX        | GPIO17 (TX2)
TX        | GPIO16 (RX2)
