#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    int n = 0;
    fin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
        fin >> vec[i];
    fin.close();
    
    for(int i = 1; i < n; ++i){
        if(vec[i] < vec[i - 1]){
            cout << "-1";
            return 0;
        }
    }
    cout << vec.back() - vec.front();
    return 0;
}
