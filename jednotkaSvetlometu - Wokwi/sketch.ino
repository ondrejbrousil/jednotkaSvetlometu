/*

  Řídící jednotka svetlometu - firmware
  - stále ve vývoji
  - funkční animace směrovek, není možné je spustit přepínačemi
  - nefunkční přepínače, obrysová a dálková světla

  https://github.com/ondrejbrousil/jednotkaSvetlometu$0

*/

int promMillis = 0;

//Tlacitka a spinace - fyzicke piny na desce
int pinObrys = 8;
int pinDalkove = 7;
int pinLeve = 4;
int pinPrave = 3;
int pinVystrazne = 2;

//Cteni pinu promitnuti na promennou
bool stavObrys = 0;
bool stavDalkove = 0;
bool stavLeve = 0;
bool stavPrave = 0;
bool stavVystrazne = 0;

//Obrys
int obrysDimm = 0; //0-255 stmivani LED
int obrysDimmProdleva = 100; //prodleva zvyseni/snizeni jasu
int vystupObrys = 5; //fyzicky vystupni pin

//Dalkove
int dalkoveDimm = 0; //0-255 stmivani LED
int dalkoveDimmProdleva = 100; //prodleva zvyseni/snizeni jasu
int vystupDalkove = 6; //fyzicky vystupni pin


//Smerorvky - zapojeni registru
int clock = 12;
int latchLeve = 11;
int dataLeve = 13;
int latchPrave = 9;
int dataPrave = 10;

int predchoziSmerovkyLeve = 0;
int predchoziSmerovkyPrave = 0;
int smerovkyLeve = 0; //cislo aktualniho snimku animace
int smerovkyPrave = 0; //cislo aktualniho snimku animace
int smerovkyProdleva = 70; //prodleva zvyseni cisla snimku animace

void setup() {
  Serial.begin(9600);

  pinMode(clock, OUTPUT);
  pinMode(latchLeve, OUTPUT);
  pinMode(dataLeve, OUTPUT);
  pinMode(latchPrave, OUTPUT);
  pinMode(dataPrave, OUTPUT);

  pinMode(pinObrys, INPUT);
  pinMode(pinDalkove, INPUT);
  pinMode(pinLeve, INPUT);
  pinMode(pinPrave, INPUT);
  pinMode(pinVystrazne, INPUT);
}

void smerovkyLeveVoid() { //Pocitadlo snimku animace
  for (smerovkyLeve; smerovkyLeve <= 8; smerovkyLeve++) {
    smerovkyLeveZobrazeni();
    delay(smerovkyProdleva);
  }

  if (smerovkyLeve > 8) {
    smerovkyLeve = 0;
  }
}

void smerovkyLeveZobrazeni() { //Zobrazeni aktualniho snimku dle pocitadla
  switch (smerovkyLeve) {
    case 0:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 1);
      digitalWrite(latchLeve, HIGH);
      break;
    case 1:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 1);
      digitalWrite(latchLeve, HIGH);
      break;
    case 2:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 3);
      digitalWrite(latchLeve, HIGH);
      break;
    case 3:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 7);
      digitalWrite(latchLeve, HIGH);
      break;
    case 4:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 15);
      digitalWrite(latchLeve, HIGH);
      break;
    case 5:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 31);
      digitalWrite(latchLeve, HIGH);
      break;
    case 6:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 63);
      digitalWrite(latchLeve, HIGH);
      break;
    case 7:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 127);
      digitalWrite(latchLeve, HIGH);
      break;
    case 8:
      digitalWrite(latchLeve, LOW);
      shiftOut(dataLeve, clock, MSBFIRST, 255);
      digitalWrite(latchLeve, HIGH);
      break;
  }
}

void smerovkyLeveShiftOut() { //Vymazani shift registru
  digitalWrite(latchLeve, LOW);
  shiftOut(dataLeve, clock, MSBFIRST, 0);
  digitalWrite(latchLeve, HIGH);
}

void smerovkyPraveVoid() { //Pocitadlo snimku animace
  for (smerovkyPrave; smerovkyPrave <= 8; smerovkyPrave++) {
    smerovkyPraveZobrazeni();
    delay(smerovkyProdleva);
  }

  if (smerovkyPrave > 8) {
    smerovkyPrave = 0;
  }
}

void smerovkyPraveZobrazeni() { //Zobrazeni aktualniho snimku dle pocitadla
  switch (smerovkyPrave) {
    case 0:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 1);
      digitalWrite(latchPrave, HIGH);
      break;
    case 1:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 1);
      digitalWrite(latchPrave, HIGH);
      break;
    case 2:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 3);
      digitalWrite(latchPrave, HIGH);
      break;
    case 3:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 7);
      digitalWrite(latchPrave, HIGH);
      break;
    case 4:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 15);
      digitalWrite(latchPrave, HIGH);
      break;
    case 5:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 31);
      digitalWrite(latchPrave, HIGH);
      break;
    case 6:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 63);
      digitalWrite(latchPrave, HIGH);
      break;
    case 7:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 127);
      digitalWrite(latchPrave, HIGH);
      break;
    case 8:
      digitalWrite(latchPrave, LOW);
      shiftOut(dataPrave, clock, MSBFIRST, 255);
      digitalWrite(latchPrave, HIGH);
      break;
  }

}

void smerovkyPraveShiftOut() { //Vymazani shift registru
  digitalWrite(latchPrave, LOW);
  shiftOut(dataPrave, clock, MSBFIRST, 0);
  digitalWrite(latchPrave, HIGH);
}

void smerovkyRizeni() {
  if (stavLeve && promMillis - lastBlinkTimeLeve >= smerovkyProdleva) {
    lastBlinkTimeLeve = promMillis;
    smerovkyLeveZobrazeni();
    smerovkyLeve++;
    if (smerovkyLeve > 8) smerovkyLeve = 0;
  } 
  else if (!stavLeve) {
    smerovkyLeveShiftOut();
  }

  if (stavPrave && promMillis - lastBlinkTimePrave >= smerovkyProdleva) {
    lastBlinkTimePrave = promMillis;
    smerovkyPraveZobrazeni();
    smerovkyPrave++;
    if (smerovkyPrave > 8) smerovkyPrave = 0;
  } 
  else if (!stavPrave) {
    smerovkyPraveShiftOut();
  }
}

void loop() {
  promMillis = millis();


}