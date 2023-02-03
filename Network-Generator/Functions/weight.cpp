#include "../Headers/Genome.hpp"
#include <complex>

double genome::weight_generator()
{  
    return gasdev(&iseed);
}
