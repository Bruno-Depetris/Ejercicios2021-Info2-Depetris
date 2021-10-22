void setup(){
  	
	DDRD = B1111111; 
}
byte pines;
void loop(){
PORTD = B0000001;
delay(300);
PORTD = B0000010;
delay(300);
PORTD = B0000100;
delay(300);
PORTD = B0001000;
delay(300);
PORTD = B0010000;
delay(300);
PORTD = B0100000;
delay(300);
PORTD = B1000000;
delay(300);

}