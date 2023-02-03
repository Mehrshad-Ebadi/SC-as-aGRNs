#include "../Headers/Genome.hpp"

void genome::duplication() // duplicating the generated network
{

    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (adjac [i][j] != 0)
            {
                double Wgh = adjac[i][j];
                du_adjac [i][j] = Wgh;
                du_adjac [i][j+n] = Wgh;
                du_adjac [i+n][j] = Wgh;
                du_adjac [i+n][j+n] = Wgh;
            }
        }
    }

}