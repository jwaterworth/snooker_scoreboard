#define BTM_LFT 7
#define BTM 8
#define DP 2
#define BTM_RHT 3
#define MDL 5
#define TOP_RHT 4
#define TOP_LFT 9
#define TOP 6

byte segs[] = { TOP, TOP_RHT, MDL, BTM_LFT, BTM, BTM_RHT, MDL, TOP_LFT, DP, DP };

byte LSHAPE[] = {TOP_LFT,BTM_LFT,BTM};
byte OSHAPE[] = {TOP,TOP_LFT,BTM_LFT,BTM,BTM_RHT,TOP_RHT};
byte ASHAPE[] = {BTM_LFT,TOP_LFT,TOP,TOP_RHT,BTM_RHT,MDL};
byte DSHAPE[] = {MDL,BTM_LFT,BTM,BTM_RHT,TOP_RHT};
byte ISHAPE[] = {BTM_RHT,TOP_RHT};
byte NSHAPE[] = {BTM_LFT,MDL,BTM_RHT};
byte GSHAPE[] = {TOP,TOP_LFT,MDL,TOP_RHT,BTM_RHT,BTM};


void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}

void loop(){
  
  for(int i = 0; i<sizeof(LSHAPE); i++) {
    digitalWrite(LSHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
  
  
  for(int i = 0; i<sizeof(OSHAPE); i++) {
    digitalWrite(OSHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
    
  for(int i = 0; i<sizeof(ASHAPE); i++) {
    digitalWrite(ASHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
    
  for(int i = 0; i<sizeof(DSHAPE); i++) {
    digitalWrite(DSHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
    
  for(int i = 0; i<sizeof(ISHAPE); i++) {
    digitalWrite(ISHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
  
 for(int i = 0; i<sizeof(NSHAPE); i++) {
    digitalWrite(NSHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
    
  for(int i = 0; i<sizeof(GSHAPE); i++) {
    digitalWrite(GSHAPE[i], LOW);
  }
  delay(500);
  for(int i = 0; i<sizeof(segs); i++) {
    digitalWrite(segs[i], HIGH);
  }
    
  
}
