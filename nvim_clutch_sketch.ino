const int footpedal_pin = 8; // Digital Pin 8 to Read the Input from Pedal
int footpedal_previous_state=0;

void setup(){
  pinMode(footpedal_pin, INPUT); // We need to recieve data from  footpedal
  Serial.begin(9600);
}

void loop(){
  int footpedal_current_state = digitalRead(footpedal_pin); // Check if pressed or released
  if(footpedal_current_state == 1 && footpedal_previous_state != footpedal_current_state){
    Serial.println(1);
    
  }   
  footpedal_previous_state = footpedal_current_state;
  delay(20);
}
