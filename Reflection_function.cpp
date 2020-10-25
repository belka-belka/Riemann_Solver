//
// Created by Изабелла Затикян on 23.10.2020.
//

#include "Reflection_function.h"
#include <iostream>
#include "PerfectStateGas.h"
#include <cmath>
// Файл с функциями для волны разрежения
using namespace std;

float reflection_func(PerfectStateGas gas, float pressure){ //Рассчитывает функцию для волны разрежения

    float power = (gas.gamma -1) / 2 / gas.gamma;

    return 2 * gas.set_sound_speed(gas.gamma, gas.temperature, gas.mol_mass) / (gas.gamma - 1 ) * (pow((pressure / gas.pressure), power -1));
};

float derivative_reflection_func(PerfectStateGas gas, float pressure){ //Вовзращает производную от функции для волны разрежения

    float power = -(gas.gamma + 1) / 2 / gas.gamma;

    return pow((pressure / gas.pressure),power) / gas.set_sound_speed(gas.gamma, gas.temperature, gas.mol_mass) / gas.set_density(gas.mol_mass, gas.pressure, gas.temperature);

};
