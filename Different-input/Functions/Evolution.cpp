#include "../Headers/Genome.hpp"


bool genome::Evolution(double evolve)
{
    counter = 0;   
    selected_node = input[0];
    gn[selected_node].weights = evolve; //setting the input value as the activation of the input node.
    
    for (int i=0 ; i<gn[selected_node].nghbrs.size() ; i++) //process of propogating through the network.
    {
        int node2 = gn[selected_node].nghbrs[i];
        double VV = 0;   
        for (int GH=0 ; GH < gn[node2].Connected.size(); GH++)
        {
            int gh = gn[node2].Connected[GH];
            VV += double(gn[gh].weights * adjac[gh][node2]);
        }

        gn[node2].weights = The_Function(VV); //the specific function that updates the activation of the node, could be tanh, linear, ...
        updater (node2); // this function is recursive.
    }

    if (counter < crazyness_counter)
    {
        return true;
    }
    
    else
    {
        return false;
    } 
}

void genome::updater (int nodex)
{   
    counter ++;
    if (counter < crazyness_counter)
    {
        for (int i=0 ; i<gn[nodex].nghbrs.size() ; i++)
        {   
            double values = 0;
            int node4 = gn[nodex].nghbrs[i];
            for (int GH=0 ; GH < gn[node4].Connected.size(); GH++)
            {
                int gh = gn[node4].Connected[GH];
                values += double(gn[gh].weights * adjac[gh][node4]);
            }

            gn[node4].weights = The_Function(values);
            updater (node4);
        }
    }
}
