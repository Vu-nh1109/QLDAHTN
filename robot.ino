//Khai báo các chân trên L298n
#define enA 3
#define in1 4
#define in2 5
#define enB 9
#define in3 6
#define in4 7

bool left_1, center, right_1; //dùng kiểu boolean lưu trữ trạng thái của cảm biến
uint8_t Sensor[5] = { A0, A1, A2 }; // mảng Sensor gồm 3 phần tử, lưu trữ các chân analog A0, A1, A2

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);       //Set chân in1 của dc A là output
  pinMode(in2, OUTPUT);       //Set chân in2 của dc A là output
  pinMode(in3, OUTPUT);       //Set chân in1 của dc B là output
  pinMode(in4, OUTPUT);       //Set chân in2 của dc B là output
  pinMode(Sensor[0], INPUT);  //Set chân cảm biến 1 là input
  pinMode(Sensor[1], INPUT);  //Set chân cảm biến 2 là input
  pinMode(Sensor[2], INPUT);  //Set chân cảm biến 3 là input

}

void loop() {
  // gán giá trị đọc được từ sensor vào 3 biến
  left_1 = digitalRead(Sensor[0]);
  center = digitalRead(Sensor[1]);
  right_1 = digitalRead(Sensor[2]);
  Serial.println(String(left_1) + "," + String(center) + "," + String(right_1)); // in giá trị đọc được ra serial
  //xử lý với từng trường hợp giá trị cảm biến
  if ((left_1 == 1) && (center == 0) && (right_1 == 1)) {
    Tien();
  }
  if ((left_1 == 0) && (center == 0) && (right_1 == 1)) {
    Retrai();
  }
  if ((left_1 == 0) && (center == 1) && (right_1 == 1)) {
    Retrai();
  }
  if ((left_1 == 1) && (center == 0) && (right_1 == 0)) {
    Rephai();
  }
  if ((left_1 == 1) && (center == 1) && (right_1 == 0)) {
    Rephai();
  }
  if ((left_1 == 0) && (center == 0) && (right_1 == 0)) {
    Tien();
    delay(150);
  }
  if ((left_1 == 1) && (center == 1) && (right_1 == 1)) {
    Lui();
    delay(150);    
  }
}

void Tien()  // Function xe tiến
{
  analogWrite(enA, 175);
  analogWrite(enB, 175);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void Retrai()  // Function xe re trái
{
  analogWrite(enA, 175);
  analogWrite(enB, 175);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void Rephai()  // Function xe re phải
{
  analogWrite(enA, 175);
  analogWrite(enB, 175);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
void Lui()  // Function xe lùi
{
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
