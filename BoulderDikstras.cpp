#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

// N is the maximum number of nodes in the graph
// M is the maximum number of edges in the graph
const int N = 400;
const int M = 80000;


// head[i] stores the starting edge for node i in the adjacency list representation of the graph
// ver[i] stores the end node of edge i in the adjacency list representation of the graph
// edge[i] stores the weight of edge i in the adjacency list representation of the graph
// Next[i] stores the next edge after edge i in the adjacency list representation of the graph
int head[N], ver[M], edge[M], Next[M];
// d[i] stores the minimum distance from node S to node i
// incf[i] stores the maximum flow from node S to node i
int d[N], incf[N];
// vis[i] stores whether node i has been visited in the current BFS
bool vis[N];
// n is the number of nodes in the graph
// m is the number of edges in the graph
// S is the source node
// T is the sink node
int n, m, S, T;

// Node structure used to store a node in the priority queue
struct Node {
    int u, d;
    // Overload the < operator to compare two nodes based on their distances
    bool operator<(const Node &x) const {
        return x.d < d;
    }
};
// add function to add an edge between nodes x and y with weight z
void add(int x, int y, int z) {
    static int tot = -1;
    // Add the edge from node x to node y
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
    // Add the reverse edge from node y to node x
    ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

// bfs function to find the shortest path from node S to node T
bool bfs() {
    // Initialize all distances to INT_MAX
    for (int i = 0; i < n; i++)
        d[i] = INT_MAX;

    // Initialize the queue    
    queue<int> q;
    q.push(S);

    // Set the distance of node S to 0 and the maximum flow from node S to INT_MAX
    d[S] = 0, incf[S] = INT_MAX, vis[S] = true;

    // Perform the BFS
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = head[x]; ~i; i = Next[i]) {
            int y = ver[i];
            if (!edge[i]) continue;
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                incf[y] = min(incf[x], edge[i]);
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
    }
    return d[T] != INT_MAX;
}

int dinic(int x, int flow) {
    if (x == T) return flow;
    int rest = flow, k;
    vis[x] = true;
    for (int i = head[x]; ~i && rest; i = Next[i]) {
        int y = ver[i];
        if (vis[y] || !edge[i]) continue;
        if (d[y] == d[x] + 1 && (k = dinic(y, min(rest, edge[i])))) {
            edge[i] -= k;
            edge[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}

int dinic() {
    int maxflow = 0, flow;
    while (bfs()) {
        for (int i = 0; i < n; i++)
            vis[i] = false;
        while (flow = dinic(S, INT_MAX))
            maxflow += flow;
    }
    return maxflow;
}

