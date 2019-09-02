#include "grafo.h"
#include "dados.h"
#include <iostream>

vector<Pessoa> nodes;
vector<vector<unsigned int>> edges;

bool BFS(const unsigned int src, const unsigned int dest, vector<int> &pred, vector<int> &dist) {
    unsigned long v = nodes.size();
    queue<unsigned int> queue;
    bitset<MAX> visited;

    for (unsigned long i = v; i--; ) {
        visited[i] = false;
        dist[i] = 999999999;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push(src);

    while (!queue.empty()) {
        unsigned int u = queue.front();
        queue.pop();
        for (unsigned long i = edges[u].size(); i--; ) {
            unsigned int valor = edges[u][i];
            if(visited[valor] == false) {
                visited[valor] = true;
                dist[valor] = dist[u] + 1;
                pred[valor] = u;
                queue.push(valor);

                if (valor == dest)
                    return true;
            }
        }
    }

    return false;
}

vector<int> BFS_Shortest_Distance(const unsigned int s, const unsigned int dest) {
    unsigned long v = nodes.size();
    vector<int> pred(v), dist(v);

    if (BFS(s, dest, pred, dist) == false) {
        vector<int> path = {-1};
        return path;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    return path;
}

void complete_BFS(const unsigned int src, vector<int>& dist) {
    unsigned long v = nodes.size();
    queue<unsigned int> queue;
    bitset<MAX> visited;

    for (unsigned long i = v; i--; ) {
        visited[i] = false;
        dist[i] = 999999999;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push(src);

    while (!queue.empty()) {
        unsigned int u = queue.front();
        queue.pop();
        for (unsigned long i = edges[u].size(); i--; ) {
            unsigned int valor = edges[u][i];
            if(visited[valor] == false) {
                visited[valor] = true;
                dist[valor] = dist[u] + 1;
                queue.push(valor);
            }
        }
    }
}

vector<int> complete_BFS_Shortest_Distance(const unsigned int s) {
    unsigned long v = nodes.size();
    vector<int> pred(v), dist(v);

    complete_BFS(s, dist);

    vector<int> quantidade(1000, 0);

    for (unsigned long i = dist.size(); i--; ) {
        if(dist[i] >= quantidade.size() && dist[i] != 999999999) {
            quantidade.resize(dist[i]+1);
            quantidade[dist[i]] = 1;
        }
        else if(dist[i] != 999999999){
            quantidade[dist[i]]++;
        }
        else if(dist[i] == 999999999) {
            quantidade[0]++;
        }
    }

    return quantidade;
}

map<string, int> coletar_cidades() {
    map<string, int> m;
    for(auto& n : nodes) {
        m[n.get_cidade()]++;
    }

    return m;
}

bool colorGraph(vector<int>& color,int pos, int c){
    if(color[pos] != -1 && color[pos] !=c)
        return false;

    color[pos] = c;
    bool ans = true;
    for(const auto& e : edges[pos]) {
        if(color[e] == -1)
            ans &= colorGraph(color,e,1-c);

        if(color[e] != -1 && color[e] != 1-c)
            return false;

        if (!ans)
            return false;
    }

    return true;
}

bool isBipartite(){
    const size_t V = nodes.size();
    vector<int> color(V, -1);

    int pos = 0;
    return colorGraph(color,pos,1);
}

int quantidade_componentes() {
    const size_t V = nodes.size();
    bitset<MAX> visited;
    int count = 0;

    for (size_t v = 0; v < V; ++v) {
        if (!visited[v]) {
            DFSUtil(v, visited);
            count++;
        }
    }

    return count;
}

void DFSUtil(int v, bitset<MAX>& visited) {
    visited[v] = true;

    for(const auto& i : edges[v])
        if (!visited[i])
            DFSUtil(i, visited);
}
