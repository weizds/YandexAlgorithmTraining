#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int n = 0;
    int m = 0;
    fin >> n >> m;
    map<int, int> points_sum;
    for(int i = 0; i < n; ++i){
        int point;
        fin >> point;
        points_sum[point] += 1;
    }
    vector<pair<int, int>> segments(m);
    for(int i = 0; i < m; ++i){
        int left, right;
        fin >> left >> right;
        segments[i] = {left, right};
    }
    fin.close();

    int prev_sum = 0;
    for(auto it = points_sum.begin(); it != points_sum.end(); ++it){
        it->second += prev_sum;
        prev_sum = it->second;
    }

    for(auto seg : segments) {
        auto it_from = points_sum.lower_bound(seg.first);
        auto it_to = points_sum.lower_bound(seg.second);
        int count_from = 0;
        if(it_from != points_sum.begin())
            count_from = (--it_from)->second;
        if(it_to->first != seg.second && it_to != points_sum.begin())
            --it_to;
        cout << it_to->second - count_from << " ";
    }
    return 0;
}