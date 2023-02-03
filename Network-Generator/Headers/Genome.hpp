#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
#include <sstream>
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
    
    public:
    int k_in;
    
	int k_out; 
    //int counter = 0;
    int k_in_du;
    int k_out_du;
    int nm;
    int II;
    int UU;
    gene* gn;
    dupli* du;
    double** adjac;
    double** du_adjac;
    double Out_frac; // fraction of nodes which are output nodes
    double In_frac; // fraction of nodes which are input nodes
    double inputs;
    double WWW = 1;
    //double justifier;

 //+++++++++ FUNCTIONS+++++++//

    double gasdev(long*);
	double ran2 (long*);
    void Start(int );
    void base ();  //this function will set the first valuse and also builds the adjacency matrix and every gene in memory.
    void anses_network (); //initialzing the first three nodes all-to-all network
    void connect (int, int, double);
    void Prf_attch ();
    void duplication ();
    int police1 (int, int);
    int police2 (int, int);
    double weight_generator();
    void Save(int );
    void du_save(int);
    void distruction();
};
