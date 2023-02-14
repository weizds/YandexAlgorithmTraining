#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

list<string> getPath(const unordered_map<string, string> &tree, const string &person){
    list<string> res;
    string current = person;
    while(tree.find(current) != tree.end()){
        res.push_front(current);
        current = tree.find(current)->second;
    }
    res.push_front(current);
    return res;
}

int main() {
    unordered_map<string, string> tree;
    ifstream fin("input.txt");
    string line;
    int n = 0;
    fin >> n;
    vector<pair<string, string>> queries;
    for(int i = 0; i < n; ++i){
        getline(fin, line);
        istringstream iss(line);
        vector<string> line_split;
        string word;
        while(getline(iss, word, ' ')){
            line_split.push_back(word);
        }
        if(line_split.size() >= 2)
            tree[line_split[0]] = line_split[1];
    }
    int count = 0;
    while(getline(fin, line)){
        istringstream iss(line);
        vector<string> line_split;
        string word;
        while(getline(iss, word, ' ')){
            line_split.push_back(word);
        }
        if(line_split.size() >= 2)
            queries.push_back({line_split[0], line_split[1]});
    }
    fin.close();

    for(const auto &q : queries){
        auto path1 = getPath(tree, q.first);
        auto path2 = getPath(tree, q.second);
        auto it1 = path1.begin();
        auto it2 = path2.begin();
        while((it1 != path1.end() && it2 != path2.end() && *it1 == *it2)){
            ++it1;
            ++it2;
        }
        cout << *prev(it1) << "\n";
    }

    return 0;
}