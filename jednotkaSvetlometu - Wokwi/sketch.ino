/*

Řídící jednotka svetlometu - firmware
- stále ve vývoji
- funkční animace směrovek, není možné je spustit přepínačemi
- nefunkční přepínače, obrysová a dálková světla

https://github.com/ondrejbrousil/jednotkaSvetlometu$0

*/

//Tlacitka a spinace
int pinObrys = 8;
int pinDalkove = 7;
int pinLeve = 4;
int pinPrave = 3;
int pinVystrazne = 2;

int stavObrys = 0;
int stavDalkove = 0;
int stavLeve = 0;
int stavPrave = 0;
int stavVystrazne = 0;

//Obrys
int obrysDimm = 0;
int obrysDimmKrok = 20;
int obrysDimmKrokProdleva = 100;
int vystupObrys = 5;

//Dalkove
int dalkoveDimm = 0;
int dalkoveDimmKrok = 20;
int dalkoveDimmKrokProdleva = 100;
int vystupDalkove = 6;


//Smerorvky
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
  for (smerovkyLeve; smerovkyLeve <= 8; smerovkyLeve++) {
    smerovkyLeveZobrazeni();
    delay(smerovkyProdleva);
  }

  if (smerovkyLeve > 8) {
    smerovkyLeve = 0;
  }
}

void smerovkyLeveZobrazeni() {
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

void smerovkyPraveVoid() {
  for (smerovkyPrave; smerovkyPrave <= 8; smerovkyPrave++) {
    smerovkyPraveZobrazeni();
    delay(smerovkyProdleva);
  }

  if (smerovkyPrave > 8) {
    smerovkyPrave = 0;
  }
}

void smerovkyPraveZobrazeni() {
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

/* 

P O Z N A M K A : aktualne ve stadiu vyvoje

void obrysVoid() {

  int obrysPricteni = obrysDimm+obrysDimmKrok;
  Serial.print("vysledek: ");
  Serial.println(obrysPricteni);

  for (obrysDimm; obrysDimm <= 255; obrysDimm+obrysDimmKrok) {
    digitalWrite(vystupObrys, obrysDimm);
    delay(obrysDimmKrokProdleva);
    Serial.println(obrysDimm);
  }
}

void cteniVstupu() {
  stavObrys = digitalRead(pinObrys);

  if(stavObrys) {
    
  }
}
*/

void loop() {
  smerovkyPraveVoid();
}