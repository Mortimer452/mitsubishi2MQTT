Import("env")

# Name the firmware binary after the environment (binary_name in platformio.ini)
# and pass the name to the sketch so the upgrade page can show it.
binary_name = env.GetProjectOption("binary_name", "mitsubishi2MQTT")
env.Replace(PROGNAME=binary_name)
env.Append(CPPDEFINES=[("PIO_BINARY", binary_name)])
