#include "grafo.h"
#include <iostream>

vector<Pessoa> nodes;
vector<vector<Pessoa*>> edges;

const int MAX = 10000000;

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
            unsigned int valor = edges[u][i]->get_id();
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

void complete_BFS(const unsigned int src, vector<int>& pred, vector<int>& dist) {
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
            unsigned int valor = edges[u][i]->get_id();
            if(visited[valor] == false) {
                visited[valor] = true;
                dist[valor] = dist[u] + 1;
                pred[valor] = u;
                queue.push(valor);
            }
        }
    }
}

vector<int> complete_BFS_Shortest_Distance(const unsigned int s) {
    unsigned long v = nodes.size();
    vector<int> pred(v), dist(v);

    complete_BFS(s, pred, dist);

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
