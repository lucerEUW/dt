#include<DmxSimple.h>
#include<string.h>

//thunderstruck acdc -- 134 bpm --from 20s
//setting up pins
void setup(){
  DmxSimple.usePin(3);
  DmxSimple.MaxChannel(44);
}

//continues code
void loop(){
  structure();
}

//controlling the headlights
//color 1 = red;2 = green;3 = blue; 4 = white; (0 dim only)
void light(int headPort, int color, int value){
  
  //assign easier numbers for less komlexity
  switch(headPort){
    case  1:
      headPort = 9;
    break;
    case  2:
      headPort = 23;
    break;
    case  3:
      headPort = 1;
    break;
    case  4:
      headPort = 37;
    break;
  }

  //accounting for incapability of displaying white (mHeads)
  if(color  ==  4  && (headPort ==  14 || headPort  ==  28)){

    //simulate white by powering every color equally
    DmxSimple.write(headPort  + 1,  value);
    DmxSimple.write(headPort  + 2,  value);
    DmxSimple.write(headPort  + 3,  value);
  }

  //setting colorvalues
  DmxSimple.write(headPort  + color,  value);
}

//controlling the moving head
void movingHead(int mHeadPort, int pan, int tilt, int speed){

  //accesssing and reassigning movingheads
  if(mHeadPort  ==  1){
    mHeadPort = 9;
  }else if(mHeadPort  ==  2){
    mHeadPort = 23;
  }

  //giving mHeads the values
  DmxSimple.write(mHeadPort     , pan);
  DmxSimple.write(mHeadPort + 2 , tilt);
  DmxSimple.write(mHeadPort + 4 , speed);
}

//for highlighting
void strobe(int headPort, int value){

  //easy access port rename
  if(headPort ==  1){
    headPort = 9;
  }else if(headPort ==  2){
    headPort = 23;
  }

  //white on mhead
  DmxSimple.write(headPort  + 9,  value);
}

//soundlib
void sound(int type){

  //set values
  int     intensity   = 255;
  double  achtel      = 447,8;

  //convert to musical values
  double  sechzehntel   = achtel  * 2;
  double  viertel       = achtel  / 2;

  //instrument type
  //0 = cymbal; 1  = thun der;  2 = pause-red
  switch(type){
    case  0:
      light(3,  3,  255);
      light(4,  3,  255);
      
      delay(achtel);

      light(3,  3,  0);
      light(4,  3,  0);

      delay(achtel);
    break;
    
    case  1:
      strobe(1, 255);
      strobe(2, 255);

      delay(achtel);
      
      strobe(1, 0);
      strobe(2, 0);

      delay(achtel);
    break;

    case  2:
      delay(viertel);

      light(3,  1,  255);
      light(4,  1,  255);

      delay(achtel);

      light(3,  3,  0);
      light(4,  3,  0);

      delay(achtel);      
    break;
  }
}

//20s-50s
void  structure(){

  //intro cymbalhighlighting x 6
  for(int i = 0; i  <=  6; i++){
    for(int j = 0; i  <=  4; i++){
      sound(0);
    }
  }
  
  for(int i = 0; i  <=  100 ;i++){

    //thunder double white
    for(int j = 0; j  <=  2; j++){
      sound(1);
    }
    sound(2);

    //double pause red
    for(int z = 0; z  <=  2; z++){
     sound(2);
    }
  }
}