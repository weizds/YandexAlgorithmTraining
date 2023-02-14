#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_child(const unordered_map<string, string> &tree, const string &child, const string &parent){
    auto found = tree.find(child);
    if(found == tree.end())
        return false;
    if(found->second == parent)
        return true;
    else
        return is_child(tree, found->second, parent);
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
        bool first_is_child = is_child(tree, q.first, q.second);
        bool second_is_child = is_child(tree, q.second, q.first);
        if(second_is_child)
            cout << "1 ";
        else if(first_is_child)
            cout << "2 ";
        else
            cout << "0 ";
    }

    return 0;
}