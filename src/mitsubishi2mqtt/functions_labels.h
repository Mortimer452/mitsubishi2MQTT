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

// Human-readable names for the indoor unit installer functions (codes 101-128)
// that the HeatPump library reads with getFunctions(). Names and option text
// come from the generic table in Mitsubishi document 69-2426-01 (MHK1 controller
// kit installation manual, pages 6-7). What each function actually does is
// model specific, so treat these as typical meanings and always show the raw code.
// Codes not listed here are reported as "Function NNN" with the raw value only.

const char fn_name_101[] PROGMEM = "Auto restart after power outage";
const char fn_name_103[] PROGMEM = "Ventilation air (LOSSNAY)";
const char fn_name_104[] PROGMEM = "Power voltage";
const char fn_name_105[] PROGMEM = "Auto energy-savings operation";
const char fn_name_107[] PROGMEM = "Change filter duration";
const char fn_name_108[] PROGMEM = "Auto fan speed setting";
const char fn_name_109[] PROGMEM = "Number of air outlets (PLA only)";
const char fn_name_110[] PROGMEM = "High performance filter installed";
const char fn_name_111[] PROGMEM = "Airflow direction settings";
const char fn_name_115[] PROGMEM = "Indoor coil frost prevention temperature";
const char fn_name_117[] PROGMEM = "Defrost control";
const char fn_name_123[] PROGMEM = "Airflow oscillate mode";
const char fn_name_124[] PROGMEM = "Heating mode temperature offset";
const char fn_name_125[] PROGMEM = "Thermal off fan operation (heat mode)";
const char fn_name_127[] PROGMEM = "Thermal off fan operation (cool mode)";
const char fn_name_128[] PROGMEM = "Display system error";

const char fn_opt_101_1[] PROGMEM = "OFF";
const char fn_opt_101_2[] PROGMEM = "ON";
const char fn_opt_103_1[] PROGMEM = "Not supported";
const char fn_opt_103_2[] PROGMEM = "IDU does not intake outdoor air through LOSSNAY";
const char fn_opt_103_3[] PROGMEM = "IDU intakes outdoor air through LOSSNAY";
const char fn_opt_104_1[] PROGMEM = "230V";
const char fn_opt_104_2[] PROGMEM = "208V";
const char fn_opt_105_1[] PROGMEM = "ON";
const char fn_opt_105_2[] PROGMEM = "OFF";
const char fn_opt_107_1[] PROGMEM = "100 hours";
const char fn_opt_107_2[] PROGMEM = "2500 hours";
const char fn_opt_107_3[] PROGMEM = "OFF";
const char fn_opt_108_1[] PROGMEM = "Quiet";
const char fn_opt_108_2[] PROGMEM = "Standard";
const char fn_opt_108_3[] PROGMEM = "High ceiling";
const char fn_opt_109_1[] PROGMEM = "4 directions";
const char fn_opt_109_2[] PROGMEM = "3 directions";
const char fn_opt_109_3[] PROGMEM = "2 directions";
const char fn_opt_110_1[] PROGMEM = "NO";
const char fn_opt_110_2[] PROGMEM = "YES";
const char fn_opt_111_1[] PROGMEM = "No vanes (or vane #3 for PLA)";
const char fn_opt_111_2[] PROGMEM = "Vane #1 setting";
const char fn_opt_111_3[] PROGMEM = "Vane #2 setting";
const char fn_opt_115_1[] PROGMEM = "36 F (2 C)";
const char fn_opt_115_2[] PROGMEM = "37 F (3 C)";
const char fn_opt_117_1[] PROGMEM = "Standard";
const char fn_opt_117_2[] PROGMEM = "High humidity";
const char fn_opt_123_1[] PROGMEM = "Not available";
const char fn_opt_123_2[] PROGMEM = "Available";
const char fn_opt_124_1[] PROGMEM = "ON";
const char fn_opt_124_2[] PROGMEM = "OFF";
const char fn_opt_125_1[] PROGMEM = "Extra low";
const char fn_opt_125_2[] PROGMEM = "Stop";
const char fn_opt_125_3[] PROGMEM = "Selectable fan speed";
const char fn_opt_127_1[] PROGMEM = "Selectable fan speed";
const char fn_opt_127_2[] PROGMEM = "Stop";
const char fn_opt_128_1[] PROGMEM = "ON";
const char fn_opt_128_2[] PROGMEM = "OFF";

// Shared fallbacks
const char fn_opt_not_supported[] PROGMEM = "Not supported";
const char fn_opt_not_reported[] PROGMEM = "not available on this model";
const char fn_opt_unknown[] PROGMEM = "";

// Returns the manual's name for a function code, or nullptr when the manual
// does not list it.
const char* functionName(int code) {
  switch (code) {
    case 101: return fn_name_101;
    case 103: return fn_name_103;
    case 104: return fn_name_104;
    case 105: return fn_name_105;
    case 107: return fn_name_107;
    case 108: return fn_name_108;
    case 109: return fn_name_109;
    case 110: return fn_name_110;
    case 111: return fn_name_111;
    case 115: return fn_name_115;
    case 117: return fn_name_117;
    case 123: return fn_name_123;
    case 124: return fn_name_124;
    case 125: return fn_name_125;
    case 127: return fn_name_127;
    case 128: return fn_name_128;
    default:  return nullptr;
  }
}

// Returns the manual's text for option `value` (1-3) of a function code.
// Listed functions whose option 3 the manual marks "Not Supported" fall
// through to the shared string. Unlisted codes return an empty string.
// A value of 0 is outside the manual's range. Units report 0 for functions they
// do not have (an SLZ cassette reports 0 for the PLA-only code 109, for example),
// and an MHK1 hides those codes from its installer setup. Some models, such as
// the MSZ-FH wall units, report 0 for every code.
const char* functionOption(int code, int value) {
  if (value < 1 || value > 3) return fn_opt_not_reported;
  switch (code) {
    case 101: return value == 1 ? fn_opt_101_1 : value == 2 ? fn_opt_101_2 : fn_opt_not_supported;
    case 103: return value == 1 ? fn_opt_103_1 : value == 2 ? fn_opt_103_2 : fn_opt_103_3;
    case 104: return value == 1 ? fn_opt_104_1 : value == 2 ? fn_opt_104_2 : fn_opt_not_supported;
    case 105: return value == 1 ? fn_opt_105_1 : value == 2 ? fn_opt_105_2 : fn_opt_not_supported;
    case 107: return value == 1 ? fn_opt_107_1 : value == 2 ? fn_opt_107_2 : fn_opt_107_3;
    case 108: return value == 1 ? fn_opt_108_1 : value == 2 ? fn_opt_108_2 : fn_opt_108_3;
    case 109: return value == 1 ? fn_opt_109_1 : value == 2 ? fn_opt_109_2 : fn_opt_109_3;
    case 110: return value == 1 ? fn_opt_110_1 : value == 2 ? fn_opt_110_2 : fn_opt_not_supported;
    case 111: return value == 1 ? fn_opt_111_1 : value == 2 ? fn_opt_111_2 : fn_opt_111_3;
    case 115: return value == 1 ? fn_opt_115_1 : value == 2 ? fn_opt_115_2 : fn_opt_not_supported;
    case 117: return value == 1 ? fn_opt_117_1 : value == 2 ? fn_opt_117_2 : fn_opt_not_supported;
    case 123: return value == 1 ? fn_opt_123_1 : value == 2 ? fn_opt_123_2 : fn_opt_not_supported;
    case 124: return value == 1 ? fn_opt_124_1 : value == 2 ? fn_opt_124_2 : fn_opt_not_supported;
    case 125: return value == 1 ? fn_opt_125_1 : value == 2 ? fn_opt_125_2 : fn_opt_125_3;
    case 127: return value == 1 ? fn_opt_127_1 : value == 2 ? fn_opt_127_2 : fn_opt_not_supported;
    case 128: return value == 1 ? fn_opt_128_1 : value == 2 ? fn_opt_128_2 : fn_opt_not_supported;
    default:  return fn_opt_unknown;
  }
}
