#include <iostream>
#include "CalculoPrestamo.h"
using std::cin;
using std::cout;
int main() {
    CalculoPrestamo calc1(30000.000000);
    cout<<"Calcular prestamo:\n"<<calc1.reporteCalculoPrestamo("1A", 8.40%);
    
    
    
    cin.get();
    return 0;
}