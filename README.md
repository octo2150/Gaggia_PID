# Gaggia_PID
Arduino Temperature Control 
of an 
Espresso Machine

By Quinlan Slavin and Owen Kiernan

I. Abstract


The Gaggia Classic, a cheap, mass-produced espresso machine uses an inaccurate temperature and pressure control system. The temperature is controlled by a thermostat and the pressure is set higher than necessary. The thermostat works through metal strips inside of it heating up and turning off the circuit which is only reconnected once the temperature is lower than the target. Therefore, the temperature will never be consistently on-target. The pressure, meanwhile, is set to be able to work with a wide variety of coffees including coarse pre-ground coffee; the higher pressure necessary to extract these leads to a harsher flavor profile for freshly ground coffees. On the contrary, a more expensive machine called the La Marzocco G3 uses a proportionally, integral, derivative controller (PID) which allows it to maintain a much more constant temperature due to having an analog sensor adding the ability to read way the temperature is not only an above or below sensor which allows it to see the difference between the current and target temperatures. The pressure for the La Marzocco G3 is user-controlled, allowing pressure profiles for a more nuanced flavor profile. We modified the Gaggia Classic to be able to provide an espresso brewing experience comparable to the La Marzoko by adding a PID and the ability to adjust the brewing pressure. This was done using an Arduino running an algorithm that attempts to maintain a constant temperature using different gain values. In order to measure the temperature a thermocouple is used. This is a temperature sensor whose resistance changes based on temperature. A breakout board called the MAX6675 is used to translate this value to a temperature and send it to the Arduino. To change the temperature a relay is used to switch 24v used to switch a solid state relay.



II. Engineering Goal
To refine the precision of the temperature and pressure of the Gaggia Classic to be comparable to the more expensive La Marzoko G3.


II. Procedure


Materials:
Gaggia Classic espresso machine
M4 K type thermistor
Thermal conduction paste
MAX6675 breakout board
Arduino Uno 
Solid state relay
Relay
Espresso Single Speed Chilmark Coffee Company Coffee Beans
Coffee grinder
Vernier Temperature Probe
Lab Quest 2 
AC dimmer switch from Amazon	


	Step-by-Step Procedure:
Disassemble the Gaggia Classic and isolate the power leads connected to its thermostat.
Connect the MAX6675 chip to the Arduino and the thermocouple.
Attach the end of the thermocouple to the boiler of the Gaggia Classic and ensure accurate thermal readings with thermal paste.
Connect the relay to the Arduino and the relay to the solid state relay.
Connect the output of the solid state relay to the previously isolated thermostat wires.
Write code that reads the temperature, runs the data through a PID algorithm and uses the output of the algorithm to determine the time the relay is on for each cycle.
Reassemble the Gaggia classic.


Feasibility VII:
Regarding the feasibility of our project, it's not entirely applicable to what we’re trying to do. We aren’t attempting to make something completely new, simply a modification of a product that already exists. The entirety of the project was not cheap, however, the parts used to modify the existing device were very cheap which could show some feasibility as it only cost around 60 and it drastically increased the quality so companies could certainly take advantage of that. Along with that, it wasn’t at all easy; it requires a strong understanding of electricity and code along with the engineering skill to operate the electronics and execute these tasks with high amounts of electricity safely. Overall, this project isn’t marketable in any way from an individual person's perspective. Still, larger companies could definitely implement this into their products to vastly increase the quality at a fraction of the cost.


Conclusion VI:
The goal of the project was to refine the precision of the temperature and pressure of the Gaggia Classic to be comparable to the more expensive La Marzoko G3. And while we were able to effectively regulate the temperature using code, there simply wasn’t enough time to work out a way to safely read the pressure. In the end, however, our attempts to use the PID to keep the temperature at a constant rate paid off and the coffee was able to be held at a relatively steady temperature perfect for pulling an optimal shot.
