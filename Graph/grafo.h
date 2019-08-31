#ifndef GRAFO_H
#define GRAFO_H

#include <pessoa.h>
#include <vector>
#include <bitset>
#include <list>
#include <queue>
#include <map>

using namespace std;

extern vector<Pessoa> nodes;
extern vector<vector<unsigned int>> edges;

bool BFS(const unsigned int src, const unsigned int dest, vector<int>& pred, vector<int>& dist);
vector<int> BFS_Shortest_Distance(const unsigned int s, const unsigned int dest);

void complete_BFS(const unsigned int src, vector<int>& dist);
vector<int> complete_BFS_Shortest_Distance(const unsigned int s);

map<string, int> BFS_cidades();

#endif // GRAFO_H
