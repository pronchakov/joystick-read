#include "Arduino.h"
#include "hid.h"
#include "hiduniversal.h"
#include "usbhub.h"

#include "hidjoystickrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);

JoystickEvents JoyEvents;
JoystickReportParser Joy(&JoyEvents);

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Serial.println("AAAAAAAAAAAAAAAAAA");

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay(200);

    if (!Hid.SetReportParser(0, &Joy))
        ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
}

void loop() {
    Usb.Task();
}
