#include <SPI.h>  //incluimos librerias para poder utilizar la memoria SD
#include <SD.h>
File DatoS;      //creamos una variable para poder usar archivos 
#define Temp 2   
#define Dist 3      
#define pulsador 5          // Definimos el pin del pulsador 
struct sensor{        //Definimos una estructura
  uint32_t tiempo;     
  uint16_t valor;      //valor obtenido de los sensores
  char nombre;           //Letra de identificacion para el sensor
}Temperatura, Distancia;


float T = 0, mv = 0, _Tiempo;
int i = 0;
float tt = 0, td = 0;      //Diferencia de tiempos de cada sensor
float tti = 0, tdi = 0;      //Tiempo inicial de cada sensor
float ttf = 0, tdf = 0;      //Tiempo final de cada sensor


void setup() {
  Serial.begin(9600);                        
  if (!SD.begin(4)) {                        //SD en el pin 4;
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  pinMode(pulsador, INPUT);                        //declaramos al pulsador como entrada
  
}

void loop() {
  
  Temperatura.nombre = 'T';     //Calculo de Temperatura
  T = analogRead(Temp);
  mv = (T/1024.0)*5000;
  Temperatura.valor = mv/10;          
  if (i==1){                                    
    tti = millis();
    i++;
    tt=tti;
  }
  else{
    ttf=millis();
    tt=ttf-tti;
    tti=ttf;
  }
  Temperatura.tiempo = tt;                            //Guardamos el valor del tiempo en el miembro de la variable que es de tipo estructura
  
  Distancia.nombre = 'D';
  pinMode(Dist,OUTPUT); 
  digitalWrite(Dist,LOW);
  digitalWrite(Dist,HIGH);
  delayMicroseconds(Dist);
  digitalWrite(Dist,LOW);
  pinMode(Dist,INPUT);
  _Tiempo = pulseIn(Dist,HIGH);
  Distancia.valor = 0.03432 * _Tiempo / 2;  //Calculo de Distancia

  
  if(digitalRead(pulsador) == 1){                        
    DatoS = SD.open("sensores.txt", FILE_WRITE);             //creacion/apertura
    
    if (DatoS) {
      
      DatoS.write((const uint8_t *)&Temperatura, sizeof(Temperatura));
      DatoS.write((const uint8_t *)&Distancia, sizeof(Distancia));      //Si el archivo se envian 2 struct byte a byte
  
      DatoS.close();                                        //Se cierra el archivo
    } else {

      Serial.println("ERROR al abrrur archivo txt");
    }
    Serial.println("Datos guardados");
  }
}
