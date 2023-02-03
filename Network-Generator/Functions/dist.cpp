#include "../Headers/Genome.hpp"

void genome::distruction()
{
    for (int i=0 ; i<n ; i++)
    {
            delete [] adjac[i];
    }

    delete [] adjac;
}