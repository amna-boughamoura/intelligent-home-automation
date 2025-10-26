# System Architecture

This diagram shows how sensors, control logic, and actuators communicate within the home automation system:

[DHT11 / LM35] --->|
[LDR]              |--> Arduino Processing --> [LCD Display]
[Soil Sensor] --->|                            |
                                               --> [Light Relay → Lights]
                                               --> [Pump Relay → Irrigation]

Key Concepts:
- Sensors collect environmental data in real time
- Arduino executes automation rules (if dark → lights ON, if soil dry → pump ON)
- LCD shows live values for usability
- System can be expanded with ESP32 for remote monitoring and control
