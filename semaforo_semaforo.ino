
int pinVermelho = 10;
int pinVerde = 8;
int pinAzul = 9;
int pinBotao = 7;
int fasesemaforo = 1;
int estadobotao;
int pinPedestreVermelho = 3;
int pinPedestreVerde = 2;
int estadoAnteriorBotao;
int tempoPisca;
int estadoPisca;

void setup() {

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinBotao, INPUT);
  pinMode(pinPedestreVermelho, OUTPUT);
  pinMode(pinPedestreVerde, OUTPUT);
  tempoPisca = 0;
  estadoPisca = HIGH;

  estadoAnteriorBotao =  digitalRead(pinBotao);
 
}

void loop() {

  estadobotao = digitalRead(pinBotao);

  if ((estadobotao == HIGH) && (estadoAnteriorBotao == LOW)) {
    if (fasesemaforo < 4) {
      fasesemaforo = fasesemaforo + 1;
    }
    else {
      fasesemaforo = 1;
    }
  }

  estadoAnteriorBotao = estadobotao;

  if (fasesemaforo == 1) {
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinVermelho, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
    digitalWrite(pinPedestreVerde, LOW);
  }
  
  if (fasesemaforo == 2) {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, HIGH);
    digitalWrite(pinVermelho, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);
    digitalWrite(pinPedestreVerde, LOW);
  }
  
  if (fasesemaforo == 3) {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinVermelho, HIGH);
    digitalWrite(pinPedestreVermelho, LOW);
    digitalWrite(pinPedestreVerde, HIGH);
  }
  
  if (fasesemaforo == 4) {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinVermelho, HIGH);

    tempoPisca = tempoPisca + 1;
    if (tempoPisca == 400){
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    } 
    digitalWrite(pinPedestreVermelho,estadoPisca);
    digitalWrite(pinPedestreVerde, LOW);
  }
  delay(1);
}
