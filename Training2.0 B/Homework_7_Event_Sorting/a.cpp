#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int n = 0;
    fin >> n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; ++i){
        int left, right;
        fin >> left >> right;
        vec[i] = {left, right};
    }
    fin.close();
    
    sort(vec.begin(), vec.end());
    vector<pair<int, int>> res;
    res.push_back(vec.front());
    for(int i = 1; i < n; ++i){
        if(vec[i].first > res.back().second){
            res.push_back(vec[i]);
        }else{
            if(vec[i].second > res.back().second)
                res.back().second = vec[i].second;
        }
    }
    int sum_length = 0;
    for(auto p : res)
        sum_length += p.second - p.first;
    cout << sum_length;
    return 0;
}