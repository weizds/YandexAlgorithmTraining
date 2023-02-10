#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int left_binary_search(const vector<int> &vec, int target) {
    int l = 0;
    int r = vec.size() - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(vec[m] < target)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int right_binary_search(const vector<int> &vec, int target) {
    int l = 0;
    int r = vec.size() - 1;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(vec[m] > target)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

int main() {
    int size = 0;
    vector<int> vec;
    int queries_count = 0;
    vector<int> queries;
    
    ifstream fin("input.txt");
    int x;
    fin >> size;
    vec.resize(size);
    for(int i = 0; i < size; ++i)
        fin >> vec[i];
    fin >> queries_count;
    queries.resize(queries_count);
    for(int i = 0; i < queries_count; ++i)
        fin >> queries[i];
    fin.close();

    for(auto q : queries){
        if(q > vec.back() || q < vec.front()){
            cout << "0 0\n";
            continue;
        }
        int l = left_binary_search(vec, q);
        int r = right_binary_search(vec, q);
        if(l > r)
            cout << "0 0\n";
        else
            cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}