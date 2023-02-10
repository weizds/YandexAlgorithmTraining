#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Event{
    int min;
    int id;
    char status;
};

bool eventCompare(const Event &e1, const Event &e2){
    if(e1.id == e2.id)
        return e1.status < e2.status;
    return e1.id < e2.id;
}

int main() {
    int n = 0;
    vector<Event> events;
    
    ifstream fin("input.txt");
    string line;
    fin >> n;
    while(getline(fin, line)){
        istringstream iss(line);
        vector<string> line_split;
        string word;
        while(getline(iss, word, ' ')){
            line_split.push_back(word);
        }
        if(line_split.size() >= 5)
        events.push_back({stoi(line_split[0]) * 24 * 60 + stoi(line_split[1]) * 60 + stoi(line_split[2]), 
        stoi(line_split[3]), line_split[4][0]});
    }
    fin.close();
    
    sort(events.begin(), events.end(), eventCompare);
    
    map<int, int> total_time;
    int start_time = 0;
    for(auto e : events){
        cout << e.id << " " << e.min << " " << e.status << "\n";
        if(e.status == 'A')
            start_time = e.min;
        if(e.status == 'C' || e.status == 'S'){
            int end_time = e.min;
            if(end_time < start_time)
                start_time -= 365*24*60;
            total_time[e.id] += end_time - start_time;
        }
    }
    cout << "\n";
    for(auto rocket : total_time){
        cout << rocket.first << " " << rocket.second << "\n";
    }

    return 0;
}
