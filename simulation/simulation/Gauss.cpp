//
//  Gauss.cpp
//  simulation
//
//  Created by Matek on 28.12.2017.
//  Copyright © 2017 Matek. All rights reserved.
//

#include "Gauss.hpp"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());

double Gauss::setHeading(double heading){
    if (heading > 360) heading -= 360;
    if (heading < 0) heading += 360;
    
    return heading;
}

double Gauss::GaussRandom(double mean, double n){
    std::normal_distribution <double> d(mean, n);
    
    return d(gen);
}

