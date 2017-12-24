#include "assets.h" 

void setup() {
  // put your setup code here, to run once:
  int i ; 
  int nb_led_horizontal = sizeof(LED_HORIZONTAL) ; 
  for (i = 0; i < nb_led_horizontal ; i++) {
    pinMode(LED_HORIZONTAL[i], OUTPUT) ; 
  }

  int nb_led_vertical = sizeof(LED_VERTICAL) ; 
  for (i = 0; i < nb_led_vertical ; i++) {
    pinMode(LED_VERTICAL[i], OUTPUT) ; 
  }

  pinMode(PWM_HORIZONTAL, INPUT) ; 
  pinMode(PWM_VERTICAL, INPUT) ; 

}

void loop() {
  // put your main code here, to run repeatedly:

}
