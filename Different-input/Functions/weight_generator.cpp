#include "../Headers/Genome.hpp"
double genome::Weight_generator()
{
    return gasdev(&iseed);
}