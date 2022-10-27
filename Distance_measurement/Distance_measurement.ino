


// Successfull failure :(
// The sensor measuring rates mess up the calculations
// The code will be revised with Interrupts  
// Measuring distance covered by both Left and Right wheels



//[0,1] = [Left,Right]

int i = 0;

//Encoder values
int enc_val[2] = {0,0};
int last_enc_val[2] = {0,0};

//Count of encoder ticks
float tick[2] = {0,0}; 

float dist[2] = {0,0};

//Bot specifications
float wheel_radius = 0.065/2; 



void setup() {
  // put your setup code here, to run once:

  pinMode(3, INPUT);  //Left Encoder input
  pinMode(4, INPUT);  //Right Encoder input
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Reading encoder value
  enc_val[0] = digitalRead(3);
  enc_val[1] = digitalRead(4);

  for(i=0;i<2;i++)
  {
    if (enc_val[i] != last_enc_val[i])
    {
      tick[i]++;     
      //Incrementing tick count after each state change
    }
    
  }


  for(i=0;i<2;i++)
  {
    //Distance = (Tick Count/Number of ticks in one full rotation) * Wheel Circumference
    //Wheel circumference = 2*Pi*r
  
    dist[i] = (tick[i]/40) * (2*3.14*wheel_radius);    
  }



    Serial.println(" ");
    Serial.print("Left Tick: ");
    Serial.print(tick[0]);
    Serial.print("Right Tick: ");
    Serial.print(tick[1]);
    Serial.println(" ");
    Serial.print("Left Wheel Distance: ");
    Serial.print(dist[0]);
    Serial.print("Right wheel Distance: ");
    Serial.print(dist[1]);        
  

  for(i=0;i<2;i++)
  {

    //Updating last encoder value with current value    
    last_enc_val[i] = enc_val[i];
  }
  

}
