/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: CalculoPrestamo
 * 
 *        Created:  09/08/2019
 *
 *         Author:  Danilo Alvarado Arce
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */
#include <iostream>
#include "CalculoPrestamo.h"
using std::cin;
using std::cout;

int main() {
    //creacion del objeto
    CalculoPrestamo calc1(30000.000000);
    //imprime el reporte
    cout << "Calcular prestamo:\n" << calc1.reporteCalculoPrestamo("1A", "8.40%");



    cin.get();
    return 0;
}