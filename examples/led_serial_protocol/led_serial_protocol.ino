// Arduino RBD Serial Manager Library v1.0.0-alpha.2 Example - Control the built-in Arduino led with serial commands: on; off; pwm,255;
// https://github.com/alextaujenis/RBD_SerialManager
// Copyright 2016 Alex Taujenis
// MIT License

#include <RBD_Timer.h>         // https://github.com/alextaujenis/RBD_Timer
#include <RBD_Light.h>         // https://github.com/alextaujenis/RBD_Light
#include <RBD_SerialManager.h> // https://github.com/alextaujenis/RBD_SerialManager

RBD::Light light(13);
RBD::SerialManager usb;

void setup() {
  usb.start();
}

void loop() {
  if(usb.onReceive()) {
    // example serial command: on;
    if(usb.isCmd("on")) {
      light.on();
    }

    // example serial command: off;
    if(usb.isCmd("off")) {
      light.off();
    }

    // example serial command: pwm,123;
    if(usb.isCmd("pwm")) {
      int pwm = usb.getParam().toInt();
      light.setBrightness(pwm);
    }
  }
}