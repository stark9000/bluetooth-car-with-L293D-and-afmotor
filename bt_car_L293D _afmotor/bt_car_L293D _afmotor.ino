#include <AFMotor.h>
#include <SoftwareSerial.h>

const byte rxPin = 10;
const byte txPin = 11;

char command = 'S';

int vel = 127;
char det;
char determinant;

SoftwareSerial BTS (rxPin, txPin);


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
  BTS.begin(9600);
}

void loop() {

  det = check();

  while (det == 'F')   // F, move forward
  {
    Serial.println("F");
    FOWARD();
    det = check();
  }

  while (det == 'B')   // B, move back
  {
    Serial.println("B");
    BACKWRD();
    det = check();
  }

  while (det == 'L')   // L, turn left
  {
    Serial.println("L");
    LEFT();
    det = check();
  }

  while (det == 'R')   // R, turn right
  {
    Serial.println("R");
    RIGHT();
    det = check();
  }

  while (det == 'S')   // S, stop
  {
    Serial.println("S");
    STOP();
    det = check();
  }

  //---------------------Toggle switch code------------------//
  while (det == 'W') {
    det = check();
  }
  while (det == 'w') {
    det = check();
  }

  while (det == 'U') {
    det = check();
  }
  while (det == 'u') {
    det = check();
  }

  while (det == 'V') {
    det = check();
  }
  while (det == 'v') {
    det = check();
  }

}


int check()
{ if (BTS.available() > 0) {
    command = BTS.read();
    //Serial.print(command);
    if (command == 'F') {
      determinant = 'F';
    }
    else if (command == 'B') {
      determinant = 'B';
    } else if (command == 'L') {
      determinant = 'L';
    }
    else if (command == 'R') {
      determinant = 'R';
    } else if (command == 'I') {
      determinant = 'I';
    }
    else if (command == 'J') {
      determinant = 'J';
    } else if (command == 'G') {
      determinant = 'G';
    }
    else if (command == 'H') {
      determinant = 'H';
    } else if (command == 'S') {
      determinant = 'S';
    }
    else if (command == '0') {
      vel = 0;
    } else if (command == '1') {
      vel =25 ;
    }
    else if (command == '2') {
      vel = 55;
    } else if (command == '3') {
      vel = 65;
    }
    else if (command == '4') {
      vel = 75;
    } else if (command == '5') {
      vel = 85;
    }
    else if (command == '6') {
      vel = 100;
    } else if (command == '7') {
      vel = 125;
    }
    else if (command == '8') {
      vel = 150;
    } else if (command == '9') {
      vel = 200;
    }
    else if (command == 'q') {
      vel = 255;
    }
    else if (command == 'U') {
      determinant = 'U';
    } else if (command == 'u') {
      determinant = 'u';
    }
    else if (command == 'W') {
      determinant = 'W';
    } else if (command == 'w') {
      determinant = 'w';
    }

  } return determinant;
}


void FOWARD() {
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
  motor3.setSpeed(vel);
  motor4.setSpeed(vel);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void BACKWRD() {
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
  motor3.setSpeed(vel);
  motor4.setSpeed(vel);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void RIGHT() {
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
  motor3.setSpeed(vel);
  motor4.setSpeed(vel);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void LEFT() {
  motor1.setSpeed(vel);
  motor2.setSpeed(vel);
  motor3.setSpeed(vel);
  motor4.setSpeed(vel);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void STOP()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
