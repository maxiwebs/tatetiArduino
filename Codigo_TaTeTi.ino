//Pines Leds
#define B11 41
#define G11 39
#define R11 37

#define B12 49
#define G12 51
#define R12 53

#define B13 A7
#define G13 A8
#define R13 A9

#define B21 35
#define G21 33
#define R21 31

#define B22 47
#define G22 45
#define R22 43

#define B23 A10
#define G23 A11
#define R23 A12

#define B31 29
#define G31 27
#define R31 25

#define B32 22
#define G32 24
#define R32 23

#define B33 A6
#define G33 A5
#define R33 A4

#define BLT A13
#define GLT A14
#define RLT A15


////Pines Teclado Matricial
#define C1 2
#define C2 1
#define C3 0
#define F1 14
#define F2 15
#define F3 16
 
#include <Keypad.h>
const byte FILAS = 3;
const byte COLUMNAS = 3;

char teclado_matricial [FILAS][COLUMNAS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
  
};

char tateti[FILAS][COLUMNAS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

byte pines_filas[FILAS] = {F1, F2, F3}; 
byte pines_columnas[COLUMNAS] = {C1, C2, C3}; 
Keypad keypad = Keypad( makeKeymap(teclado_matricial), pines_filas, pines_columnas, FILAS, COLUMNAS );

//Prototipos de funciones

void jugadores();
//Turno del jugador 1, turno del jugador 2.

void impresion();
// Tablero de juego.

void encender_leds();
//Enciende los leds según el numero o la posicion ingresada por el jugador.

void apagar_leds();
//Apaga todos los leds. Pone a las entradas en LOW y a las salidas en HIGH

void ganar();
// Verifica si hay un ganador, y si lo hay, imprime que jugador ganó.

void reinicio();
//Después de una partida, se reinicia todo para jugar nuevamente.

int i;
int turno = 0;
int cont=0;
char tecla;
int jug;
//int pinesLedFila[]={S1,S2,S3};  //Vector que contiene donde están conetados los leds (filas)
//int pinesLedColumna[]={E1,E2,E3}; //Vector que contiene donde están conetados los leds (columnas)

void setup() {
  Serial.begin(9600);
  
  // declaracion de pines como salida
  for (i = 2; i <= 1; i++) {
    pinMode (i, OUTPUT);
  } 
  
}
void loop() {

  testLedsRGB();
}

//Test de los 10 leds RGBs
void testLedsRGB(){

  digitalWrite(B11,HIGH);
  delay(100);
  digitalWrite(B11,LOW);
  digitalWrite(G11,HIGH);
  delay(100); 
  digitalWrite(G11,LOW);
  digitalWrite(R11,HIGH);
  delay(100);
  digitalWrite(R11,LOW);
  delay(300);

  digitalWrite(B12,HIGH);
  delay(100);
  digitalWrite(B12,LOW);
  digitalWrite(G12,HIGH);
  delay(100); 
  digitalWrite(G12,LOW);
  digitalWrite(R12,HIGH);
  delay(100);
  digitalWrite(R12,LOW);
  delay(300);

  digitalWrite(B13,HIGH);
  delay(100);
  digitalWrite(B13,LOW);
  digitalWrite(G13,HIGH);
  delay(100); 
  digitalWrite(G13,LOW);
  digitalWrite(R13,HIGH);
  delay(100);
  digitalWrite(R13,LOW);
  delay(300);

  digitalWrite(B21,HIGH);
  delay(100);
  digitalWrite(B21,LOW);
  digitalWrite(G21,HIGH);
  delay(100); 
  digitalWrite(G21,LOW);
  digitalWrite(R21,HIGH);
  delay(100);
  digitalWrite(R21,LOW);
  delay(300);

  digitalWrite(B22,HIGH);
  delay(100);
  digitalWrite(B22,LOW);
  digitalWrite(G22,HIGH);
  delay(100); 
  digitalWrite(G22,LOW);
  digitalWrite(R22,HIGH);
  delay(100);
  digitalWrite(R22,LOW);
  delay(300);

  digitalWrite(B23,HIGH);
  delay(100);
  digitalWrite(B23,LOW);
  digitalWrite(G23,HIGH);
  delay(100); 
  digitalWrite(G23,LOW);
  digitalWrite(R23,HIGH);
  delay(100);
  digitalWrite(R23,LOW);
  delay(300);

  digitalWrite(B31,HIGH);
  delay(100);
  digitalWrite(B31,LOW);
  digitalWrite(G31,HIGH);
  delay(100); 
  digitalWrite(G31,LOW);
  digitalWrite(R31,HIGH);
  delay(100);
  digitalWrite(R31,LOW);
  delay(300);

  digitalWrite(B32,HIGH);
  delay(100);
  digitalWrite(B32,LOW);
  digitalWrite(G32,HIGH);
  delay(100); 
  digitalWrite(G32,LOW);
  digitalWrite(R32,HIGH);
  delay(100);
  digitalWrite(R32,LOW);
  delay(300);

  digitalWrite(B33,HIGH);
  delay(100);
  digitalWrite(B33,LOW);
  digitalWrite(G33,HIGH);
  delay(100); 
  digitalWrite(G33,LOW);
  digitalWrite(R33,HIGH);
  delay(100);
  digitalWrite(R33,LOW);
  delay(300);

  digitalWrite(BLT,HIGH);
  delay(100);
  digitalWrite(BLT,LOW);
  digitalWrite(GLT,HIGH);
  delay(100); 
  digitalWrite(GLT,LOW);
  digitalWrite(RLT,HIGH);
  delay(100);
  digitalWrite(RLT,LOW);
  delay(300);
  
}

void jugadores() {
  int i, j, aux = 0;
  if (jug==1){
    Serial.println("\nTurno jugador 1");
    Serial.print("Aprete un numero de posicion libre: ");
  }
  else if (jug==2){
    Serial.println("\nTurno jugador 2");
    Serial.print("Aprete un numero de posicion libre: ");
  }
  
  while (aux == 0) {
    encender_leds();
     tecla = keypad.getKey();
    if (tecla != NO_KEY) {
      Serial.println(tecla);
      switch (tecla) {
        case '1':
          if (tateti[0][0] == '1') {
            i = 0;
            j = 0;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '2':
          if (tateti[0][1] == '2') {
            i = 0;
            j = 1;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '3':
          if (tateti[0][2] == '3') {
            i = 0;
            j = 2;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '4':
          if (tateti[1][0] == '4') {
            i = 1;
            j = 0;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '5':
          if (tateti[1][1] == '5') {
            i = 1;
            j = 1;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;

        case '6':
          if (tateti[1][2] == '6') {
            i = 1;
            j = 2;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '7':
          if (tateti[2][0] == '7') {
            i = 2;
            j = 0;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '8':
          if (tateti[2][1] == '8') {
            i = 2;
            j = 1;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
        case '9':
          if (tateti[2][2] == '9') {
            i = 2;
            j = 2;
            aux++;
          }
          else {
            Serial.println("POSICION OCUPADA INGRESE OTRA ");
          }
          break;
      }
    }
  }
  if (jug==1){
    tateti[i][j] = 'X';
  }
  else if (jug==2){
    tateti[i][j] = 'O';
  }
  
}


void impresion() {
  Serial.println("\nJugador 1: X");
  Serial.println("Jugador 2: O\n");
  for (int i = 0; i < FILAS; i++) {    
    for (int j = 0; j < COLUMNAS; j++) {
        Serial.print("  |  ");
        Serial.print(tateti[i][j]) ;  
    }
    Serial.print("  |  ");
    Serial.print("\n");
    Serial.print("\n");
  }
}

void encender_leds() {
      for(int fila=0;fila<3;fila++){
        apagar_leds();
//        digitalWrite(pinesLedFila[fila], LOW);
        for(int columna=0;columna<3;columna++){
          if(tateti[fila][columna]=='O' || tateti[fila][columna]=='X'){
//            digitalWrite(pinesLedColumna[columna], HIGH);
          }
        }
      } 
}


void ganar() {  
  /*
   * combinaciones.
   * en la variable aux guarda el numero del jugador ganador
  */
  cont++;
  int gan=0;
  // inicio caso de estar en la posicion 1
  if (tateti[0][0] == 'X' || tateti[0][0] == 'O') {
    if (tateti[0][0] == tateti[0][1] && tateti[0][0] == tateti[0][2]) {
      if (tateti[0][0] == 'X') {
        gan = 1;
      }
      else {
        gan = 2;
      }
    }
    if (tateti[0][0] == tateti[1][0] && tateti[2][0] == tateti[0][0]) {
      if (tateti[0][0] == 'X') {
        gan = 1;
      }
      else {
        gan = 2;
      }
    }
  }
  //fin caso 1
  
  //inicio caso 5
  
  if (tateti[1][1] == 'X' || tateti[1][1] == 'O') {
    if (tateti[1][1] == tateti[0][0] && tateti[1][1] == tateti[2][2]) {
      if (tateti[1][1] == 'X') {
        gan = 1;
      }
      else {
        gan = 2;
      }
    }
    if (tateti[1][0] == tateti[1][1] && tateti[1][1] == tateti[1][2]) {
      if (tateti[1][1] == 'X') {
        gan = 1;
      }
      else {
        gan = 2;
      }
    }
    if (tateti[1][1] == tateti[2][0] && tateti[1][1] == tateti[0][2]) {
      if (tateti[1][1] == 'X') {
        gan = 1;
      }
      else {
        gan = 2;
      }
    }
    if (tateti[1][1] == tateti[0][1] && tateti[1][1] == tateti[2][1]) {
      if (tateti[1][1] == 'X') {
        gan = 1;
      }
      else {
        gan = 2;
      }
    }
  }
  // Fin caso 5
  
  // Inicio caso 9
  if (tateti[2][2] == 'X' || tateti[2][2] == 'O') {
    if (tateti[2][2] == tateti[2][0] && tateti[2][2] == tateti[2][1]) {
      if (tateti[0][0] == 'X') {
        gan = 2;
      }
      else {
        gan = 1;
      }
    }
    if (tateti[2][2] == tateti[0][2] && tateti[2][2] == tateti[1][2]) {
      if (tateti[0][0] == 'X') {
        gan = 2;
      }
      else {
        gan = 1;
      }
    }
  }
  //fin caso 9.
  
  if (gan == 1) {
    Serial.println("\nGANO JUGADOR 1");
    tone (A0,700);
    impresion();
    delay (3000);
    noTone(A0);
    reinicio();
  }
  else if (gan == 2) {
    Serial.println("\nGANO JUGADOR 2");
    tone (A0,700);
    impresion();
    delay (3000);
    noTone(A0);
    reinicio();
  }
  if (cont>=9 && gan!=1 && gan!=2){
    Serial.println("\nEMPATE");
    tone (A0,700);
    impresion();
    delay (3000);
    noTone(A0);
    reinicio();
  }
}

void apagar_leds(){
  /*digitalWrite (E1, LOW);
  digitalWrite (E2, LOW);
  digitalWrite (E3, LOW);

  digitalWrite (S1, HIGH);
  digitalWrite (S2, HIGH);
  digitalWrite (S3, HIGH);
*/
}


void reinicio(){
  apagar_leds();
  tateti[0][0]='1';
  tateti[0][1]='2';
  tateti[0][2]='3';
  tateti[1][0]='4';
  tateti[1][1]='5';
  tateti[1][2]='6';
  tateti[2][0]='7';
  tateti[2][1]='8';
  tateti[2][2]='9';
  turno=0;
  Serial.println("\n\n\n\n\n\n\nNUEVA PARTIDA.\n");
  cont=0;
}
