#define Temperatura A0    
#define Distancia A1      

struct sensores{        
  uint32_t tiempo;     
  uint16_t valor;      
  char nombre;  
};

union Datos{
  sensores dato;
  byte a[sizeof(sensores)];
}Temp,Dist;

float T = 0, mv = 0, _Tiempo;
int i = 0;
float tt = 0, td = 0;      //Diferencia de tiempos de cada sensor
float tti = 0, tdi = 0;      //Tiempo inicial de cada sensor
float ttf = 0, tdf = 0;      //Tiempo final de cada sensor
String DatoRecibido;
void setup() {
  Serial.begin(9600);                                //Puerto serie
  
}

void loop() {
  
  Temp.dato.nombre = 'T';     //Calculo de Temperatura
  T = analogRead(Temperatura);
  mv = (T/1024.0)*5000;
  Temp.dato.valor = mv/10;          
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
  Temp.dato.tiempo = tt;                            //Guardamos el valor del tiempo en el miembro de la variable que es de tipo estructura
  
  Dist.dato.nombre = 'D';
  pinMode(Distancia,OUTPUT); 
  digitalWrite(Distancia,LOW);
  digitalWrite(Distancia,HIGH);
  delayMicroseconds(Distancia);
  digitalWrite(Distancia,LOW);
  pinMode(Distancia,INPUT);
  _Tiempo = pulseIn(Distancia,HIGH);
  Dist.dato.valor = 0.03432 * _Tiempo / 2;  //Calculo de Distancia
  
  if(Serial.available()>0){                 //Se pregunta si hay datos en el puerto serie
    DatoRecibido = Serial.readString();                     //Se guardan datos recibidos en una variable
    
    if(DatoRecibido == "T"){                                //Si se recibe el dato y si esta 
      for(unsigned long long i=0;i<(sizeof(sensores));i++){    // con este for y el Serial.write se byte a byte
        Serial.write(Temp.a[i]);
      }
    }
    if(DatoRecibido == "D"){
      for(unsigned long long i=0;i<(sizeof(sensores));i++){
        Serial.write(Dist.a[i]);
      }
    }
  }
  delay(1000);
}
