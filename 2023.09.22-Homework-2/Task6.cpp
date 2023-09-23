#include <iostream>

int main ( int argc , char * )
{
    int k = 0;
    int m = 0;
    int n = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    int T = 0;
    int r = 2*n/k;
    if ( n <= k) {
            T = m * 2;
    } else if ( n*2 % k == 0){
        T=r*m;
    } else {
        T = (r + 1)*m;
    }
    std::cout << T;
    return  EXIT_SUCCESS;
}
