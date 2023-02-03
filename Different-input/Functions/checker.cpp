#include "../Headers/Genome.hpp"

bool genome::checker(string mahal)
{
    ifstream NetWork (mahal);

    if (NetWork.good())
    {
        return true;
    }
    else 
    {
        return false;
    }
}
