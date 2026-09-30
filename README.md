# mitsubishi2MQTT
Use MQTT and ESP8266/ESP32 module to control Mitsubishi HVAC unit.
It use SwiCago libraries: https://github.com/SwiCago/HeatPump

***
Features:
 - Initial config:  WIFI AP mode and web portal
 - Web interface for configuration, status and control, firmware upgrade
 - Homeassistant autodiscovery and control with MQTT
 - Control with MQTT
 - Multilanguages
 - View and change the indoor unit installer function settings (codes 101-128, Setup -> Functions). Only functions the unit reports are editable; applying a change stops the unit for a few seconds and restarts it, as an MHK1 does. Wall-mount MSZ units report no functions over CN105.

Screenshots:

![Main page](https://github.com/gysmo38/mitsubishi2MQTT/blob/master/images/main_page.png)

![](https://github.com/gysmo38/mitsubishi2MQTT/blob/master/images/control_page.png)

![](https://github.com/gysmo38/mitsubishi2MQTT/blob/master/images/config_page.png)

***
How to use:
 - Step 1: flash the sketch with flash size include SPIFFS option.
 - Step 2: connect to device AP with name HVAC_XXXX (XXXX last 4 character MAC address)
 - Step 3: You should be automatically redirected to the web portal or go to 192.168.1.1
 - Step 4: set Wifi information, save & reboot. Fall back to AP mode if WiFi connection fails (AP password sets to default SSID name from step 2).
 - Step 5: find the device IP with last 4 character MAC address in your router
 - Step 6: (optional): Set MQTT information for use with Home Assistant
 - Step 7: (optional): Set Login password to prevent unwanted access in SETUP->ADVANCE->Login Password

Nightly builds are available for select platforms via GitHub Actions. Go to [the platformio workflow](https://github.com/gysmo38/mitsubishi2MQTT/actions/workflows/platformio.yml), select the latest build, then check the **Artifacts** section. 

***
# Installer function settings
Setup -> Functions reads the indoor unit's installer function settings over CN105 and, on units that expose them, lets you change them. These are the same settings a wired MA controller edits as "function setting mode no." 01-28 and that an MHK1 thermostat shows as 101-128 in installer setup; code NNN is mode NNN-100.

- Which units: ceiling cassettes, ducted and P-series units such as SLZ, SEZ, PLA and PVA report real values. Wall-mount MSZ units report every code as 0 and the page offers nothing to change; their function settings are only reachable from the handheld remote's service mode.
- What 0 means: the unit does not have that function. An MHK1 hides those codes, which is why its installer setup skips numbers.
- Names and option text come from Mitsubishi document 69-2426-01 (MHK1 kit installation manual) and the PAR-31MAA technical manual. What a function does can differ by model, so check your unit's installation manual before changing anything. Codes the unit reports but no manual identifies are shown read-only and cannot be changed from the page.
- Applying a change does what an MHK1 does when it enters installer setup: read fresh, stop the unit if it is running, write, read back, and restart. It takes about ten seconds and the result page shows each change with the value read back from the unit.
- Two settings worth knowing about: 124 "heating set temperature offset" makes the unit heat to about 4 C (7 F) above the set point to compensate for a ceiling-mounted sensor, which becomes overshoot when a remote room sensor is in use; 125 and 127 control what the fan does when the thermostat is satisfied in heat and cool mode.

# Room temperature sensor
Setup -> Unit has a "Room temperature sensor" setting:

- Remote sensor via MQTT (default): temperatures published to topic/remote_temp/set are passed to the unit, and the unit reverts to its own sensor if no value arrives for five minutes. This is the previous behaviour.
- Internal sensor: the unit always uses its own sensor. Messages on the remote temperature topic are ignored, and at every boot the firmware sends the unit a reset so a remote value left behind by a previous controller, such as an MHK1, is cleared.

The state topic includes remoteTempActive (true/false) and the Status page shows which sensor is in use and, when remote, how long since the last value arrived.

***
For nodered fans MQTT topic use cases
- topic/power/set OFF
- topic/mode/set AUTO HEAT COOL DRY FAN_ONLY OFF ON
- topic/temp/set 16-31
- topic/remote_temp/set also called "room_temp", the implementation defined in "HeatPump" seems not work in some models
  - Ignored when the Unit page's "Room temperature sensor" is set to Internal sensor. In that mode the firmware also resets the unit to its own sensor at every boot, which clears a remote value left behind by a previous controller such as an MHK1.
- topic/fan/set 1-4 AUTO QUIET
- topic/vane/set 1-5 SWING AUTO
- topic/wideVane/set << < | > >>
- topic/settings
- topic/state (JSON; includes remoteTempActive true/false showing whether the unit is currently using a remote temperature)
- topic/debug/packets/<direction>/<type> (one subtopic per packet direction and type byte, subscribe to topic/debug/packets/# to see everything)
- topic/debug/packets/set on off
- topic/debug/logs
- topic/debug/logs/set on off
- topic/custom/send as example "fc 42 01 30 10 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 7b " see https://github.com/SwiCago/HeatPump/blob/master/src/HeatPump.h
- topic/system/set reboot 
***
# Grafana dashboard
To use Grafana you need to have Prometheus and Grafana (v10 or newer) installed.
Config for Prometheus:
```  - job_name: Mitsubishi2mqtt
    static_configs:
        - targets:
            - IP-TO-Mitsubishi2mqtt
```
Then add Prometheus as a datasource in Grafana
Grafana -> Connections -> Add new connection -> Prometheus -> ```Prometheus server URL: PROMETHEUS-IP:PORT```

Then you can import the dashboard in Grafana -> Dashboards -> New -> Import and upload the file https://github.com/gysmo38/mitsubishi2MQTT/blob/master/Mitsubishi2mqtt.json

![](https://github.com/gysmo38/mitsubishi2MQTT/blob/master/images/Grafana-screenshot.png)

If you like my work and use it ;)<br>

<a href='https://ko-fi.com/L3L0GSF7X' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://storage.ko-fi.com/cdn/kofi2.png?v=3' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>
