#include <LiquidCrystal.h>
#include <millisDelay.h>
millisDelay muteDelay;

#define LDR_PIN 2
volatile unsigned long puseInStart = micros();
volatile unsigned long puseInEnd = micros();
unsigned long pulseDuration;
volatile bool newPulseAvailable = false;
volatile bool startflag = false;

int tones[] = { 261, 277, 294, 311, 330, 349, 370, 392, 415, 440 };
//            mid C  C#   D    D#   E    F    F#   G    G#   A
//const int pinIRd = 7;

const int pinIRa = A0;

int IRvalueA = 0;
int IRvalueD = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 6;
const int buzzerPin = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int LED = 8;

void pulseInterrupt() {
  if (digitalRead(LDR_PIN) == LOW) {
    // start measuring
    puseInStart = micros();
    startflag = true;
  } else if (startflag) {
    // stop measure
    puseInEnd = micros();
    startflag = false;
    newPulseAvailable = true;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(LDR_PIN),
                  pulseInterrupt, CHANGE);
  pinMode(pinIRa, INPUT);
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);

  pinMode(7, INPUT);  // mute btn
  pinMode(LED, OUTPUT);
}

void loop() {

  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  if (newPulseAvailable) {
    newPulseAvailable = false;
    pulseDuration = puseInEnd - puseInStart;
    Serial.println(pulseDuration);

    if (pulseDuration >= 9000 && pulseDuration <= 20000) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door Open");
      tone(buzzerPin, tones[0], 500);
      digitalWrite(LED, HIGH);
      delay(500);
      noTone(buzzerPin);
      digitalWrite(LED, LOW);
      delay(500);

    } else if (pulseDuration >= 50000 && pulseDuration <= 60000) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fume. Fire");
      bool flag = 1;
      bool swtch;

      while (flag) {

        do {
          while (digitalRead(7)) {
            tone(buzzerPin, tones[5], 100);
            digitalWrite(LED, LOW);
            delay(30);
            noTone(buzzerPin);
            digitalWrite(LED, HIGH);
            delay(30);
          }
          delay(30);
          }while (digitalRead(7));
          muteDelay.start(10000);
          if (muteDelay.justFinished()) {
          flag = 1;
          }
          else{
            tone(buzzerPin, tones[5], 100);
            digitalWrite(LED, LOW);
            delay(30);
            noTone(buzzerPin);
            digitalWrite(LED, HIGH);
            delay(30);
          }

        flag = 0;
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(500);
    } else if (pulseDuration >= 19000 && pulseDuration <= 30000) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Object Near");
      tone(buzzerPin, tones[1], 500);
      digitalWrite(LED, HIGH);
      delay(500);
      noTone(buzzerPin);
      digitalWrite(LED, LOW);
      delay(500);
    }
  }

  //Serial.println("No");

  /*Serial.print("Analog Reading=");
  Serial.print(IRvalueA);

  Serial.print("\t Digital Reading=");
  Serial.println(IRvalueD);
 IRvalueA = analogRead(pinIRa);
IRvalueD = digitalRead(pinIRd);

    duration= int((pulseIn(7, HIGH))/10000);
    if (duration == 21 ){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tempreture 17-18");
    }else if(duration == 23){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tempreture 19");
    }else if(duration>12 && duration<15){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Door Open");
        pinMode(buzzerPin, OUTPUT); 
        tone(buzzerPin, 50);
        digitalWrite(LED,HIGH);
        delay(100);
        noTone(buzzerPin);
    }else if(duration == 0){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("No Signal");
    }else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("No Signal");
        digitalWrite(LED,LOW);


    }*/
  /*
  switch(duration){
    case 16 :
    //lcd.clear();
    //lcd.setCursor(0, 0);
    //lcd.print("Door Open");
              break;
    case 21 :
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tempreture 17-18");
    //delay(500);
              break;
    case 23 :
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tempreture 19");
    //delay(500);
              break;
    case 11 :
    lcd.clear();
    //lcd.print("Tempreture 17-18");
    //delay(500);
              break;
    case 14 :
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Open");
              break;
    case 0 :
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Closed");
              break;
    
    default :
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("No Signal");
              break;
  }
*/
  /*Serial.print("\t Duration=");
    Serial.println(duration);*/
}
