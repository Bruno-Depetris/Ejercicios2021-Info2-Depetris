struct Edatos{
  uint32_t tiempo;
  uint16_t temperatura;
  uint16_t distancia;
  char nombre[20];
};


int valor = 0;
float distancia = 0;
unsigned long tiempo; 
float METROS = 0;
float dist = 0;
void setup(){
  Serial.begin( 115200);
}
void loop(){
  int cantidad = 0;
  Edatos DATOS;
  Serial.println("\nDigite la cantidad de sensores: ");
  while(Serial.available()){
    cantidad = Serial.read();
    Serial.println("usted tiene:");
    Serial.print(cantidad - 48);
  }
  int i;
  for (i=0; i<cantidad; i++){
    Serial.println("\n Edatos - Digite su nombre: " );
    while(Serial.available()){
      DATOS.nombre[i] = Serial.read();
  }
  char opcion;
  Serial.println("\n para leer los datos de Temperatura precionar letra T"
                 "\n para leer los datos de Distancia precionar letra D");

  while(Serial.available()==0){
  opcion = Serial.println();
  }
  
  switch(opcion){
    case 'T':
    
    valor = analogRead(2);
    float mv = (valor/1024.0)*5000;
    float c = mv/10;
    Serial.println("Temperatura: ");
    Serial.println(DATOS.temperatura);
    break;

    case 'D':
    pinMode(3,OUTPUT);
    digitalWrite(3,LOW);
    digitalWrite(3,HIGH);
    delayMicroseconds(3);
    digitalWrite(3,LOW);
    pinMode(3,INPUT);
    tiempo = pulseIn(3,HIGH);
    distancia = 0.03432 * tiempo / 2;
    Serial.println(" Distancia: ");
    Serial.println(DATOS.distancia);
    break;
  }
  return opcion;
  }
}
