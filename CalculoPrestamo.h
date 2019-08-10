//
// Creado por Danilo Alvarado Arce 09/08/2019
// 

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>
#include <sstream>
using std::string;
using std::find;

class CalculoPrestamo {
private:
    float monto;
    //metodos privados
    float obtenerPorcentaje(string);
    int calcularTiempoEnMeses(string);
    float calcularInteresMensual(float, float);
public:
    //metodos publicos
    CalculoPrestamo();
    CalculoPrestamo(int64_t);
    string reporteCalculoPrestamo(string, string);
    float getMonto();
    void setMonto(float);

};
#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
