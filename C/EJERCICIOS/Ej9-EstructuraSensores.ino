void setup (){
    struct sensores{
        char inicial[1];
        int valor;
        unsigned long tiempo;

    }sensor;
    float variable = 0;
    variable = sizeof(sensor);

    
    Serial.println("%f",variable);
}
void loop (){

}