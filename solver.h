//
// Created by Изабелла Затикян on 23.10.2020.
//

#ifndef RIEMMAN_SOLVER_H
#define RIEMMAN_SOLVER_H
#include <iostream>
#include "PerfectStateGas.h"
#include "Reflection_function.h"
#include "Shock_function.h"

using namespace std;

class InitialApproximation { // Класс для вычисления начального приближения
public:
    virtual float calc_initial_approximation(PerfectStateGas left_gas, PerfectStateGas right_gas, float left_velocity, float right_velocity);
};

class InitialApproximationMean: public InitialApproximation { // Считает начальное приближение средним арифметическм
public:
    float calc_initial_approximation(PerfectStateGas left_gas, PerfectStateGas right_gas, float left_velocity, // Класс для вычисления начального приближения
                                     float right_velocity);
};







#endif //RIEMMAN_SOLVER1_H
