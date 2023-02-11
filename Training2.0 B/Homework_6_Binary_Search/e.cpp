#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int> &points, int len, int k){
    int count = 0;
    int right = points.front() - 1;
    for(auto point : points){
        if(point > right){
            count++;
            right = point + len;
        }
    }
    return count <= k;
}

int main() {
    ifstream fin("input.txt");
    int n = 0;
    int k = 0;
    fin >> n >> k;
    vector<int> points(n);
    for(int i = 0; i < n; ++i){
        fin >> points[i];
    }
    fin.close();

    sort(points.begin(), points.end());
    
    int left = 0;
    int right = points.back() - points.front();
    int count = 0;
    while(left < right){
        int mid = ((long long)left + right) / 2;
        if(check(points, mid, k))
            right = mid;
        else
            left = mid + 1;
        if(count++ > 100)
            break;
    }
    cout << left;
    return 0;
}