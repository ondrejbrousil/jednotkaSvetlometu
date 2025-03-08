int inObrys = 6;
int inDalkove = 5;
int inLeve = 4;
int inPrave = 3;
int inVystrazne = 2;

int clock = 12;
int latchLeve = 11;
int dataLeve = 13;
int latchPrave = 9;
int dataPrave = 10;

int smerovkyLeve = 0;
int smerovkyPrave = 0;
int smerovkyProdleva = 70;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clock, OUTPUT);
  pinMode(latchLeve, OUTPUT);
  pinMode(dataLeve, OUTPUT);
  pinMode(latchPrave, OUTPUT);
  pinMode(dataPrave, OUTPUT);
}

void smerovkyLeveVoid() {
  for (smerovkyLeve; smerovkyLeve <= 9; smerovkyLeve++) {
    smerovkyLeveZobrazeni();
    delay(smerovkyProdleva);
  }

  if (smerovkyLeve > 9) {
    smerovkyLeve = 0;
  }
}

void smerovkyLeveZobrazeni() {
  switch (smerovkyLeve) {
    case 0:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 0);
      digitalWrite(latchLeve, HIGH);
      break;
    case 1:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 0);
      digitalWrite(latchLeve, HIGH);
      break;
    case 2:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 1);
      digitalWrite(latchLeve, HIGH);
      break;
    case 3:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 3);
      digitalWrite(latchLeve, HIGH);
      break;
    case 4:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 7);
      digitalWrite(latchLeve, HIGH);
      break;
    case 5:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 15);
      digitalWrite(latchLeve, HIGH);
      break;
    case 6:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 31);
      digitalWrite(latchLeve, HIGH);
      break;
    case 7:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 63);
      digitalWrite(latchLeve, HIGH);
      break;
    case 8:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 127);
      digitalWrite(latchLeve, HIGH);
      break;
    case 9:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 255);
      digitalWrite(latchLeve, HIGH);
      break;
  }
}

void smerovkyPraveVoid() {
  for (smerovkyPrave; smerovkyPrave <= 9; smerovkyPrave++) {
    smerovkyPraveZobrazeni();
    delay(smerovkyProdleva);
  }

  if (smerovkyPrave > 9) {
    smerovkyPrave = 0;
  }
}

void smerovkyPraveZobrazeni() {
  switch (smerovkyPrave) {
    case 0:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 0);
      digitalWrite(latchPrave, HIGH);
      break;
    case 1:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 0);
      digitalWrite(latchPrave, HIGH);
      break;
    case 2:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 1);
      digitalWrite(latchPrave, HIGH);
      break;
    case 3:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 3);
      digitalWrite(latchPrave, HIGH);
      break;
    case 4:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 7);
      digitalWrite(latchPrave, HIGH);
      break;
    case 5:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 15);
      digitalWrite(latchPrave, HIGH);
      break;
    case 6:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 31);
      digitalWrite(latchPrave, HIGH);
      break;
    case 7:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 63);
      digitalWrite(latchPrave, HIGH);
      break;
    case 8:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 127);
      digitalWrite(latchPrave, HIGH);
      break;
    case 9:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 255);
      digitalWrite(latchPrave, HIGH);
      break;
  }

}

void loop() {
  smerovkyLeveVoid();
}