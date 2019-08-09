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
    int posicion= porcentaje.find(%);
    string subString =porcentaje.substr(0,posicion);
    return (stof(subString)/100);
    
}

int CalculoPrestamo::calcularTiempoEnMeses(string tiempo) {
    string subString;
    int pos;
    if(tiempo.find("A")!=-1){
        pos=tiempo.find("A");
        subString=tiempo.substr(0,pos);
        return ((stoi(subString))*12);
    }
    else{
        pos=tiempo.find("M");
        subString=tiempo.substr(0,pos);
        return (stoi(subString));
    }
        
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
    return (balance*(tasaAnual/12));
}

string CalculoPrestamo::reporteCalculoPrestamo(string tiempo, string porcentaje){
    
}

float CalculoPrestamo::getMonto(){return monto;}

void CalculoPrestamo::setMonto(float monto) {
    this->monto=monto;
}