#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int m = 0;
    fin >> m;
    vector<pair<int, int>> segments;
    int left, right;
    while(fin >> left >> right){
        if(right > 0 && left < m)
            segments.push_back({left, right});
    }
    fin.close();
    
    sort(segments.begin(), segments.end());
    int target = 0;
    int next_target = 0;
    pair<int, int> current_best{0, 0};
    vector<pair<int, int>> res;
    for(auto seg : segments){
        if(seg.first > target){
            res.push_back(current_best);
            target = next_target;
            if(target >= m)
                break;
        }
        if(seg.first <= target && seg.second > next_target){
            next_target = seg.second;
            current_best = seg;
        }
    }
    
    if(target < m){
        res.push_back(current_best);
        target = next_target;
    }
    if(target < m){
       cout << "No solution\n";
    }else{
        cout << res.size() << "\n";
        for(auto a : res)
            cout << a.first << " " << a.second << "\n";
    }
    return 0;
}