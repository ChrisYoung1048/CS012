#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);


//selection sort and swap function
//make sure function can handle an empty vector
//cannot compare floating values is to subtract one from each other and get the absolute
//make sure the the absolute difference is < .001