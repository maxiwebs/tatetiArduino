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
#define C2 18
#define C3 19
#define F1 14
#define F2 15
#define F3 16
#define F4 17

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

byte pines_filas[FILASTECLADO] = {F1, F2, F3, F4}; 
byte pines_columnas[COLUMNASTECLADO] = {C1, C2, C3}; 
Keypad keypad = Keypad( makeKeymap(teclado_matricial), pines_filas, pines_columnas, FILASTECLADO, COLUMNASTECLADO);

int jugadorActual = 0;
char teclaPresionada;
bool alguienGano = false;
char ganador = 'X';
int cantidadMovimientos = 0;

void setup() {
  Serial.begin(9600);
 
}


void loop() {

  //testLedsRGB();
  //testTeclado();

  while (!alguienGano){
    mostrarTurnoJugador(jugadorActual);
    imprimirTablero();
    teclaPresionada = escucharTeclado();
    cantidadMovimientos++;
    Serial.print("Volvi con tecla: "); Serial.println(teclaPresionada);
    prenderLedJugado(jugadorActual,teclaPresionada);
    alguienGano = chequearVictoria(cantidadMovimientos);
    siguienteTurno(jugadorActual);  
  }

  mostrarGanador();
  reiniciarJuego();
  Serial.println("FIN de JUEGO");
}

//FUNCIONES DE JUEGO

//Espera la tecla * para reiniciar el juego
void reiniciarJuego(){

  Serial.println("Para reiniciar el juego presione la tecla *"); //print to serial the key that has been pressed
  delay(50);
  char key = keypad.getKey();
  
  if (key != NO_KEY && key == '*'){
    Serial.println(key);
    alguienGano = false;
    limpiarMatriz();
  }

}

//Reinicio la matriz de juego tateti
void limpiarMatriz(){
  int contador = 1;
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      tateti[i][j] = contador + '0';
      contador++;
    } 
  }
  imprimirTablero();
}

//Prendo todos los leds con el color del ganador
void mostrarGanador(){

  if (ganador == 'R'){
    digitalWrite(R11, HIGH); digitalWrite(G11, LOW); digitalWrite(B11, LOW);
    digitalWrite(R12, HIGH); digitalWrite(G12, LOW); digitalWrite(B12, LOW);
    digitalWrite(R13, HIGH); digitalWrite(G13, LOW); digitalWrite(B13, LOW);
    digitalWrite(R21, HIGH); digitalWrite(G21, LOW); digitalWrite(B21, LOW);
    digitalWrite(R22, HIGH); digitalWrite(G22, LOW); digitalWrite(B22, LOW);
    digitalWrite(R23, HIGH); digitalWrite(G23, LOW); digitalWrite(B23, LOW);
    digitalWrite(R31, HIGH); digitalWrite(G31, LOW); digitalWrite(B31, LOW);
    digitalWrite(R32, HIGH); digitalWrite(G32, LOW); digitalWrite(B32, LOW);
    digitalWrite(R33, HIGH); digitalWrite(G33, LOW); digitalWrite(B33, LOW);  
  }else if (ganador == 'V'){
    digitalWrite(R11, LOW); digitalWrite(G11, HIGH); digitalWrite(B11, LOW);
    digitalWrite(R12, LOW); digitalWrite(G12, HIGH); digitalWrite(B12, LOW);
    digitalWrite(R13, LOW); digitalWrite(G13, HIGH); digitalWrite(B13, LOW);
    digitalWrite(R21, LOW); digitalWrite(G21, HIGH); digitalWrite(B21, LOW);
    digitalWrite(R22, LOW); digitalWrite(G22, HIGH); digitalWrite(B22, LOW);
    digitalWrite(R23, LOW); digitalWrite(G23, HIGH); digitalWrite(B23, LOW);
    digitalWrite(R31, LOW); digitalWrite(G31, HIGH); digitalWrite(B31, LOW);
    digitalWrite(R32, LOW); digitalWrite(G32, HIGH); digitalWrite(B32, LOW);
    digitalWrite(R33, LOW); digitalWrite(G33, HIGH); digitalWrite(B33, LOW);
  }
  delay(300);
  //Apago todos
  digitalWrite(R11, LOW); digitalWrite(G11, LOW); digitalWrite(B11, LOW);
  digitalWrite(R12, LOW); digitalWrite(G12, LOW); digitalWrite(B12, LOW);
  digitalWrite(R13, LOW); digitalWrite(G13, LOW); digitalWrite(B13, LOW);
  digitalWrite(R21, LOW); digitalWrite(G21, LOW); digitalWrite(B21, LOW);
  digitalWrite(R22, LOW); digitalWrite(G22, LOW); digitalWrite(B22, LOW);
  digitalWrite(R23, LOW); digitalWrite(G23, LOW); digitalWrite(B23, LOW);
  digitalWrite(R31, LOW); digitalWrite(G31, LOW); digitalWrite(B31, LOW);
  digitalWrite(R32, LOW); digitalWrite(G32, LOW); digitalWrite(B32, LOW);
  digitalWrite(R33, LOW); digitalWrite(G33, LOW); digitalWrite(B33, LOW);
  delay(300);

}

void imprimirTablero(){
  
  for (int i = 0; i<3 ; i++){
    for (int j = 0; j<3; j++){
      Serial.print(tateti[i][j]); Serial.print(",");
    }
    Serial.println("");
  }

}

bool chequearVictoria(int cantMovs){

  //Si no hay al menos 5 fichas jugadas, nadie gano
  if (cantMovs <= 4) return false;

  //Las posibilidades de ganar con led 11
  if (tateti[0][0] == tateti[0][1] && tateti[0][1] == tateti[0][2]){ //F1
    Serial.print("Hay ganador!!!"); Serial.println(tateti[0][0]);
    ganador = tateti[0][0];
    return true;
  }else if (tateti[0][0] == tateti[1][0] && tateti[1][0] == tateti[2][0]){ //C1
    Serial.print("Hay ganador!!!"); Serial.println(tateti[0][0]);
    ganador = tateti[0][0];
    return true; 
  }else if (tateti[0][0] == tateti[1][1] && tateti[1][1] == tateti[2][2]){ //D1
    Serial.print("Hay ganador!!!"); Serial.println(tateti[0][0]);
    ganador = tateti[0][0];
    return true; 
  }else if (tateti[1][0] == tateti[1][1] && tateti[1][1] == tateti[1][2]){ //F2
    Serial.print("Hay ganador!!!"); Serial.println(tateti[1][0]);
    ganador = tateti[1][0];
    return true; 
  }else if (tateti[2][0] == tateti[2][1] && tateti[2][1] == tateti[2][2]){ //F3
    Serial.print("Hay ganador!!!"); Serial.println(tateti[2][0]);
    ganador = tateti[2][0];
    return true;
  }else if (tateti[2][0] == tateti[1][1] && tateti[1][1] == tateti[0][2]){ //D2
    Serial.print("Hay ganador!!!"); Serial.println(tateti[2][0]);
    ganador = tateti[2][0];
    return true; 
  }else if (tateti[0][1] == tateti[1][1] && tateti[1][1] == tateti[2][1]){ //C2
    Serial.print("Hay ganador!!!"); Serial.println(tateti[0][1]);
    ganador = tateti[0][1];
    return true; 
  }else if (tateti[0][2] == tateti[1][2] && tateti[1][2] == tateti[2][2]){ //C3
    Serial.print("Hay ganador!!!"); Serial.println(tateti[0][2]);
    ganador = tateti[0][2];
    return true; 
  }else {
    return false;
  }
      
  

}

void siguienteTurno(int jugActual){
  jugadorActual = (jugActual+1)%2;
  Serial.print("Turno de: "); Serial.println(jugadorActual);
}

void prenderLedJugado(int jugActual, char teclaPres){

  //O: rojo, 1: verde

  switch (teclaPres){
    case '1':
      if (jugActual == 0){
        //Prendo 1 rojo
        digitalWrite(R11, HIGH); digitalWrite(G11, LOW); digitalWrite(B11, LOW);
        tateti[0][0] = 'R';
      }else {
        //Prendo 1 verde
        digitalWrite(R11, LOW); digitalWrite(G11, HIGH); digitalWrite(B11, LOW);    
        tateti[0][0] = 'V';
      }
      break;

    case '2':
      if (jugActual == 0){
        //Prendo 2 rojo
        digitalWrite(R12, HIGH); digitalWrite(G12, LOW); digitalWrite(B12, LOW);
        tateti[0][1] = 'R';
      }else {
        //Prendo 2 verde
        digitalWrite(R12, LOW); digitalWrite(G12, HIGH); digitalWrite(B12, LOW);    
        tateti[0][1] = 'V';
      }
      break;  
    case '3':
      if (jugActual == 0){
        //Prendo 3 rojo
        digitalWrite(R13, HIGH); digitalWrite(G13, LOW); digitalWrite(B13, LOW);
        tateti[0][2] = 'R';
      }else {
        //Prendo 3 verde
        digitalWrite(R13, LOW); digitalWrite(G13, HIGH); digitalWrite(B13, LOW);    
        tateti[0][2] = 'V';
      }
      break;
      
    case '4':
      if (jugActual == 0){
        //Prendo 4 rojo
        digitalWrite(R21, HIGH); digitalWrite(G21, LOW); digitalWrite(B21, LOW);
        tateti[1][0] = 'R';
      }else {
        //Prendo 4 verde
        digitalWrite(R21, LOW); digitalWrite(G21, HIGH); digitalWrite(B21, LOW);    
        tateti[1][0] = 'V';
      }
      break;
      
    case '5':
      if (jugActual == 0){
        //Prendo 5 rojo
        digitalWrite(R22, HIGH); digitalWrite(G22, LOW); digitalWrite(B22, LOW);
        tateti[1][1] = 'R';
      }else {
        //Prendo 5 verde
        digitalWrite(R22, LOW); digitalWrite(G22, HIGH); digitalWrite(B22, LOW);    
        tateti[1][1] = 'V';
      }
      break;
      
    case '6':
      if (jugActual == 0){
        //Prendo 6 rojo
        digitalWrite(R23, HIGH); digitalWrite(G23, LOW); digitalWrite(B23, LOW);
        tateti[1][2] = 'R';
      }else {
        //Prendo 6 verde
        digitalWrite(R23, LOW); digitalWrite(G23, HIGH); digitalWrite(B23, LOW);    
        tateti[1][2] = 'V';
      }
      break;
      
    case '7':
      if (jugActual == 0){
        //Prendo 7 rojo
        digitalWrite(R31, HIGH); digitalWrite(G31, LOW); digitalWrite(B31, LOW);
        tateti[2][0] = 'R';
      }else {
        //Prendo 7 verde
        digitalWrite(R31, LOW); digitalWrite(G31, HIGH); digitalWrite(B31, LOW);    
        tateti[2][0] = 'V';
      }
      break;
        
    case '8':
      if (jugActual == 0){
        //Prendo 8 rojo
        digitalWrite(R32, HIGH); digitalWrite(G32, LOW); digitalWrite(B32, LOW);
        tateti[2][1] = 'R';
      }else {
        //Prendo 8 verde
        digitalWrite(R32, LOW); digitalWrite(G32, HIGH); digitalWrite(B32, LOW);    
        tateti[2][1] = 'V';
      }
      break;

    case '9':
      if (jugActual == 0){
        //Prendo 9 rojo
        digitalWrite(R33, HIGH); digitalWrite(G33, LOW); digitalWrite(B33, LOW);
        tateti[2][2] = 'R';
      }else {
        //Prendo 9 verde
        digitalWrite(R33, LOW); digitalWrite(G33, HIGH); digitalWrite(B33, LOW);    
        tateti[2][2] = 'V';
      }  
      break;
      
  }//FIN switch(teclaPres)
}

char escucharTeclado(){

  char presionada = NO_KEY;
  char key  = NO_KEY;

  //Mientras no se apriete una tecla
  while (key == NO_KEY){
    //Me quedo esperando
    Serial.println("Presione una tecla y luego confirme con #");
    presionada = keypad.getKey();

    //Si presionaron una tecla y no es #
    if (presionada != NO_KEY && presionada != '#'){
      delay(100);
      //Muestro la tecla presionada
      Serial.println(presionada);
      //Espero confirmacion (#)
      key = keypad.getKey();

      //Mientras no presionen confirmacion o cambien de opinion
      while (key == NO_KEY){
        Serial.println("Presione # para confirmar.");
        key = keypad.getKey();
        //Si apretaron una tecla y es la confirmacion
        if (key != NO_KEY && key == '#'){
          //Devuelvo la tecla presionada
          return presionada;

         //Si cambiaron de opinion y no confirmaron (pero apretaron otra tecla)
        }else if (key != NO_KEY){
          //Actualizo la tecla presionada
          presionada = key;
          //Muestro nueva tecla presionada
          Serial.println(presionada);
          //Seteo vacio para esperar confirmacion (#)
          key = NO_KEY;
        }
        delay(100);
      }
      
    }
    delay(100);
  }
}

void mostrarTurnoJugador(int actual){
  
  if (actual == 0){
    //muestro color Rojo en el led del turno
    digitalWrite(RLT, HIGH); digitalWrite(BLT, LOW); digitalWrite(GLT, LOW);
  }else{
    //muestro color Verde en el led del turno
    digitalWrite(GLT, HIGH); digitalWrite(BLT, LOW); digitalWrite(RLT, LOW);
  }

}


//FIN FUNCIONES DE JUEGO


//Test del Teclado
void testTeclado(){
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key); //print to serial the key that has been pressed
  }
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
