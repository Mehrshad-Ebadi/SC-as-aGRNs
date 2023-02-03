#include "../Headers/Genome.hpp"

void genome::Save(int QW) // saving the single network to a txt file, QW would be the number of networks
{
    char ss [5000];

    sprintf(ss,"./Results/Net_%d.txt", QW);
    ofstream sve (ss);

    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            sve<<adjac[i][j]<<'\t';
        }

        sve<<'\n';
    }
}

void genome::du_save(int QW)    // saving the duplicated network to a txt file, QW would be the number of networks
{
    char ss [5000];

    sprintf(ss,"./Results_du/Net_du_%d.txt", QW);
    ofstream sve (ss);

    for (int i=0 ; i<nn ; i++)
    {
        for (int j=0 ; j<nn ; j++)
        {
            sve<<du_adjac[i][j]<<'\t';
        }

        sve<<'\n';
    }
}