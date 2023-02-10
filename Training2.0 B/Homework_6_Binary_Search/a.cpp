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
    vector<pair<int, int>> queries;
    
    ifstream fin("input.txt");
    int x;
    fin >> size;
    vec.resize(size);
    for(int i = 0; i < size; ++i)
        fin >> vec[i];
    fin >> queries_count;
    for(int i = 0; i < queries_count; ++i){
        int l,r;
        fin >> l >> r;
        queries.push_back({l, r});
    }
    fin.close();
    
    sort(vec.begin(), vec.end());

    for(auto q : queries){
        if(q.first > vec.back() || q.second < vec.front()){
            cout << "0 ";
            continue;
        }
        //cout << q.first << " " << q.second << "\n";
        int l = left_binary_search(vec, q.first);
        int r = right_binary_search(vec, q.second);
        //cout << l << " " << r << "\n";
        cout << r - l + 1 << "\n";
    }
    return 0;
}