# Wiring Guides for Moddable supported SPI displays

Copyright 2018 Moddable Tech, Inc.  
Revised: January 2, 2018


## Switch Science reflective LCD display
**Part:** 2858: JDI - REFLCD - 128 

**Size:** 1.28", 176 × 176

**Type:** Color reflective LCD (no backlight)

**Interface:** SPI

**Drivers:** video [lpm013m126a](../../documentation/drivers/lpm013m126a/lpm013m126a.md), No touch

**Availability:** [1.28" Switch Science Color reflective LCD] (https://translate.google.com/translate?hl=en&sl=ja&tl=en&u=https%3A%2F%2Fwww.switch-science.com%2Fcatalog%2F2874%2F)

**Description:** Moddable purchased this display in Tokyo. [Here](https://translate.googleusercontent.com/translate_c?depth=1&hl=en&rurl=translate.google.com&sl=ja&sp=nmt4&tl=en&u=https://www.switch-science.com/catalog/2858/&usg=ALkJrhijtlYZnC4qJ2sRkLE3mkVZujVU1w) is some info on the display.

![Generic SPI Display](images/switch-science-LCD-relective-display.jpg)

**Moddable Sample code:** The Piu example [transitions](../../examples/piu/transitions/) is good for testing this display. The build command below includes the -d, debug flag.

```
cd $MODDABLE/examples/piu/transitions
mcconfig -d -m -r 0 -f rgb332 -p esp screen=lpm013m126a touch="" 
```


**ESP8266 Pinout:**

| Switch Science LCD | ESP8266 | ESP8266 Devboard label
| --- | --- | --- |
| 14 - SCLK | GPIO 14 | (D5)
| 13 - SI | GPIO 13 | (D7) 
| 15 - SCS | GPIO 15 | (D8)
| DISP | 3.3v | 
| GND | GND | 
| VIN | 3.3v | 

![Generic 2.4"-2.8" wiring illustration](images/switch-science-esp-wiring.png)

