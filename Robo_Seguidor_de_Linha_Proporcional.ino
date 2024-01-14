////////////////////////////////////
//Tecnologia em Automação indutrial
//Arthur, Geovanna e Heloisa
////////////////////////////////////
#define IN1 2  //roda direita
#define IN2 3  //roda direita
#define IN3 6  //roda esquerda
#define IN4 7  //roda esquerda

const int S_esquerda = A0;
const int S_direita = A1;
const int VelocidadeA = 10;
const int VelocidadeB = 11;

int erroX, erroY;
int SetPoint;
int constante = 200;
int velocidadeEsq;
int velocidadeDir;

int x, y, z;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S_esquerda, INPUT);
  pinMode(S_direita, INPUT);
  pinMode(VelocidadeB, OUTPUT);
  pinMode(VelocidadeA, OUTPUT);
  Serial.begin(9600);

  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);  //avança ambos os motores
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void loop() {
  x = analogRead(S_esquerda);
  y = analogRead(S_direita);

  SetPoint = ((x + y) / 2);

  erroX = SetPoint - x;
  erroY = SetPoint - y;

  velocidadeEsq = constante + erroX;
  velocidadeDir = constante + erroY;

  if (velocidadeDir < 0) {
    frente(0, velocidadeEsq);
  } else if (velocidadeEsq < 0) {
    frente(velocidadeDir, 0);
  } else if (velocidadeDir > 255) {
    frente(255, velocidadeEsq);
  } else if (velocidadeEsq > 255) {
    frente(velocidadeDir, 255);
  } else {
    frente(velocidadeDir, velocidadeEsq);
  }
}

void frente(int c, int d) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);  //avança ambos os motores
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);

  analogWrite(VelocidadeA, c);
  analogWrite(VelocidadeB, d);
}
