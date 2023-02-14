#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

void addEdge(vector<list<int>> &graph, int v, int w){
    graph[v].push_back(w);
    graph[w].push_back(v);
}

pair<int, int> bfs(vector<list<int>> &graph, int start){
    vector<int> dist(graph.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 1;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(auto adj : graph[current]) {
            if(dist[adj] == -1) {
                q.push(adj);
                dist[adj] = dist[current] + 1;
            }
        }
    }
    auto max_dist = max_element(dist.begin(), dist.end());
    return make_pair(distance(dist.begin(), max_dist), *max_dist);
}

int main() {
    ifstream fin("input.txt");
    int n = 0;
    fin >> n;
    vector<list<int>> graph(n + 1);
    for(int i = 0; i < n; ++i){
        int first, second;
        fin >> first >> second;
        addEdge(graph, first, second);
    }
    fin.close();

    auto max_from_last = bfs(graph, graph.back().back());
    auto real_max = bfs(graph, max_from_last.first);
    cout << real_max.second;
    return 0;
}