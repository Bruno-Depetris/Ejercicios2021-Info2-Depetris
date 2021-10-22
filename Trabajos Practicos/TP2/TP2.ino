#include <SPI.h>
#include <SD.h>
#define SSpin 10
File archivo;
unsigned long T0,TF;

int valor = 0;
float distancia = 0;
unsigned long tiempo; 
float METROS = 0;
float dist = 0;
struct datoTipo{
  char temp[20];
  char dis[20];
  char gas[20];
}datoTipo;
struct datosMedicion{
  float T;
  float D;
  float G;
};
struct datoTiempo{
  uint32_t ti;
  uint32_t tf;
};


void setup() {
  Serial.begin(9600);                           // inicializa monitor serie a 9600 bps
  Serial.println("Inicializando tarjeta ...");  // texto en ventana de monitor
  if (!SD.begin(SSpin)) {                       // inicializacion de tarjeta SD
    Serial.println("fallo en inicializacion !");// si falla se muestra texto correspondiente y
    return;                                     // se sale del setup() para finalizar el programa
  }
  pinMode(SSpin, OUTPUT);
  Serial.println("inicializacion correcta");  // texto de inicializacion correcta
 
}
void loop(){
  T0=micros();
  
  //Configuramos el sensor de temperatura
  valor = analogRead(A4);
  float mv = (valor/1024.0)*5000;
  float c = mv/10;
  Serial.print("Temperatura: ");
  Serial.println(c);
  
  //Configuramos el sensor de distancia
  pinMode(A3,OUTPUT);
  digitalWrite(A3,LOW);
  digitalWrite(A3,HIGH);
  delayMicroseconds(3);
  digitalWrite(A3,LOW);
  pinMode(A3,INPUT);
  tiempo = pulseIn(A3,HIGH);
  distancia = 0.03432 * tiempo / 2;
  Serial.print(" Distancia: ");
  Serial.println(distancia,1);
  
  //Configuramos el sensor de gas
  float valor = analogRead(A5);
  valor = map(valor, 300, 750, 0, 100);
  Serial.print(" Gas: ");
  Serial.println(valor);
  delay(250);  
  TF = micros()-T0;     //Calculo el tiempo que pasó desde que se tomó la muestra T0 hasta ahora
  Serial.print("El tiempo total en microsegundos usando programacion en bajo nivel es: ");
  Serial.println(TF);  //alrededor de 76 us para Arduino Uno

 archivo = SD.open("DatosMedicion.txt", FILE_WRITE);  
    if (archivo) {
      Serial.println("abierto para escribir 'test.txt'");
      for(int i=0;i<=50;i++){
      struct datosMedicion DatosM;
      DatosM.T = Serial.println(c);
      DatosM.D = Serial.println(distancia,1);
      DatosM.G = Serial.println(valor);
      struct datoTiempo datoT;
      datoT.ti = Serial.println(TF);
      archivo.write((const uint8_t*)&DatosM, sizeof(DatosM));
      archivo.write((const uint8_t*)&datoT, sizeof(datoT));
      }
      archivo.close(); 
      }
  }
