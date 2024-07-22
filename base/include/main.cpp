#include "Types.h"
#include <iostream>
int main() {
    int x = 10;
    double y = zero::implicit_cast<double>(x);
    std::cout<<"sizeof(y):"<<sizeof(y)<<"\n";
    return 0;
}