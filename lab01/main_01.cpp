#include <iostream>
#include "functions.h"
#include <cstring>



int main() {
    for (int i = 1; i <= 127; ++i) {
        std::cout<< countBits(i)<< std::endl;

    }

    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            std::cout<<i<<" ---> " << n <<std::endl;
        }else{
            std::cout<<"Impossible operation!" << std::endl;
        }
    }

    double numbers[] = {2.0, 4.0, 6.0, 8.0, 10.0};
    std::cout << mean(numbers, 5) << std::endl;


}
