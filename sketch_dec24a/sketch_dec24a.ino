#include "assets.h" 

void setup() {
  // put your setup code here, to run once:
  int i ; 
  int nb_led_horizontal = sizeof(LED_HORIZONTAL)/sizeof(int) ; 
  for (i = 0; i < nb_led_horizontal ; i++) {
    pinMode(LED_HORIZONTAL[i], OUTPUT) ; 
  }

  int nb_led_vertical = sizeof(LED_VERTICAL)/sizeof(int) ; 
  for (i = 0; i < nb_led_vertical ; i++) {
    pinMode(LED_VERTICAL[i], OUTPUT) ; 
  }

  pinMode(PWM_HORIZONTAL, INPUT) ; 
  pinMode(PWM_VERTICAL, INPUT) ; 

}

void loop() {
  // put your main code here, to run repeatedly:
  int horizontal_value = analogRead(PWM_HORIZONTAL) ; 
  int vertical_value = analogRead(PWM_VERTICAL); 

  // horizontal treatment left 
  int nb_rates = sizeof(RATE_HORIZONTAL)/sizeof(int); 
  int nb_led_horizontal = sizeof(LED_HORIZONTAL)/sizeof(int);
  if (nb_rates == nb_led_horizontal) {
    int j ; 
    for(j = 0 ; j < nb_rates -3 ; j++) {
       if (horizontal_value < RATE_HORIZONTAL[j]) {
          digitalWrite(LED_HORIZONTAL[j],HIGH) ; 
       } else {
          digitalWrite(LED_HORIZONTAL[j],LOW) ; 
       }
    }
  }

}
