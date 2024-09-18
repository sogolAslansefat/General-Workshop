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

int second = 0;
int D1_min = 5;
int D2_min = 5;
int D1_hour = 3;
int D2_hour = 2;
ISR(TIMER1_COMPA_vect)
{
  TCNT1 = 0;
  second++;
  if(second == 60)
  {
    second = 0;
    D1_min++;
  }
  if(D1_min == 10)
  {
    D1_min = 0;
    D2_min++;
  }
  if(D2_min == 6)
  {
    D2_min = 0;
    D1_hour++;
  }
  if(D1_hour == 10)
  {
    D1_hour = 0;
    D2_hour++;
  }
  if(D2_hour == 2)
    if(D1_hour == 4)
    {
      D1_hour = 0;
      D2_hour = 0;
    }
    
}

void setup() 
{
  for(int i = 2; i <= 12; i++)
    pinMode(i,OUTPUT);
  
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  
  OCR1A = 62500;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
} 

void loop() 
{
  multiple_shows(num_i[D1_min], num_i[D2_min], num_i[D1_hour], num_i[D2_hour]);
}
