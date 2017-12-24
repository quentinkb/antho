/**
 * @author quentin bernet
 * @version 1.0.241217
 * @todo : test 
 */

#include "assets.h" 

void setup() {
  int i ; 
  int nb_led_horizontal = sizeof(LED_HORIZONTAL)/sizeof(int) ; 

  for (i = 0; i < nb_led_horizontal ; i++) {
    pinMode(LED_HORIZONTAL[i], OUTPUT) ; 
    digitalWrite(LED_HORIZONTAL[i], LOW) ; 
    Serial.println("setting low"); 
  }

  int nb_led_vertical = sizeof(LED_VERTICAL)/sizeof(int) ; 
  for (i = 0; i < nb_led_vertical ; i++) {
    pinMode(LED_VERTICAL[i], OUTPUT) ; 
    digitalWrite(LED_VERTICAL[i], LOW) ; 
  }

  pinMode(PWM_HORIZONTAL, INPUT) ; 
  pinMode(PWM_VERTICAL, INPUT) ; 

}

void loop() {

  double horizontal_value = pulseIn(PWM_HORIZONTAL, HIGH);
  double vertical_value = pulseIn(PWM_VERTICAL, HIGH);

  int nb_rates = sizeof(RATE_HORIZONTAL)/sizeof(int); 
  int nb_led_horizontal = sizeof(LED_HORIZONTAL)/sizeof(int);
  if (nb_rates == nb_led_horizontal) {
    int j ; 
     // horizontal treatment left 
    for(j = 0 ; j < nb_rates -3 ; j++) {
       if (horizontal_value < RATE_HORIZONTAL[j]) {
          digitalWrite(LED_HORIZONTAL[j],HIGH) ; 
       } else {
          digitalWrite(LED_HORIZONTAL[j],LOW) ; 
       }
    }
     // horizontal treatment right 
    for(j = 3 ; j < nb_rates ; j++) {
       if (horizontal_value > RATE_HORIZONTAL[j]) {
          digitalWrite(LED_HORIZONTAL[j],HIGH) ; 
       } else {
          digitalWrite(LED_HORIZONTAL[j],LOW) ; 
       }
    }
  }

  nb_rates = sizeof(RATE_VERTICAL)/sizeof(int); 
  int nb_led_vertical = sizeof(LED_VERTICAL)/sizeof(int);
  if (nb_rates == nb_led_vertical) {
    int j ; 
     // vertical treatment low 
    for(j = 0 ; j < nb_rates -3 ; j++) {
       if (vertical_value < RATE_VERTICAL[j]) {
          digitalWrite(LED_VERTICAL[j],HIGH) ; 
       } else {
          digitalWrite(LED_VERTICAL[j],LOW) ; 
       }
    }
     // vertical treatment high 
    for(j = 3 ; j < nb_rates ; j++) {
       if (vertical_value > RATE_VERTICAL[j]) {
          digitalWrite(LED_VERTICAL[j],HIGH) ; 
       } else {
          digitalWrite(LED_VERTICAL[j],LOW) ; 
       }
    }
  }


}
