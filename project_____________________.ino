// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
LiquidCrystal_I2C lcd(0x27, 16, 2);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int time = 0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(A0, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  int Distance = sonar.ping_cm();
  if(Distance > 8 && time > 30){
    digitalWrite(A0, 1);
    lcd.setCursor(0, 0);
    lcd.print("Danger!!");
    }
  else if(Distance > 8){ 
    time++;
    Serial.println(time);
    }
  else{
    time = 0;
    digitalWrite(A0, 0);
    lcd.setCursor(0, 0);
    lcd.print("Safe fuu");
    }
    delay(990);
    
}
