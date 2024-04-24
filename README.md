# F-16 ICP Button Box

# Summary

This project seeks to document my progress on building a F-16 ICP (Integrated Control Panel) along with some functionality from the Misc Armament Panel for use in DCS.
<br>

![drawIO Diagram](Images/Real-F16.jpeg)

<br>
My approach relies on using 3 arduino pro micro boards connected via their i2c allowing for only 1 usb for output rather than 3. There is an oppertunity to use a board with more GPIO like a bluepill board or use a GPIO expander like the mpc23017 however, with my limited electrical engineering ability it was easier to just use the arduinos.

<br>

A decision was made early on to use solder to connect any switches rather than using any connectors mainly as I wanted to use this as a learning oppertunity but also to avoid any connections coming loose overtime.

<br>

# Diagram

![drawIO Diagram](Images/drawIO.png)

# Requirements / BOM

## Tools

- Soldering Iron
- Solder
- Something to cut plastic

## Hardware

- 4 SPST Switches
- 2 DPST Switches
- 1 Rocker Switch
- 12 Cherry MX Switches
- 9 Momentary Push Buttons
- Project Box
- 3 Ardunio Pro Micro's

<br>

# Steps

## Dissasembly

To begin after creating the plan I began disassembling an old keyboard I had to salvage the cherry MX switches, this involved using a desoldering pump to remove any solder.
<br>

To begin actually wiring up the icp I initially wired up the 3 arduinos via to take advantage of the i2c protocol by wiring the SDA, SCL, VCC and Ground pins.
After this ran some code to verify the boards were communicating with one another using a button to test if the master board was correctly reading the inputs from the slave board.

<center>
<img src="Images/i2cWiring.jpeg" width='800' height='400' align='centre'>
</center>

<br>
The code being used to power the ICP is taken from Matthew Heironimus and his work on the ardunio joystick library which I have modified to work with the i2c protocol and 2 other arduios being used as slaves.

## Construction

To begin construction on the ICP the project box was used as the shell of the ICP, initially the SPST and DPST switches were installed as unlike the cherry keys they can be mounted straight into a 12mm circular hole which was cut with a step bit which reduced any melting and provided cleaner cuts.
