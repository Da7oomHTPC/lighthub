// Configuration of drivers enabled
#ifndef PIO_SRC_REV
#define PIO_SRC_REV v0.999
#endif

#define TXEnablePin 13

#ifndef AVR_DMXOUT_PIN
#define AVR_DMXOUT_PIN 3
#endif

#define T_ATTEMPTS 200
#define IET_TEMP     0
#define IET_ATTEMPTS 1

#define THERMO_GIST_CELSIUS 2
#define THERMO_OVERHEAT_CELSIUS 38
#define FM_OVERHEAT_CELSIUS 40.


#define OFFSET_MAC 0
#define OFFSET_IP OFFSET_MAC+6
#define OFFSET_DNS OFFSET_IP+4
#define OFFSET_GW OFFSET_DNS+4
#define OFFSET_MASK OFFSET_GW+4
#define OFFSET_CONFIGSERVER OFFSET_MASK+4
#define OFFSET_MQTT_PWD OFFSET_CONFIGSERVER+32
#define EEPROM_offset OFFSET_MQTT_PWD+16

#define INTERVAL_CHECK_INPUT  50
#define INTERVAL_CHECK_MODBUS 2000
#define INTERVAL_POLLING      100
#define THERMOSTAT_CHECK_PERIOD 5000

#ifndef MODBUS_SERIAL_BAUD
#define MODBUS_SERIAL_BAUD 9600
#endif

#define dimPar SERIAL_8E1
#define fmPar  SERIAL_8N1

#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

#ifndef CUSTOM_FIRMWARE_MAC
#define DEFAULT_FIRMWARE_MAC {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xFF}
#endif

#ifndef MY_CONFIG_SERVER
#define CONFIG_SERVER "lazyhome.ru"
#else
#define CONFIG_SERVER QUOTE(MY_CONFIG_SERVER)
#endif

#ifndef OUTTOPIC
#define OUTTOPIC "/myhome/s_out/"
#endif

#ifndef INTOPIC
#define INTOPIC  "/myhome/in/"
#endif

#define MQTT_SUBJECT_LENGTH 20
#define MQTT_TOPIC_LENGTH 20

#ifndef DMX_DISABLE
#define _dmxin
#define _dmxout
#endif

#ifndef OWIRE_DISABLE
#define _owire
#endif

#ifndef MODBUS_DISABLE
#define _modbus
#endif

#ifdef ARTNET_ENABLE
#define _artnet
#endif

#if defined(ESP8266)
#define __ESP__
#endif

#if defined(__AVR__)
//All options available
#ifdef CONTROLLINO
#define modbusSerial Serial3
#else
#define modbusSerial Serial2
#endif
#define dmxin DMXSerial
#define dmxout DmxSimple
#endif

#if defined(__SAM3X8E__)
#define modbusSerial Serial2
#define dmxout DmxDue1
#define dmxin  DmxDue1
#endif

#if defined(__ESP__)
#undef _dmxin
#undef _modbus
#define _espdmx
#define modbusSerial Serial1
#endif

#ifndef _dmxout
#undef _artnet
#endif
