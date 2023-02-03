#include <vector>
#include <string>
using namespace std;

class gene
{
    public:
    int dg_in, dg_out;
    double weights;
    //double decay;
    bool up;
    bool off_check;
    //string Ag;
    vector <int> nghbrs;
    vector <int> connect;

    gene () {

    }

    ~gene (){

    }


};