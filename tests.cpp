#include <climits>
//
// Created by Изабелла Затикян on 23.10.2020.
//
#include "Shock_function.h"
#include "solver.h"
#include "PerfectStateGas.h"
#include "Reflection_function.h"
#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;


float gamma = 1.4;
float mol_mass = 0.029;


float left_pressure = 460.894;
float left_density = 5.99924;
float left_velocity = 19.5975;

float left_gas = PerfectStateGas.set_density(left_pressure, left_density, gamma, mol_mass);


float right_pressure = 46.0950;
float right_density = 5.9924;
float right_velocity = -6.19633;

float right_gas = PerfectStateGas.set_density(right_pressure, right_density, gamma, mol_mass);

printf(pressure_solve(InitialApproximationMean, left_gas, rigft_gas, left_velocity, right_velocity));

