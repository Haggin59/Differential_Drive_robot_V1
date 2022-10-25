//Encoder values
int enc_val = 0;
int last_enc_val = 0;

//Count of encoder ticks
float tick = 0; 

float dist = 0;

//Bot specifications
float wheel_radius = 0.065/2; 



void setup() {
  // put your setup code here, to run once:

  pinMode(3, INPUT);  //Encoder input
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Reading encoder value
  enc_val = digitalRead(3);
  
  if (enc_val != last_enc_val)
  {
    tick++;     
    //Incrementing tick count after each state change
  }

  //Distance = (Tick Count/Number of ticks in one full rotation) * Wheel Circumference
  //Wheel circumference = 2*Pi*r
  dist = (tick/40) * (2*3.14*wheel_radius);    
  
  Serial.println(" "); 
  Serial.print("Tick: ");
  Serial.print(tick);
  Serial.print("|| Distance: ");
  Serial.print(dist);

  //Updating last encoder value with current value
  last_enc_val = enc_val;

}
