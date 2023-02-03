#include "../Headers/Genome.hpp"

void genome::Reader(string location)
{
    ifstream NetWork (location);

    for (int j=0 ; j<n ; j++)
    {
        for (int k=0 ; k<n ; k++)
        {
            NetWork>>adjac[j][k];
        }
    }
}
