#define D4 12
#define A  2
#define F  7
#define D3 11
#define D2 10
#define B  3
#define E  6
#define D  5
#define C  4
#define G  8
#define D1 9
const byte no_on[] = {0, 0, 0, 0};
const byte D1_on[] = {1, 0, 0, 0};
const byte D2_on[] = {0, 1, 0, 0};
const byte D3_on[] = {0, 0, 1, 0};
const byte D4_on[] = {0, 0, 0, 1};
const byte Di_on[5][4] = {
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0}, 
  {0, 0, 0, 1}};

const byte num_0[] = {0, 0, 0, 0, 0, 0, 1};
const byte num_1[] = {1, 0, 0, 1, 1, 1, 1};
const byte num_2[] = {0, 0, 1, 0, 0, 1, 0};
const byte num_3[] = {0, 0, 0, 0, 1, 1, 0};
const byte num_4[] = {1, 0, 0, 1, 1, 0, 0};
const byte num_5[] = {0, 1, 0, 0, 1, 0, 0};
const byte num_6[] = {0, 1, 0, 0, 0, 0, 0};
const byte num_7[] = {0, 0, 0, 1, 1, 1, 1};
const byte num_8[] = {0, 0, 0, 0, 0, 0, 0};
const byte num_9[] = {0, 0, 0, 0, 1, 0, 0};
const byte num_i[10][7] = {
  {0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 1, 0},
  {1, 0, 0, 1, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0}};

void seven_segment(byte* digit, byte* number)
{ 
  digitalWrite(D1, digit[0]);
  digitalWrite(D2, digit[1]);
  digitalWrite(D3, digit[2]);
  digitalWrite(D4, digit[3]);

  digitalWrite(A, number[0]);
  digitalWrite(B, number[1]);
  digitalWrite(C, number[2]);
  digitalWrite(D, number[3]); 
  digitalWrite(E, number[4]);
  digitalWrite(F, number[5]);
  digitalWrite(G, number[6]);
}

void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
} 

void loop() {
  for(int i = 1; i < 5; i++)
    for(int j = 0; j < 10; j++)
    {
      seven_segment(Di_on[i], num_i[j]);
      delay(1000); 
    }
}
