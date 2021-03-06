#define TRIG 9 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 8 //ECHO 핀 설정 (초음파 받는 핀)
#define IN 10 //부저 핀 설정


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // 시리얼 통신 시작 
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IN, OUTPUT);
 
}



void loop() {
  
  distance_sensor();  //초음파 센서 측정
  alram();  //부저 사이렌 측정
}



//==================================================================초음파센서
void distance_sensor(){
  // put your main code here, to run repeatedly:
  long duration, distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG, LOW);

  duration = pulseIn (ECHO, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.


  //34000*초음파가 물체로 부터 반사되어 돌아오는시간 /1000000 / 2(왕복값이아니라 편도값이기때문에 나누기2를 해줍니다.)
 //초음파센서의 거리값이 위 계산값과 동일하게 Cm로 환산되는 계산공식 입니다. 수식이 간단해지도록 적용했습니다.

  distance = duration * 17 / 1000; 


  //PC모니터로 초음파 거리값을 확인 하는 코드 입니다.
  Serial.println(distance); //측정된 물체로부터 거리값(cm값)을 보여줍니다.
  delay(500); //1초마다 측정값을 보여줍니다.
}






//=====================================================================피에조부저
void alram(){

if( Serial.available() ){
      digitalWrite(IN, Serial.read());
  }
}
