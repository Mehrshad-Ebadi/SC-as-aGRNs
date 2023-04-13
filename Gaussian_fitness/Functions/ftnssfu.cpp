#include "../Headers/Genome.hpp"

double genome::Ftnssfu(double KAPA)
{
    double RR = (1/(Sigma * 2.5066)) * exp(-(((KAPA - Miuw) * (KAPA - Miuw)) / (2 * Sigma * Sigma)));
    return RR; 
}