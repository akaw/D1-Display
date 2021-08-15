# D1-Display 

Wemos D1 mini Shield

## Complete Pinout

| Pin/Const | Function | ESP-8266 Pin | GPIO | Comment |
| --- | -------- | ------------ | ---- | ------- |
| TX | TXD | TXD | GPIO1 ||
| RX | RXD | RXD | GPIO3 ||
| A0 | AI | A0 | ADC0 | Analog input max 3.3V input |
| D0 | IO || GPIO16 | High at boot, pull down to GND <br> no interrupt <br> no I2C support <br> Used to wake up from deep sleep |
| D1 | IO | SCL | GPIO5 | Display |
| D2 | IO | SDA | GPIO4 | Display |
| D3 | IO |  | GPIO0 | 10k Pull-up <br> Boot fail if pulled low |
| D4 | IO | BUILTIN_LED | GPIO2 | 10k Pull-up <br> Boot fail if pulled low <br> Set to LOW for BUILTIN_LED on |
| D5 | IO | SCK | GPIO14 ||
| D6 | IO | MISO | GPIO12 ||
| D7 | IO | MOSI | GPIO13 ||
| D8 | IO | CS | GPIO15 | 10k Pull-down |
| G | Ground | GND ||
| 5V | 5V | - ||
| 3V3 | 3.3V | 3.3V ||
| RST | Reset | RST ||

Using GPIO0 (D3), GPIO2 (D4) and GPIO15 (D8) as Outputs

As noted above, these pins will already have a resistor connected to either VCC (GPIO0 and GPIO2) or GND for GPIO15. This determines how any external device, like a relay or led+resistor, must be connected. For GPIO0 and GPIO2, an external relay must be connected between VCC and the pin so that it does not interfere with the action of the pull up resistor. Conversely an external relay connected to GPIO15 must be connected between GND and the pin so that is does not interfere with the action of the pull down resistor.

To activate the external device, GPIO0 or GPIO2 must be driven LOW (Active LOW) while GPIO15 must be driven HIGH (Active HIGH).

For more information, see <https://www.forward.com.au/pfod/ESP8266/GPIOpins/index.html>
