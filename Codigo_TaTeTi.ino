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
const byte FILASLEDS = 3;
const byte COLUMNASLEDS = 3;

const byte FILASTECLADO = 4;
const byte COLUMNASTECLADO = 3;

char teclado_matricial [FILASTECLADO][COLUMNASTECLADO] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
  
};

char tateti[FILASLEDS][COLUMNASLEDS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

byte pines_filas[FILASTECLADO] = {F1, F2, F3}; 
byte pines_columnas[COLUMNASTECLADO] = {C1, C2, C3}; 
Keypad keypad = Keypad( makeKeymap(teclado_matricial), pines_filas, pines_columnas, FILASTECLADO, COLUMNASTECLADO);


void setup() {
  Serial.begin(9600);
  
 
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
