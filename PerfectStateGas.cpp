//
// Created by Изабелла Затикян on 23.10.2020.
//
#include <iostream>
#include <cmath>
#include "PerfectStateGas.h"

    //float pressure, temperature,  mol_mass, density;


float PerfectStateGas::set_density(float, float, float){

        return mol_mass * pressure / 8.314 / temperature;
    };

    float PerfectStateGas::set_temperature(float, float, float, float){

        return pressure / density * mol_mass / 8.314;
    };

    float PerfectStateGas::set_cv(float, float){ // Возвращает удельную теплоемкость при постоянном объеме в Дж / кг / K

        return 8.314 / (gamma - 1) / mol_mass;
    };

    float PerfectStateGas::set_cp(float, float){ // Возвращает удельную теплоемкость при постоянном давлении ДЖ / кг / K

        return 8.314 * gamma / (gamma - 1) / mol_mass;
    };

    float PerfectStateGas::set_sound_speed(float, float, float){ //Возвращает скорость звука м / с

        return sqrt(gamma * 8.314 * temperature / mol_mass);
    };

    float PerfectStateGas::internal_energy(float){ //Возвращает удельную внутреннюю энергию газа Дж / кг

        return this -> set_cv(gamma, mol_mass) * temperature;
    };
    float PerfectStateGas::enthalpy(float){ //Возвращает удельную энтальпию газа Дж / кг

        return this -> set_cp(gamma, mol_mass) * temperature;
    };
