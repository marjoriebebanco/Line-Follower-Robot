#define in1 D2    
#define in2 D3    
#define in3 D4    
#define in4 D5   
#define EnA D6   
#define EnB D7   

#define IR_LEFT D0 
#define IR_RIGHT D1

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(EnA, OUTPUT);
    pinMode(EnB, OUTPUT);
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_RIGHT, INPUT);

    analogWriteRange(255); 
    analogWriteFreq(1000); 

    analogWrite(EnA, 100); 
    analogWrite(EnB, 100);
    
    stopMotors();
    delay(1000);
}

void loop() {
    int leftSensor = digitalRead(IR_LEFT);
    int rightSensor = digitalRead(IR_RIGHT);

    if (leftSensor == 0 && rightSensor == 0) {
        forward();
    } else if (leftSensor == 0 && rightSensor == 1) {
        turnRight();
    } else if (leftSensor == 1 && rightSensor == 0) {
        turnLeft();
    } else {
        stopMotors();
    }
}

void forward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void turnRight() {
    analogWrite(EnA, 100); 
    analogWrite(EnB, 150); 

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void turnLeft() {
    analogWrite(EnA, 150); 
    analogWrite(EnB, 100); 

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}


void stopMotors() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
