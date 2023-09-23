#include <iostream>

int main ( int argc , char* argv[])
{
  int n = 0;
  int A1 = 15;
  int A5 = 70;
  int A10 = 125;
  int A20 = 230;
  int A60 = 440;
  std::cin >> n;
  int kp60 = n / 60;
  int n1 = n% 60;
  int kp20 = n1 / 20;
  int n2 = n1 % 20;
  int kp10 = n2 / 10;
  int n3 = n2 % 10;
  int kp5 = n3 / 5;
  int kp1 = n3 % 5;

  if (kp1 * A1 >= A5){
    kp1 = 0;
    kp5++;
  } if (kp1 * A1 + kp5 * A5 >= A10){
    kp1 = 0;
    kp5 = 0;
    kp10++;
  } if (kp1 * A1 + kp5 * A5 + kp10 * A10 >= A20){
    kp1 = 0;
    kp5 = 0;
    kp10 = 0;
    kp20++;
  } if (kp1 * A1 + kp5 * A5 + kp10 * A10 + kp20 * A20 >= A60){
    kp1 = 0;
    kp5 = 0;
    kp10 = 0;
    kp20 = 0;
    kp60++;
  }
  std::cout<< kp1 << " " << kp5 << " " << kp10 << " " << kp20 << " " << kp60;
  return EXIT_SUCCESS;
}
