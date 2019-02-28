void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(IRread(0)) ;       // 距離(ln有りで改行、無しで改行なし)
  delay(100) ;                          // 500ms後に繰り返す
}

double IRread(int PinNo){
  double ans;
  int i;
  ans = 0;
  for(i=0; i<1000; i++){
    ans = ans + analogRead(PinNo);
  }

  //return ans/1000;
  return 19501.14 * pow(ans/1000 , -1.256676);
}

