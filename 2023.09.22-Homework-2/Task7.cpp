#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int a = 0;
    std::cin >>a;
    int b = a/10;
    int c = a%10;
    if (b == 10){
        std::cout << "C";
    } if (b == 9){
        std::cout << "XC";
    } if (b == 8) {
        std::cout << "LXXX";
    } if (b == 7) {
        std::cout << "LXX";
    } if (b == 6) {
        std::cout << "LX";
    } if (b == 5){
        std::cout << "L";
    } if (b == 4) {
        std::cout << "XL";
    } if (b == 3) {
        std::cout << "XXX";
    } if (b == 2) {
        std::cout << "XX";
    } if (b == 1) {
        std::cout << "X";
    }
    if (c == 9){
        std::cout << "IX";
    } if (c == 8) {
        std::cout << "VIII";
    } if (c == 7) {
        std::cout << "VII";
    } if (c == 6) {
        std::cout << "VI";
    } if (c == 5){
        std::cout << "V";
    } if (c == 4) {
        std::cout << "IV";
    } if (c == 3) {
        std::cout << "III";
    } if (c == 2) {
        std::cout << "II";
    } if (c == 1) {
        std::cout << "I";
    }
    return EXIT_SUCCESS;
}
