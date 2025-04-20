


// const int trigpin = 11 ;
// const int echopin = 10 ;
// int distance;
// int duration;
// int vcc = 8;


// #include <Servo.h>'


// Servo myServo;


// void setup() {
//   // put your setup code here, to run once:
//   pinMode(trigpin , OUTPUT);
//   pinMode(echopin , INPUT);
//   pinMode(vcc , OUTPUT);

//   digitalWrite(vcc , HIGH);
// }
// void stop() {
//   Serial.begin(9600);
//   myServo.attach(9);       // Attach servo to pin 9
//   myServo.write(0);        // Start at 0 degrees
//   delay(1000);             // Wait a bit

//   myServo.write(0);       // Move to 90 degrees
//   delay(5000);             // Hold for 1 second

//   myServo.write(0);        // Return to 0 degrees90

//   delay(1000);

// }

// void lid() {
//   Serial.begin(9600);
//   myServo.attach(9);       // Attach servo to pin 9
//   myServo.write(0);        // Start at 0 degrees
//   delay(1000);             // Wait a bit

//   myServo.write(90);       // Move to 90 degrees
//   delay(3000);             // Hold for 1 second

//   myServo.write(0);        // Return to 0 degrees90

//   delay(1000); 
// }

// void loop() {
  
  
//   digitalWrite(trigpin , LOW);
//   delayMicroseconds(2);


//   digitalWrite(trigpin , HIGH);
//   delayMicroseconds(10);

//   digitalWrite(trigpin , LOW);


//   duration = pulseIn(echopin , HIGH);
//   distance = (duration * 0.034) / 2 ;
//   Serial.print("The Distance is in cm : "); 
//   Serial.println(distance);

//   if (distance < 15) {
//     lid();
//   }
//   else {
//     stop();
//   }
// }




#include <Servo.h>

const int trigpin = 11;
const int echopin = 10;
const int vcc = 8;

int distance;
int duration;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(vcc, OUTPUT);

  digitalWrite(vcc, HIGH);

  myServo.attach(9);       // Attach servo once
  myServo.write(0);        // Ensure it starts at 0 degrees
}

void stop() {
  myServo.write(0);        // Keep at 0 degrees
  delay(1000);
}

void lid() {
  myServo.write(90);       // Open lid
  delay(3000);             // Stay open for 3 seconds
  myServo.write(0);        // Close lid
  delay(1000);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  // Read echo duration and calculate distance
  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.034) / 2;

  Serial.print("Distance in cm: ");
  Serial.println(distance);

  // Trigger lid movement based on distance
  if (distance < 15) {
    lid();
  } else {
    stop();
  }

  delay(500);  // Small delay to avoid rapid triggering
}

