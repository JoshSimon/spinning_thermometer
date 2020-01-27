#include <dht.h>

dht DHT;

#define DHT11_PIN 7


int Pin1 = 10;
int Pin2 = 11;
int Pin3 = 12;
int Pin4 = 13;


void turn(boolean leftOrRight, int requiredSteps){
 

  int _step = 0;
  for (int i = 0; i <= requiredSteps; i++) {
     

    switch(_step){
      case 0:
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, LOW);
        digitalWrite(Pin4, HIGH);
        break;
      case 1:
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, HIGH);
        digitalWrite(Pin4, HIGH);
        break;
      case 2:
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, HIGH);
        digitalWrite(Pin4, LOW);
      break;
    case 3:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, LOW);
      break;
    case 4: 
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      break;
    case 5:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
    break;
     case 6:
     digitalWrite(Pin1, HIGH);
     digitalWrite(Pin2, LOW);
     digitalWrite(Pin3, LOW);
     digitalWrite(Pin4, LOW);
   break;
   case 7:
     digitalWrite(Pin1, HIGH);
     digitalWrite(Pin2, LOW);
     digitalWrite(Pin3, LOW);
     digitalWrite(Pin4, HIGH);
   break;
   default:
     digitalWrite(Pin1, LOW);
     digitalWrite(Pin2, LOW);
     digitalWrite(Pin3, LOW);
     digitalWrite(Pin4, LOW);
   break;
 }
 if(leftOrRight){
  _step++;
 } else {
  _step--;
 }

  if(_step>7){
   _step=0;
  }
  if(_step<0){
   _step=7;
  }
  delay(10);
 }


}



boolean direction = true; // false right
int temperatureBefore = 29;

void setup()
{
 Serial.begin(9600);
 pinMode(Pin1, OUTPUT);
 pinMode(Pin2, OUTPUT);
 pinMode(Pin3, OUTPUT);
 pinMode(Pin4, OUTPUT);
}
 void loop()
{
  int cdk = DHT.read11(DHT11_PIN);
  int temperature = DHT.temperature;
  if(temperatureBefore - temperature != 0) {
    int diff = temperatureBefore - temperature;
    Serial.println(diff);
    if(diff > 0){
      int steps = diff * 40;
      turn(true,steps);
    } else {
      int steps = diff * (-1) * 40;
      turn(false, steps);
    }
    temperatureBefore = temperature;
  }
  Serial.print(DHT.temperature);
  Serial.println();
  
}
