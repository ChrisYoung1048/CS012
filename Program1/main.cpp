#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);
void outVector(vector<double>, vector<double>);

int main(int argc, char *argv[]) {
    vector<double> vectorAngle;
    vector<double> vectorCoefficient;
    double inputAngle;
    string inputMenu;

    readData(argv[1],vectorAngle, vectorCoefficient);
    reorder(vectorAngle, vectorCoefficient);
    while (vectorAngle.size() > 0) {
        cout << "Enter flight-path angle: ";
        cin >> inputAngle; 
        cout << "Coefficient of Lift: " << interpolation(inputAngle, vectorAngle, vectorCoefficient) << endl;
        cout << "Do you want to enter another flight-path angle? (yes/no)" << endl;
        cin >> inputMenu;
        if (inputMenu.compare("No") == 0)
            break;
    }
    return 0;
}

void readData(const string &filename, vector<double> &v1, vector<double> &v2) {
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cout << "Error opening " << filename << endl;
    }
    double num1, num2;
    while (fin >> num1 >> num2) {
        v1.push_back(num1);
        v2.push_back(num2);
    }
}

double interpolation(double inputAngle, const vector<double> &v1, const vector<double> &v2) {
    for (unsigned int i = 0; i < v1.size()-1; ++i) {
        //if(v1.size() == 0)
        //    return 0.0;
        if (inputAngle > v1[i] && inputAngle < v1[i+1])
            return v2[i] + ((inputAngle - v1[i])/(v1[i+1] - v1[i])) * (v2[i+1] - v2[i]);
    }
    for (unsigned int i = 0; i < v1.size(); ++i) {
        if (inputAngle == v1[i])
            return v2[i];
    }
    return 0;
}

bool isOrdered(const vector<double> &v) {
    for (unsigned int i = 0; i < v.size()-1; ++i) {
        if(v.size() == 0 || v.size() == 1)
            return true;
        if (v[i] > v[i+1])
            return false; 
    }
    return true;
}

void reorder(vector<double> &v1, vector<double> &v2) {
    for (unsigned int i = 0; i < v1.size()-1; ++i) {
        if(v1.size() == 0)
            break;
        for (unsigned int j = i+1; j < v1.size(); ++j) {
            if (v1[j] < v1[i]) {
                swap(v1[i],v1[j]);
                swap(v2[i],v2[j]);
            }
        }
    }
}

void outVector(vector<double> v1, vector<double> v2) {
    for (unsigned int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " " << v2[i] << endl;
    }
}


//selection sort and swap function
//make sure function can handle an empty vector
//cannot compare floating values is to subtract one from each other and get the absolute
//make sure the the absolute difference is < .001