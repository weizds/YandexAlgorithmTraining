#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

enum{
    END,
    BEGIN
};

int main()
{
    int n = 0;
    ifstream fin("input.txt");
    fin >> n;
    vector<pair<int, int>> events(n*2);
    for(int i = 0; i < n; ++i){
        int start, length;
        fin >> start >> length;
        events[i*2] = {start, BEGIN};
        events[i*2 + 1] = {start + length, END};
    }
    fin.close();
    
    sort(events.begin(), events.end());
    int count = 0;
    int max_count = 0;
    for(auto event : events){
        if(event.second == BEGIN){
            ++count;
            max_count = max(max_count, count);
        }else{
            --count;
        }
        
    }
    cout << max_count;
    return 0;
}