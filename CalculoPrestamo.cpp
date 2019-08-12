//
// Creado por Danilo Alvarado Arce 09/08/2019
// 


#include <iostream>
#include "CalculoPrestamo.h"
//constructor default

CalculoPrestamo::CalculoPrestamo() {
    monto = 0;
}
//constructor con parametros

CalculoPrestamo::CalculoPrestamo(int64_t monto) {
    this->monto = monto;
}
//convierte un porcentaje de tipo string a decimal

float CalculoPrestamo::obtenerPorcentaje(string porcentaje) {
    int posicion = porcentaje.find("%");
    string subString = porcentaje.substr(0, posicion);
    return (stof(subString) / 100);

}
//calcula el tiempo del prestamo en meses, si esta en anios lo pasa a meses

int CalculoPrestamo::calcularTiempoEnMeses(string tiempo) {
    string subString;
    int pos;
    if (tiempo.find("A") != -1) {
        pos = tiempo.find("A");
        subString = tiempo.substr(0, pos);
        return ((stoi(subString))*12);
    }
    else {
        pos = tiempo.find("M");
        subString = tiempo.substr(0, pos);
        return (stoi(subString));
    }
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
    return (balance * (tasaAnual / 12));
}
//provee el formato y la informacion para luego mostrar en pantalla

string CalculoPrestamo::reporteCalculoPrestamo(string tiempo, string porcentaje) {
    int contador = 1; 
    int64_t balanceInicial = getMonto();
    float interes = calcularInteresMensual(balanceInicial, (obtenerPorcentaje(porcentaje)));
    int64_t balanceNuevo = balanceInicial + interes;
    int cantMeses = calcularTiempoEnMeses(tiempo);
    string tasaTexto;

    //ciclo que opera hasta llegar a la cantidad de meses descrita
    for (contador; contador <= cantMeses; contador++) {
        tasaTexto = "tasa [" + porcentaje + "], Mes [" + contador + "], balance inicial [" +
                balanceInicial + "], interes [" + interes + "], balance nuevo [" +
                balanceNuevo + "]\n";
        return tasaTexto;
        balanceInicial = balanceNuevo;
    }

}
//obtiene el valor del monto

float CalculoPrestamo::getMonto() {
    return monto;
}
//setea el valor del monto

void CalculoPrestamo::setMonto(float monto) {
    this->monto = monto;
}