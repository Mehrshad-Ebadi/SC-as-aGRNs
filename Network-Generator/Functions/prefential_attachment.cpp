#include "../Headers/Genome.hpp"

void genome::Prf_attch() // The mean-degree is 2 in this network:
{
    double weight;
    UU = n-2;
    for (int i=3 ; i<UU ; i++)
    {
        int current_degree = 0;
        while (current_degree < 1)
        {
            int j = ran2(&iseed) * (i);
            double pf = (double(gn[j].dg_out + gn[j].dg_in) / (k_in + k_out));
            double chance = ran2(&iseed);
            if (pf >= chance && adjac[j][i] == 0 && adjac[i][j] == 0 && i != j)
            {
                current_degree = 1;
                int boz = 0;
                weight = weight_generator();
                connect (i, j, weight);

                if (gn[j].nghbrs.size() > 0)
                {
                    while (boz < 1)
                    {
                        int GG = ran2(&iseed) * gn[j].nghbrs.size();
                        GG = gn[j].nghbrs[GG];

                        if (GG != i && GG != j)
                        {  
                            weight = weight_generator();  
                            connect (i, GG, weight);
                            boz ++ ;
                        }
                    }
                }
                else
                {
                    while (boz < 1)
                    {
                        int GG = ran2(&iseed) * gn[j].connect.size(); // assigning the weight of edges value, this is temprory and could be change everytime that is needed!
                        GG = gn[j].connect[GG];

                        if (GG != i && GG != j)
                        {    
                            weight = weight_generator();
                            connect (GG, i, weight);
                            boz ++ ;
                        }
                    }                    
                }
            }             
        }
    }


    for (int i=UU ; i<n ; i++) //for the output nodes
    {
        int current_degree = 0;
        while (current_degree < 2)
        {
            int j = ran2(&iseed) * (UU);
            double pf = (double(gn[j].dg_out + gn[j].dg_in) / (k_in + k_out));
            double chance = ran2(&iseed);
            if (pf >= chance && adjac[j][i] == 0 && adjac[i][j] == 0 && i != j)
            {
                current_degree ++;
                weight = weight_generator();
                connect (j, i, weight);
            }             
        }        
    }


    if (gn[2].dg_out == 0) //checking node 2, if it is not connected to other nodes, if yes, then it will be connected to one of the output node. 
                           //This condition only exist to make sure we only have 2 output nodes, since sometime node 2 becomes the third output node.
    {
        weight = weight_generator();
        connect (2, n-1, weight);
    }

    vector <int> temperory;
    for (int i=0 ; i<n ; i++)
    {
        if (gn[i].dg_in == 0)
        {
            temperory.push_back(i);
        }
    }

    if (temperory.size() > 2)   //controlling the number of input node, limiting it to 2-4. Sometimes it can reach zero input nodes, which then the network will be removed in the future steps.
    {
        for (int i=3 ; i<temperory.size() ; i++)
        {
            int INPUT = ran2(&iseed) * 2;
            weight = weight_generator();
            connect (temperory[INPUT], temperory[i], weight);
        }
    }

    temperory.clear();
    temperory.shrink_to_fit();

}
