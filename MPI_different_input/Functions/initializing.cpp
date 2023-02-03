#include "../Headers/Genome.hpp"

void genome::Initializing()
{
    for (int j=0 ; j<n ; j++)
    {
        for (int k=0 ; k<n ; k++)
        {
            if ( adjac[j][k] != 0 )
            {
                //double JK = Weight_generator();   
                connect (j, k, adjac[j][k]);
            }
        }
    }

}