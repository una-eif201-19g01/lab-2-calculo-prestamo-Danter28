/*
 * =====================================================================================
 *
 *       Filename:  CalculoPrestamo.cpp
 *
 *    Description:  Class that implements the functions
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

CalculoPrestamo::CalculoPrestamo() {
    monto = 0;
}

CalculoPrestamo::CalculoPrestamo(int64_t monto) {
    this->monto = monto;
}

float CalculoPrestamo::obtenerPorcentaje(string porcentaje) {
    int posicion = porcentaje.find("%");
    string subString = porcentaje.substr(0, posicion);
    return (stof(subString) / 100);

}

int CalculoPrestamo::calcularTiempoEnMeses(string tiempo) {
    string subString;
    int pos;
    if (tiempo.find("A") != -1) {
        pos = tiempo.find("A");
        subString = tiempo.substr(0, pos);
        return ((stoi(subString))*12);
    } else {
        pos = tiempo.find("M");
        subString = tiempo.substr(0, pos);
        return (stoi(subString));
    }
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
    return (balance * (tasaAnual / 12));
}

string CalculoPrestamo::reporteCalculoPrestamo(string tiempo, string porcentaje) {
    int contador = 1;
    int64_t balanceInicial = getMonto();
    float interes = calcularInteresMensual(balanceInicial, (obtenerPorcentaje(porcentaje)));
    int64_t balanceNuevo = balanceInicial + interes;
    int cantMeses = calcularTiempoEnMeses(tiempo);
    string tasaTexto;

    for (contador; contador <= cantMeses; contador++) {
        tasaTexto = tasaTexto + "tasa [" + porcentaje + "], Mes [" + std::to_string (contador) + "], balance inicial [" +
                std::to_string(balanceInicial) + "], interes [" + std::to_string(interes) + "], balance nuevo [" +
                std::to_string (balanceNuevo) + "]\n";
        return tasaTexto;
        balanceInicial = balanceNuevo;
    }

}

float CalculoPrestamo::getMonto() {
    return monto;
}

void CalculoPrestamo::setMonto(float monto) {
    this->monto = monto;
}