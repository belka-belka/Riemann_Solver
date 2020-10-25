//
// Created by Изабелла Затикян on 23.10.2020.
//
#include<iostream>
#include <cmath>
#include "PerfectStateGas.h"
#include "Shock_function.h"

using namespace std;

float calc_a(PerfectStateGas gas){ // Считает коэффициент А

    return 2 / (gas.gamma + 1) / gas.set_density(gas.mol_mass, gas.pressure, gas.temperature);
};

float calc_b(PerfectStateGas gas){ // Считает коэффициент B

    return (gas.gamma - 1) / (gas.gamma + 1) * gas.pressure;
};

float shock_func(PerfectStateGas gas, float pressure){ // Функция, считающая функцию для ударной волны

    return (pressure - gas.pressure) * sqrtf(calc_a(gas) / (calc_b(gas) + pressure));
};

float derivative_shock_func(PerfectStateGas gas, float pressure){ //Производная функция дял ударной волны

    float b_coef_plas_p = calc_b(gas) + pressure;

    return sqrtf(calc_a(gas) / b_coef_plas_p) * (1 - (pressure - gas.pressure) / 2 / b_coef_plas_p);
};
