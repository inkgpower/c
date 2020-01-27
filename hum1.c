#pragma config(Sensor, S1,     c1,             sensorEV3_Color)
#pragma config(Sensor, S2,     c2,             sensorEV3_Color)
#pragma config(Sensor, S3,     c3,             sensorEV3_Color)
#pragma config(Motor,  motorB,          lm,            tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorA,          rm,            tmotorEV3_Large, PIDControl, encoder)

#define DIFF 10
#define maxsize 30

int stack[maxsize];
int index=-1;

int nMotorSpeedSetting = 25;
float P = 0.3, I = 0.00001, D = 5.7, e = 0.0, s = 0.0, pre = 0;
int gray[3], dark[3], bright[3], cnt = 0, gcnt = 0,ct = 0;
bool turnFlag = false,  L = false, R = false, B =false, Gflag = false;

int isFull(){
   if(Gflag == true)
   return true;
   else
   return false;
}
int isEmpty(){
   if(Gflag != true)
   return true;
   else
   return false;
}
int n = 0;


int push(int n)
{
   if(!isFull())
     {
     stack[++index]=n;
     return 0;
      }
   else
      return -1;
}

int pop(int n)
{
   if(!isEmpty())
     {
         n=stack[index--];
      if(n==1) right
         return 0;
         }
   else
      return -1;
}


void scanLine()
{
   displayBigTextLine(1, "scan dark area!!");
   displayBigTextLine(4, "& push up button!!");
   while(getButtonPress(1)==0)sleep(10); playTone(440,20);
   dark[0] = getColorReflected(c1);
   dark[1] = getColorReflected(c2);
   dark[2] = getColorReflected(c3);
   sleep(1000);
   displayBigTextLine(1, "scan bright area!!");
   displayBigTextLine(4, "& push up button!!");
   while(getButtonPress(1)==0)sleep(10); playTone(440,20);
   bright[0] = getColorReflected(c1);
   bright[1] = getColorReflected(c2);
   bright[2] = getColorReflected(c3);
   sleep(1000);
   displayBigTextLine(1, "%d %d %d", bright[0], bright[1], bright[2]);
   displayBigTextLine(4, "%d %d %d", dark[0], dark[1], dark[2]);
  for(int i = 0; i<3; i++)
  {
     gray[i] = (dark[i] + bright[i])/2;
  }
  displayBigTextLine(7, "%d %d %d", gray[0], gray[1], gray[2]);
   displayBigTextLine(10, "push up to Start!");
}

void go()
{
   pre = e; e = getColorReflected(c2)-gray[1]; s += e; pre = e -pre;
   setMotorSpeed(lm, nMotorSpeedSetting + round(e*P + s*I + pre*D));
   setMotorSpeed(rm, nMotorSpeedSetting - round(e*P + s*I + pre*D));
}

void isCross()
{
   if(getColorReflected(c1) < gray[0] || getColorReflected(c3)<gray[2])
   {
      setMotorSpeed(lm, 20);
      setMotorSpeed(rm, 20);
      sleep(160);

      if(getColorReflected(c3) < gray[2])
      {
         L = true;
      }
      else if(L==true)
      {
         turnFlag = true;
      }

      if(getColorReflected(c1) <gray[0])
      {
         R = true;
      }
      else if(R == true)
      {
         turnFlag = true;
      }


      if(getColorReflected(c1) <=gray[0] && getColorReflected(c3) <=gray[2] && getColorReflected(c2) <=gray[1])
      {
         gcnt++;
      }
      else gcnt =0;

      if(gcnt>5) Gflag =true;
   }

   if(getColorReflected(c2)>gray[1]*7/5)
   {
      cnt++;
   }
   else
   {
      cnt = 0;
   }

   if(cnt>450)
   {
      B = true;
      turnFlag = true;
   }
}

void turnLeft()
{
   eraseDisplay();


   if(L==true)displayBigTextLine(11, "TurnLeft!");
   while(getColorReflected(c3) > gray[2])
   {
      setMotorSpeed(lm, -nMotorSpeedSetting*3/10);
      setMotorSpeed(rm, nMotorSpeedSetting*3/10);
   }
   while(getColorReflected(c2) > gray[1])
   {
      setMotorSpeed(lm, -nMotorSpeedSetting*3/10);
      setMotorSpeed(rm, nMotorSpeedSetting*3/10);
   }
   while(getColorReflected(c2) <= gray[1])
   {
      setMotorSpeed(lm, -nMotorSpeedSetting*3/10);
      setMotorSpeed(rm, nMotorSpeedSetting*3/10);
   }
   setMotorSpeed(lm,0);
   setMotorSpeed(rm,0);

}

void turnRight()
{
   eraseDisplay();


   if(R==true)displayBigTextLine(11, "TurnRight!");
   while(getColorReflected(c2) < gray[1])
   {
      setMotorSpeed(lm, -nMotorSpeedSetting*3/10);
      setMotorSpeed(rm, nMotorSpeedSetting*3/10);
   }
   while(getColorReflected(c2) > gray[1])
   {
      setMotorSpeed(lm, nMotorSpeedSetting*3/10);
      setMotorSpeed(rm, -nMotorSpeedSetting*3/10);
   }
   setMotorSpeed(lm,0);
   setMotorSpeed(rm,0);

}
void turnBack(){

   eraseDisplay();

   if(B==true)displayBigTextLine(11, "TurnBack!");
    setMotorSpeed(lm, -20);
    setMotorSpeed(rm, -20);
    sleep(160);
   while(getColorReflected(c2) > gray[1])
   {
      setMotorSpeed(lm, nMotorSpeedSetting*3/10);
      setMotorSpeed(rm, -nMotorSpeedSetting*3/10);
   }
   setMotorSpeed(lm,0);
   setMotorSpeed(rm,0);

}

void stopMotor()
{
   eraseDisplay();
   setMotorSpeed(lm, 0);
   setMotorSpeed(rm, 0);
   if(L == true) displayBigTextLine(1, "Left");
   if(R == true) displayBigTextLine(4, "Right");
   if(B == true) displayBigTextLine(7, "Back");
}

void statusReset()
{
   turnFlag = L = R = B = Gflag = false;
}






//////////////////////////////////////////////////////////////
task main()
{
   scanLine();
   int q;
   while(getButtonPress(1) == 0) sleep(10);
   setMotorSpeed(lm, nMotorSpeedSetting);
   setMotorSpeed(rm, nMotorSpeedSetting);
   sleep(1000);

   while(true)
   {
      go();
      isCross();

      if(turnFlag)
      {
         sleep(530);
         if(L==true) {turnLeft();q=1;}
         else if(R==true) {turnRight();q=3;}
         if(B==true) {turnBack();q=4;}
         statusReset();

         push(q);
         ct++;
      }
      if(Gflag)
      {
         statusReset();
         break;
      }
   }


   playTone(240, 20); sleep(200);
   stopMotor();
   for(int i=0;i<30;i++)
        displayBigTextLine(i+1, "%d, ",stack[i]);
   sleep(4000);

   while(getButtonPress(1) == 0) sleep(10);
}
