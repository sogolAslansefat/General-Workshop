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
const byte* Di_on[] = {D1_on, D2_on, D3_on, D4_on};

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
const byte* numbers[] = {num_0, num_1, num_2, num_3, num_4, num_5, num_6, num_7, num_8, num_9};


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

void multiple_shows(byte* D1_num, byte* D2_num, byte* D3_num, byte* D4_num)
{
  seven_segment(D1_on, D1_num);
  delay(1);
  seven_segment(D2_on, D2_num);
  delay(1);
  seven_segment(D3_on, D3_num);
  delay(1);
  seven_segment(D4_on, D4_num);
  delay(1);
}

void setup() 
{
  for(int i = 2; i <= 12; i++)
    pinMode(i,OUTPUT);
} 

void loop() 
{
  multiple_shows(num_i[8], num_i[5], num_i[7], num_i[3]);
}
