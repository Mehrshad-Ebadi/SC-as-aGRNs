#include "../Headers/Genome.hpp"

double genome::Ftnssfu(double KAPA)
{
    double RR =(1 - abs(KAPA)); //the linear performance function ...
    if (RR < 0)
        RR = 0; //to prevent network from reaching negative performance values, performance values less than zero would be zero as well.
    return RR; 
}