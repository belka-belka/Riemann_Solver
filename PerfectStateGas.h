//
// Created by Изабелла Затикян on 23.10.2020.
//.

#ifndef PerfectGasState_H
#define PerfectGasState_H

class PerfectStateGas{ //Класс состояния одномерного идеального газа
public:
    float pressure, temperature,  gamma,  mol_mass, density;

    float set_density(float, float, float);

    float set_temperature(float, float, float, float);

    float set_cv(float, float); // Возвращает удельную теплоемкость при постоянном объеме в Дж / кг / K

    float set_cp(float, float); // Возвращает удельную теплоемкость при постоянном давлении ДЖ / кг / K

    float set_sound_speed(float, float, float); //Возвращает скорость звука м / с

    float internal_energy(float); //Возвращает удельную внутреннюю энергию газа Дж / кг

    float enthalpy(float); //Возвращает удельную энтальпию газа Дж / кг

};

#endif //PERFECTSTATEGAS_H