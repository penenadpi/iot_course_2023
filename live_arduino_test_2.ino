int command = 0;
int state = 0;
void setup() {
  // relej na izlaznom pinu.
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
  command = Serial.read();
  Serial.println(command);
  
    if(command == 49 && state==0)
        Serial.println(1);
        state = 1;
        digitalWrite(10, state);
        while(Serial.read()!=48)
        {}
                
    if(command == 48 & state==1)
        Serial.println(0);
        state = 0;
        digitalWrite(10, state);    
        while(Serial.read()!=49)
        {}  
  }
}
