#include <iostream>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <ctime>
#include "./Gene.hpp"
#include "./duplicated.hpp"

class genome
{
    private:
    int n;
    int nn;
    long int iseed;
    int selected_node;

    public:
    int counter;
    gene* gn;
    dupli* du;
    double** adjac;
    double** du_adjac;
    double xx;
    double XX;
    int * output;
    int * input;
    int * du_output;
    int * du_input;
    int II;
    int UU;
    int du_II;
    int du_UU;
    int step;
    int crazyness_counter;
    int du_crazyness_counter;

 //+++++++++ FUNCTIONS+++++++//

    double gasdev(long*);
	double ran2 (long*);
    void base (int);  //this function will set the first valuse and also builds the adjacency matrix and every gene in memory.
    void connect (int, int, double);
    void du_connect (int, int, double);
    bool checker (string);

    void Reader(string);
    void Initializing();
    void specefication();
    void duplication ();
    bool Evolution(double);
    bool evo_dup(double);
    void updater (int);
    void du_updater(int);
    double parameters();
    double du_parameters();
    double Weight_generator();
    void Remover();
    void Network_Deleter();
    double The_Function (double);
    
    double phase()    
    {
        return gn[output[0]].weights;
    }
    double phase2()
    {
        return gn[output[1]].weights;
    }
    double du_phase()    
    {
        return ((du[du_output[0]].weights + du[du_output[0 + UU]].weights) / 2.0);
    }
    double du_phase2()
    {
        return ((du[du_output[1 + UU]].weights + (du[du_output[1]].weights)) / 2.0);
    }

};
