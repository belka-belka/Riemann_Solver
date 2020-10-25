//
// Created by Изабелла Затикян on 23.10.2020.
//

#ifndef SHOCK_FUNCTION_H
#define SHOCK_FUNCTION_H
#include<iostream>
#include <cmath>
#include "PerfectStateGas.h"
#include "Shock_function.h"

using namespace std;

float calc_a(PerfectStateGas gas); // Считает коэффициент А

float calc_b(PerfectStateGas gas); // Считает коэффициент B

float shock_func(PerfectStateGas gas, float pressure); // Функция, считающая функцию для ударной волны

float derivative_shock_func(PerfectStateGas gas, float pressure); //Производная функция дял ударной волны


#endif //SHOCK_FUNCTION_H
