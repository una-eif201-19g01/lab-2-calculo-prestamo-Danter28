//
// Created by Maikol Guzman  on 2019-08-08.
// 

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>
using std::string;
using std::find;
class CalculoPrestamo{
private:
    float monto;
    float obtenerPorcentaje(string );
    int calcularTiempoEnMeses(string);
    float calcularInteresMensual(float,float);
public:
    CalculoPrestamo();
    CalculoPrestamo(int64_t);
    string reporteCalculoPrestamo(string, string);
    float getMonto();
    void setMonto(float);
    
};
#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
