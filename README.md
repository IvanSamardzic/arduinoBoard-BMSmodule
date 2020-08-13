Arduino Uno R3 Battery Management System Module
---

#Extension Board can be aslo connected to Nano, Micro Pro and other Arduino Boards

The goal of this project is to design, sketch and program a simple pcb board that is used as an extension board for an Arduino Uno microcontroller. Each item or element within the
electronic circuit is explained in detail.

Full Arduino Uno schematic: https://www.circuito.io/blog/arduino-uno-pinout/

Battery management system explanation video tutorials: https://www.youtube.com/watch?v=MZyY1dpka7c

Problem
---
A DIY Powerwall is the DIY construction of a pack of battery cells to create an energy store which can be used via inverters to power electrical items in the home. Generally cells are salvaged/second hand, and typically use Lithium 18650 cells.

Lithium batteries need to be kept at the same voltage level across a parallel pack. This is done by balancing each cell in the pack to raise or lower its voltage to match the others.

Existing balancing solutions are available in the market place, but at a relatively high cost compared to the cost of the battery bank, so this project is to design a low-cost, simple featured BMS/balancer.

A large number of people have utilised the commercial BATRIUM BMS system in their powerwall devices.

Circuit explanation
---
The schematic attached in this repository is very simple. Electronic circuit can be divided in two parts, power supply module and analog to digital conversion peripheral. 

First part has the a function of generating a stable voltage to the ADC peripheral (main IC) always has the same voltage reference. Power supply module is made by using TPS6107x
integrated circuit (buck/boost converter IC). Looking in the IC datasheet, there will be represented some examples how to use this integrated circuit as well as schematics for that 
purposes. 

TPS61073 IC data : https://www.ti.com/lit/ds/symlink/tps61073.pdf?ts=1597321829455

The TPS6107x devices provide a power supply solution for products powered by either a one-cell, two-cell, or three-cell alkaline, NiCd or NiMH, or one cell Li-ion or Li-polymer
battery. In this example, TPSxx will be used as both buck and boost converter. It gives a stable 3.3 V (600 mA) signal at its output while at its input, voltage value varies
in range from 3 V to 4.2 V in case system manages Li-Ion battery cells.

In different modes, integrated circuit has the different efficiency. Module has cca. 80 percent efficiency in the boost mode and over 90 percent in its buck mode. Power supply is
connected directly to batteries meaning that we do not need additional external power source. Power supply main part is Texas Instruments integrated circuit TPS6107x which stands as
a buck/boost converter generating stable 600 mA and 3.3 V at the output. 

All 4.7 uF capacitors connceted to TPS6107x chip are used to give the maximum power at the output. Two 4.7 uF X7R capacitors instead of one 10uF capacitor are better solution due to
less value noise generation.

The output voltage of the TPS6107x dc/dc converter can be adjusted with an external resistor divider. The typical value of the voltage at the FB pin is 500 mV. The maximum
recommended value for the output voltage is 5.5 V. The current through the resistive divider should be about 100 times greater than the current into the FB pin.

The typical current into the FB pin is 0.01 µA, and the voltage across R2 is typically 500 mV. Based on those two values, the recommended value for R2 should be lower than 500 kΩ, in
order to set the divider current at 1 µA or higher. Because of internal compensation circuitry, the value for this resistor should be in the range of 200 kΩ. The second parameter for
choosing the inductor is the desired current ripple in the inductor. 

Normally, it is advisable to work with a ripple of less than 20% of the average inductor current. A smaller ripple reduces the magnetic hysteresis losses in the inductor, as well as
output voltage ripple and EMI. With this calculated value and the calculated currents, it is possible to choose a suitable inductor. In typical applications, a 4.7-µH inductance is
recommended. The device has been optimized to operate with inductance values between 2.2 µH and 10 µH.

ADC peripheral module is in charge of measuring battery voltage and temperature temporary values. For voltage measurements, voltage divides is used to divide maximal 4.3 V value to 
2.4 V value due to ADC characteristics. Divide ratio equals 680 / 680 + (470 + 47) =  0.568. Also, a small 100 nF capacitor is added to integrate the battery voltages.

For thermal measurements, 10kΩ NTC thermistor is used and together with 10 kΩ resistor make voltage divider in which voltage is raised when thr temperature is raised due to divider
configuration.

NTC data: https://product.tdk.com/en/search/sensor/ntc/ntc_element/info?part_no=B57861S0103A039

Required components
---
TPS61073 converter ic
