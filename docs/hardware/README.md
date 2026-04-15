# Hardware

<div align="center">
<a href="./resources/unit_sch_v_1_0_0_ue0117_devlab_dvi_to_fpc_adapter.pdf"><img src="resources/Schematics_icon.jpg?raw=false" width="200px"><br/>Schematic</a>
</div>

## Pinout

<div align="center">
    <a href="#"><img src="resources/unit_pinout_v_0_0_1_ue0094_icp10111_barometric_pressure_sensor_en.jpg" width="500px"><br/>Pinout</a>
    <br/>
    <br/>
    <br/>
</div>

## Pin & Connector Layout

<div align="center">

| Pin   | Voltage Level | Function                                                  |
|-------|---------------|-----------------------------------------------------------|
| VCC   | 3.3 V – 5.5 V | Provides power to the on-board regulator and sensor core. |
| GND   | 0 V           | Common reference for power and signals.                   |
| SDA   | 1.8 V to VCC  | Serial data line for I²C communications.                  |
| SCL   | 1.8 V to VCC  | Serial clock line for I²C communications.                 |

</div>


> **Note:** The module also includes a Qwiic/STEMMA QT connector carrying the same four signals (VCC, GND, SDA, SCL) for effortless daisy-chaining.

## Topology

<div align="center">

<div align="center">
<a href="./resources/unit_topology_v_1_0_0_ue0117_devlab_dvi_to_fpc_adapter.png"><img src="./resources/unit_topology_v_1_0_0_ue0117_devlab_dvi_to_fpc_adapter.png" width="500px"><br/> Topology</a>
<br/>
<br/>
<br/>

| Ref. |                   Description                   |
|:----:|:-----------------------------------------------:|
|  J1  |                  DVI Connector                  |
|  J2  |           FPC 22-pin 0.5mm Connector            |
|  J3  |       I2C QWIIC Connector (JST 4-Pin 1mm)       |
|  J4  |       I2C QWIIC Connector (JST 4-Pin 1mm)       |
|  U1  |              AP3602A 5V Regulator               |
| JP1  |       2.54 mm Pin Header for TMDS Signals       |
| JP2  | 2.54 mm Pin Header for Power Supply and Hotplug |
| JP3  |   2.54 mm Pin Header for I2C and CEC Signals    |
| SB1  |             Jumper pad for Hotplug              |
| SB2  |               Jumper pad for CEC                |


</div>

## Dimensions

<div align="center">
<a href="./resources/unit_dimension_v_1_0_0_ue0117_devlab_dvi_to_fpc_adapter.png"><img src="./resources/unit_dimension_v_1_0_0_ue0117_devlab_dvi_to_fpc_adapter.png" width="500px"><br/> Dimensions</a>
</div>

