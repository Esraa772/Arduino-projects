#define n1  45    //motor number 3 Back&Left
#define n2  44    //motor number 3 Back&Left
#define n3  6     //motor number 2 Back&Right 
#define n4  7    //motor number 2 Back&Right
#define n11 3      //motor number 1 Right&Front
#define n21 2     //motor number 1 Right&Front
#define n31 4     //motor number 4 Left&Front
#define n41 5     //motor number 4 Left&Front
int sensor[5] = {0, 0, 0, 0, 0};
String h="";

void Forward(int t)
{
/*back&left*/
    analogWrite(n1,0);
    analogWrite(n2,170);  //135 first  //second 145  //third 185      

/*back&Right*/
    analogWrite(n3,200); //150 first
    analogWrite(n4,0);   


/*front&Right motor*/
    analogWrite(n11,200); //170 first
    analogWrite(n21,0);



/*front&left motor*/
    analogWrite(n31,0);
    analogWrite(n41,170); //170 first
delay(t);}
void Left(int t)
{
/*back&left*/
    analogWrite(n1,170);
    analogWrite(n2,0);

/*back&Right*/
    analogWrite(n3,200);
    analogWrite(n4,0);


/*front&Right motor*/
    analogWrite(n11,200);
    analogWrite(n21,0);



/*front&left motor*/
    analogWrite(n31,170);
    analogWrite(n41,0);  
    delay(t);}
void Right(int t)
{
/*back&left*/
    analogWrite(n1,0);
    analogWrite(n2,170);

/*back&Right*/
    analogWrite(n3,0);
    analogWrite(n4,200);


/*front&Right motor*/
    analogWrite(n11,0);
    analogWrite(n21,200);



/*front&left motor*/
    analogWrite(n31,0);
    analogWrite(n41,170);  
    delay(t);
}

void Back(int t)
{
/*back&left*/
    analogWrite(n1,170);
    analogWrite(n2,0);      

/*back&Right*/
    analogWrite(n4,170);
    analogWrite(n3,0);   


/*front&Right motor*/
    analogWrite(n21,170);
    analogWrite(n11,0);



/*front&left motor*/
    analogWrite(n41,0);
    analogWrite(n31,170);
    delay(t);
delay(t);
}

void Stop()
{
/*back&left*/
    analogWrite(n1,0);
    analogWrite(n2,0);      

/*back&Right*/
    analogWrite(n3,0);
    analogWrite(n4,0);   


/*front&Right motor*/
    analogWrite(n11,0);
    analogWrite(n21,0);



/*front&left motor*/
    analogWrite(n31,0);
    analogWrite(n41,0);
}






void setup() {
  // put your setup code here, to run once:


pinMode(n1,OUTPUT);
pinMode(n2,OUTPUT);
pinMode(n3,OUTPUT);
pinMode(n4,OUTPUT);
pinMode(n11,OUTPUT);
pinMode(n21,OUTPUT);
pinMode(n31,OUTPUT);
pinMode(n41,OUTPUT);

/*
Serial.begin(9600);
*/
}

void loop() {
  // put your main code here, to run repeatedly:


  sensor[0] = digitalRead(A1);//s1
  sensor[1] = digitalRead(A2);//s2
  sensor[2] = digitalRead(A3);//s3
  sensor[3] = digitalRead(A4);//s4
  sensor[4] = digitalRead(A5);//s5
/*Serial.print(sensor[0]);Serial.print(sensor[1]);Serial.print(sensor[2]);Serial.print(sensor[3]);Serial.print(sensor[4]);Serial.println();
delay(150);
*/

if ((sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1))
    Forward(1);
else if ((sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0))
    Forward(1);
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0 ) && (sensor[4] == 1))
    Forward(1);



    
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);
else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))
    Right(1);//





else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);
else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);//
else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);
else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);






/*

if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Forward(1);
else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 0))
    Forward(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    Forward(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    Stop();
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);
else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    Right(1);//
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))
    Right(1);//#
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);
else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);//
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);
else if(sensor[0]==0&& sensor[1]==0 && sensor[2]==1&& sensor[3]==0&&sensor[4]==1)
{
  Left(1);
}
else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);
else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    Left(1);
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0))
    Right(1);
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0 ) && (sensor[4] == 0))
    Right(1);
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0 ) && (sensor[4] == 1))
    Forward(1);
else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0 ) && (sensor[4] == 1))
    Forward(1);
else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
   {if .....................}
else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    Left(1);
else
{
  Forward(1);
}

*/
}
