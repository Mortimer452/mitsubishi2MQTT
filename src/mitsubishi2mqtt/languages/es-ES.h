/*
  mitsubishi2mqtt - Mitsubishi Heat Pump to MQTT control for Home Assistant.
  Copyright (c) 2022 gysmo38, dzungpv, shampeon, endeavour, jascdk, chrdavis, alekslyse.  All right reserved.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

//Main Menu
const char txt_control[] PROGMEM = "Control";
const char txt_setup[] PROGMEM = "Configuración";
const char txt_status[] PROGMEM = "Estado";
const char txt_firmware_upgrade[] PROGMEM = "Actualizacion de firmware";
const char txt_reboot[] PROGMEM = "Reiniciar";

//Setup Menu
const char txt_MQTT[] PROGMEM = "MQTT";
const char txt_WIFI[] PROGMEM = "WIFI";
const char txt_unit[] PROGMEM = "Aparato";
const char txt_others[] PROGMEM = "Otros";
const char txt_reset[] PROGMEM = "Restablecer controlador";
const char txt_reset_confirm[] PROGMEM = "Confirmar restablecimiento de controlador?";

//Buttons
const char txt_back[] PROGMEM = "Volver";
const char txt_save[] PROGMEM = "Guardar y reiniciar";
const char txt_logout[] PROGMEM = "Salir";
const char txt_upgrade[] PROGMEM = "Comenzar actualización";
const char txt_login[] PROGMEM = "LOGIN";

//Form choices
const char txt_f_on[] PROGMEM = "ON";
const char txt_f_off[] PROGMEM = "OFF";
const char txt_f_auto[] PROGMEM = "AUTO";
const char txt_f_heat[] PROGMEM = "HEAT";
const char txt_f_dry[] PROGMEM = "DRY";
const char txt_f_cool[] PROGMEM = "COOL";
const char txt_f_fan[] PROGMEM = "FAN";
const char txt_f_quiet[] PROGMEM = "QUIET";
const char txt_f_speed[] PROGMEM = "SPEED";
const char txt_f_swing[] PROGMEM = "SWING";
const char txt_f_pos[] PROGMEM = "POSITION";
const char txt_f_celsius[] PROGMEM = "Celsius";
const char txt_f_fh[] PROGMEM = "Fahrenheit";
const char txt_f_allmodes[] PROGMEM = "Todos los modos";
const char txt_f_noheat[] PROGMEM = "Todos los modos excepto calor";


//Page Reboot, save & Resseting
const char txt_m_reboot[] PROGMEM = "Reiniciando... Refrescando en";
const char txt_m_reset[] PROGMEM = "Restableciendo... Sonectando a SSID";
const char txt_m_save[] PROGMEM = "Guardando configuración and reiniciando... Refrecando en";

//Page MQTT
const char txt_mqtt_title[] PROGMEM = "Parametros MQTT";
const char txt_mqtt_fn[] PROGMEM = "Nombre amigable";
const char txt_mqtt_host[] PROGMEM = "Servidor";
const char txt_mqtt_port[] PROGMEM = "Puerto (1883 por defecto)";
const char txt_mqtt_user[] PROGMEM = "Usuario";
const char txt_mqtt_password[] PROGMEM = "Contraseña";
const char txt_mqtt_topic[] PROGMEM = "Topic";

//Page Others
const char txt_others_title[] PROGMEM = "Otros parámetros";
const char txt_others_haauto[] PROGMEM = "HA Autodiscovery";
const char txt_others_hatopic[] PROGMEM = "HA Autodiscovery topic";
const char txt_others_debug_packets[] PROGMEM = "MQTT topic debug packets";
const char txt_others_debug_log[] PROGMEM = "MQTT topic debug logs";

//Page Status
const char txt_status_title[] PROGMEM = "Estado";
const char txt_status_hvac[] PROGMEM = "Estado HVAC";
const char txt_retries_hvac[] PROGMEM = "HVAC Connection Retries";
const char txt_status_mqtt[] PROGMEM = "Estado MQTT";
const char txt_status_wifi[] PROGMEM = "WIFI RSSI";
const char txt_status_connect[] PROGMEM = "CONNECTADO";
const char txt_status_disconnect[] PROGMEM = "DESCONECTADO";

//Page WIFI
const char txt_wifi_title[] PROGMEM = "Parametros WIFI";
const char txt_wifi_hostname[] PROGMEM = "Hostname";
const char txt_wifi_SSID[] PROGMEM = "SSID";
const char txt_wifi_psk[] PROGMEM = "PSK";
const char txt_wifi_otap[] PROGMEM = "Contraseña OTA";

//Page Control
const char txt_ctrl_title[] PROGMEM = "Control del aparato";
const char txt_ctrl_temp[] PROGMEM = "Temperatura";
const char txt_ctrl_power[] PROGMEM = "Power";
const char txt_ctrl_mode[] PROGMEM = "Modo";
const char txt_ctrl_fan[] PROGMEM = "Ventilador";
const char txt_ctrl_vane[] PROGMEM = "Aleta vertical";
const char txt_ctrl_wvane[] PROGMEM = "Aleta horizontal";
const char txt_ctrl_ctemp[] PROGMEM = "Temperatura actual";

//Page Unit
const char txt_unit_title[] PROGMEM = "Configuracion del aparato";
const char txt_unit_temp[] PROGMEM = "Temperatura del aparato";
const char txt_unit_maxtemp[] PROGMEM = "Temperatura máxima";
const char txt_unit_mintemp[] PROGMEM = "Temperatura mínima";
const char txt_unit_steptemp[] PROGMEM = "Variación de temperatura";
const char txt_unit_modes[] PROGMEM = "Modos soportados";
const char txt_unit_password[] PROGMEM = "Contraseña interfaz";

//Page Login
const char txt_login_title[] PROGMEM = "Autentificación";
const char txt_login_password[] PROGMEM = "Contraseña";
const char txt_login_sucess[] PROGMEM = "Autentificación correcta, en pocos segundos serás redirigido.";
const char txt_login_fail[] PROGMEM = "¡Usuario contraseña invalidos! Intentalo de nuevo.";

//Page Upgrade
const char txt_upgrade_title[] PROGMEM = "Actualización";
const char txt_upgrade_info[] PROGMEM = "Actualizar Firmware OTA mediante subida de fichero bin";
const char txt_upgrade_start[] PROGMEM = "Actualización iniciada";
const char txt_upgrade_build[] PROGMEM = "Current firmware";

//Page Upload
const char txt_upload_nofile[] PROGMEM = "Ningun fichero bin selecionado";
const char txt_upload_filetoolarge[] PROGMEM = "El fichero es mayor que el espacio disponible";
const char txt_upload_fileheader[] PROGMEM = "La cabecera del fichero no comienza con 0xE9";
const char txt_upload_flashsize[] PROGMEM = "El fichero es mayor que el espacio disponible en memoria flash";
const char txt_upload_buffer[] PROGMEM = "El bufer de subida de fichero es erroneo";
const char txt_upload_failed[] PROGMEM = "Subida fallida. Habilita opcion 3 de depuración para mas información";
const char txt_upload_aborted[] PROGMEM = "Subida abortada";
const char txt_upload_code[] PROGMEM = "Código de error de subida";
const char txt_upload_error[] PROGMEM = "Código de error de subida (mirar en Updater.cpp) ";
const char txt_upload_sucess[] PROGMEM = "Satisfactorio";
const char txt_upload_refresh[] PROGMEM = "Refescando en ";


//Page Init
const char txt_init_title[] PROGMEM = "Configuración inicial";
const char txt_init_reboot_mes[] PROGMEM = "Reiniciando y conectando a su red WiFi! Debería ver el equipo en su punto de acceso.";
const char txt_init_reboot[] PROGMEM = "Reiniciando...";

//Page Functions
const char txt_functions[] PROGMEM = "Functions";
const char txt_functions_title[] PROGMEM = "Installer functions (read only)";
const char txt_fn_code[] PROGMEM = "Code";
const char txt_fn_name[] PROGMEM = "Function";
const char txt_fn_value[] PROGMEM = "Value";
const char txt_fn_raw[] PROGMEM = "Raw data";
const char txt_fn_not_connected[] PROGMEM = "HVAC unit is not connected";
const char txt_fn_read_failed[] PROGMEM = "Reading functions from the HVAC unit failed";
const char txt_fn_retry[] PROGMEM = "Retry";
const char txt_fn_no_values[] PROGMEM = "This unit reports no installer functions over CN105. On models that do, unavailable functions show as 0.";

//Room temperature sensor
const char txt_unit_sensor[] PROGMEM = "Room temperature sensor";
const char txt_f_remote[] PROGMEM = "Remote sensor via MQTT";
const char txt_f_internal[] PROGMEM = "Internal sensor";
const char txt_status_sensor[] PROGMEM = "Room temperature source";
const char txt_status_lastfeed[] PROGMEM = "last update";

//Page Functions (write)
const char txt_fn_apply[] PROGMEM = "Apply changes";
const char txt_fn_confirm[] PROGMEM = "Apply the changed functions? The unit is stopped for a few seconds and then restarted.";
const char txt_fn_no_changes[] PROGMEM = "No changes to apply";
const char txt_fn_result[] PROGMEM = "Result";
const char txt_fn_written[] PROGMEM = "Written";
const char txt_fn_readback[] PROGMEM = "Read back";
const char txt_fn_ok[] PROGMEM = "OK";
const char txt_fn_mismatch[] PROGMEM = "MISMATCH";
const char txt_fn_write_rejected[] PROGMEM = "The write was rejected because the function data was incomplete. Nothing was sent.";
const char txt_fn_power_note[] PROGMEM = "The unit was stopped for the write and restarted.";
const char txt_fn_power_failed[] PROGMEM = "The unit did not acknowledge the power change.";
const char txt_fn_reload[] PROGMEM = "Back to functions";
const char txt_fn_readonly[] PROGMEM = "unknown function, read only";
