/*
 * =====================================================================================
 *
 *       Filename:  CalculoPrestamo.h
 *
 *    Description:  Header to define the template of CalculoPrestamo.
 *
 *        Created:  09/08/2019
 *
 *         Author:  Danilo Alvarado Arce
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */

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
    /**
     * Transforms an string version of the percentaje into a decimal figure.
     * 
     * @param receives a string to be transformed.
     * @return decimal version of the string.
     */
    float obtenerPorcentaje(string);
    /**
     * Transforms a string containing the desired time into months
     * 
     * @param receives a string to be transformed.
     * @return the amount of months into an integer form.
     */
    int calcularTiempoEnMeses(string);

    /**
     * Calculates monthly interest over an annual rate.
     * 
     * @param receibes the balance amount and the annual rate.
     * @return monthly interest in a decimal figure.
     */
    float calcularInteresMensual(float, float);
public:
    /**
     * Constructs a CalculoPrestamo type object by default
     * 
     * @param none
     * @return none
     */
    CalculoPrestamo();
    /**
     * Constructs a CalculoPrestamo type object with parameters
     * 
     * @param receives monto as a 64b integer parameter
     * @return none
     */
    CalculoPrestamo(int64_t);
    /**
     * Creates a string with the required information and later show it on screen
     * 
     * @param receives a string type amount and annual rate.
     * @return string containing the information of the loan information 
     * on the disered format.
     */
    string reporteCalculoPrestamo(string, string);
    /**
     * Gets the monto value.
     * 
     * @param none.
     * @return float type value of monto.
     */
    float getMonto();
    /**
     * Sets the monto value.
     * 
     * @param float type value of monto.
     * @return none.
     */
    void setMonto(float);

};
#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
