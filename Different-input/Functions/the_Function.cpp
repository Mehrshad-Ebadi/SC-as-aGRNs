#include "../Headers/Genome.hpp"

double genome::The_Function(double kapa)
{  
   return tanh(kapa); //the activation function is tanh.
   //return kapa;     //for the linear activation function, without limitaion (since tanh has a max value of 1, and min of -1)
}