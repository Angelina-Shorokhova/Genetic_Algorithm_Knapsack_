#include "Parser.h"
#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
using namespace std;

class Solver: public  Parser{
    public:
    int competition(int q,int x,int y,vector<vector<int>> t);
    
    Solver(string f_name);
};