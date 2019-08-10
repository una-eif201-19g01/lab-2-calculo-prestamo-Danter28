//
// Created by Maikol Guzman  on 2019-08-08CalculoPrestamo::
//


#include <iostream>
#include "CalculoPrestamo.h"
//constructor default
CalculoPrestamo::CalculoPrestamo() {
    monto=0;
}
//constructor con parametros
CalculoPrestamo::CalculoPrestamo(int64_t monto) {
    this->monto=monto;
}
//convierte un porcentaje de tipo string a decimal
float CalculoPrestamo::obtenerPorcentaje(string porcentaje) {
    int posicion= porcentaje.find("%");//almacena la posicion del caracter buscado
    string subString =porcentaje.substr(0,posicion);//almacena una subcadena 
    return (stof(subString)/100);//regresa el porcentaje en modo decimal
    
}
//calcula el tiempo del prestamo en meses, si esta en anios lo pasa a meses
int CalculoPrestamo::calcularTiempoEnMeses(string tiempo) {
    string subString;
    int pos;
    //si es tiempo en anios lo pasa a meses
    if(tiempo.find("A")!=-1){//el -1 es debido a que si no encuentra lo que se busca retorna esto
        pos=tiempo.find("A");
        subString=tiempo.substr(0,pos);
        return ((stoi(subString))*12);
    }
    else{//como paso el filtro de anios entonces se calcula el tiempo en meses
        pos=tiempo.find("M");
        subString=tiempo.substr(0,pos);
        return (stoi(subString));
    }
    //en ambos casos retorna el tiempo en meses
}
//calcula el interes mensual a partir de la tasa anual y el balance actual
float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
    return (balance*(tasaAnual/12));
}
//provee el formato y la informacion para luego mostrar en pantalla
string CalculoPrestamo::reporteCalculoPrestamo(string tiempo, string porcentaje){
    int j=1;//variable contador
    int64_t balanceInicial=getMonto();
    //calcula el interes mensual con base en balance inicial y el porcentaje en modo decimal
    float interes=calcularInteresMensual(balanceInicial,(obtenerPorcentaje(porcentaje)));
    //crea un nuevo valor que es la suma del balance inicial y los intereses
    int64_t balanceNuevo=balanceInicial+interes;
    //obtiene el tiempo en meses para hacer la cuenta del ciclo
    int cantMeses= calcularTiempoEnMeses(tiempo);
    //da el formato necesario para mostrar en pantalla cada linea de informacion
    std::stringstream ss;
    ss<<"tasa ["<<porcentaje<<"], Mes ["<<j<<"], balance inicial ["<<
            balanceInicial<<"], interes ["<<interes<<"], balance nuevo ["<<
            balanceNuevo<<"]\n";    
    //ciclo que opera hasta llegar a la cantidad de meses descrita
    for(j;j<=cantMeses;j++){
        return ss.str();
        balanceInicial=balanceNuevo;
    }
        
    }
//obtiene el valor del monto
float CalculoPrestamo::getMonto(){return monto;}
//setea el valor del monto
void CalculoPrestamo::setMonto(float monto) {
    this->monto=monto;
}