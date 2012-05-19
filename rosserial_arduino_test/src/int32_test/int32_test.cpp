/*
 * rosserial::std_msgs::Time Test
 * Publishes the current time.
 */

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif  // Arduino 1.0+

#include "arduino_hardware.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"

#include "std_msgs/Int32.h"

ArduinoHardware hardware;
ros::NodeHandle nh(&hardware);

std_msgs::Int32 test;
ros::Publisher p("my_topic", &test);

int i = 0;

void setup() {
  hardware.init();
  nh.advertise(p);
}

void loop() {
  test.data = i++ % 100;
  p.publish(&test);
  nh.spinOnce();
  delay(10);
}

