void setup()
{
  DDRB = 32;
}
void loop()
{
  PORTB = 32;
  for(long i = 0; i<1000000; i++){PORTB = 32;}
  PORTB = 0;
  for(long i = 0; i<1000000; i++){PORTB = 0;}
}
//PCINT


// int main() {



//   while(1) {


//   }
// }