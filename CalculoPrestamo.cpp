//
// Created by Maikol Guzman  on 2019-08-08CalculoPrestamo::
//

#include <iostream>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo() {
}

CalculoPrestamo::CalculoPrestamo(int64_t monto) {
    this->monto=monto;
}

float CalculoPrestamo::obtenerPorcentaje(string porcentaje) {
}

int CalculoPrestamo::calcularTiempoEnMeses(string tiempo) {
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
}

string CalculoPrestamo::reporteCalculoPrestamo(string tiempo, string porcentaje) {
}

float CalculoPrestamo::getMonto(){return monto;}

void CalculoPrestamo::setMonto(float monto) {
    this->monto=monto;
}