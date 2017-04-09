# Set a variable for commands below
set(PROJECT_NAME read)

# Define your project and language
project(${PROJECT_NAME} C CXX)

set(${PROJECT_NAME}_BOARD uno)

# Define the source code
set(${PROJECT_NAME}_SRCS example.cpp)

# Define the port for uploading code to the Arduino
set(${PROJECT_NAME}_PORT /dev/ttyACM0)

link_directories(${ARDUINO_SDK_PATH}/libraries/USB_Host_Shield_2.0-1.3.0)

# Command to generate code arduino firmware (.hex file)
generate_arduino_firmware(${PROJECT_NAME})
