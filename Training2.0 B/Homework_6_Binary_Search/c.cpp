#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

double calc(double x, const vector<int> &params) {
    if(params.size() < 4)
        return 0.0;
    return x*x*x*params[0] + x*x*params[1] + x*params[2] + params[3];
}

bool check(double x, const vector<int> &params) {
    if(params[0] > 0)
        return calc(x, params) > 0;
    else
        return calc(x, params) < 0;
}

double binary_search(double l, double r, double eps, const vector<int> &params) {
    while(l + eps < r){
        double m = (r + l) / 2;
        if(check(m, params))
            r = m;
        else
            l = m;
    }
    return l;
}

int main() {
    ifstream fin("cubroot.in");
    vector<int> params(4);
    fin >> params[0] >> params[1] >> params[2] >> params[3];
    fin.close();
    
    cout.precision(10);
    auto x = binary_search(-1001, 1001, 1e-6, params);
    cout << x << "\n";
    return 0;
}