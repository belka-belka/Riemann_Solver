//
// Created by Изабелла Затикян on 23.10.2020.
//

#include "solver.h"
#include <algorithm>

using namespace std;

//virtual float InitialApproximation::calc_initial_approximation(PerfectStateGas left_gas, PerfectStateGas right_gas, float left_velocity, float right_velocity);


float InitialApproximationMean:: calc_initial_approximation(PerfectStateGas left_gas, PerfectStateGas right_gas, float left_velocity, // Класс для вычисления начального приближения
                                     float right_velocity) {
        return 0.5 * (left_gas.pressure + right_gas.pressure);
    };

float calc_function(PerfectStateGas gas, float pressure){

    if (pressure > gas.pressure) {
    return derivative_shock_func(gas, pressure); }
    else{
    return derivative_reflection_func(gas, pressure);
    };
};

float calc_derivative(PerfectStateGas gas, float pressure) { //Вычисляет производную
    if (pressure > gas.pressure) {
        return derivative_shock_func(gas, pressure); }
     else {
        return derivative_reflection_func(gas, pressure);
    };
};
float pressure_solve(InitialApproximation initial_approximation, PerfectStateGas left_gas, PerfectStateGas right_gas, float left_velocity, float right_velocity, float tolerance = 1e-6){
    float pressure = initial_approximation.calc_initial_approximation(left_gas, right_gas, left_velocity, right_velocity);
    float error = 10;
    while (error > tolerance) {
        float delta_velocity = right_velocity - left_velocity;
        float function = calc_function(left_gas, pressure) + calc_function(right_gas, pressure) + delta_velocity;
        float derivative = calc_derivative(left_gas, pressure) + calc_derivative(right_gas, pressure);
        float delta = -function / derivative;
        float new_pressure = pressure + delta;
        error = abs(delta) / (abs(pressure) + abs(new_pressure));
        pressure = fmax(pressure + delta, 1e-6);
        return pressure;
    };
};

