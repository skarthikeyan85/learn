#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

typedef pair<int, int> intPair;

class Graph {
    /* directed, weighted graph */
    int V;                        // Number of vertices
    list<pair<int,int>> *adj;     // list of adjacency vertex, weight pairs - per vertex
                                  // 1-based array of vertices
    void DFSUtil(int v, bool visited[]);

  public:
    Graph(int num) {
        V = num;
        adj = new list<pair<int,int>> [V+1];
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v,w));
    }
    void BFS(int s);
    void DFS(int s);
    void display();
    vector <int> dijkstra(int s);
    vector <int> dijkstra_minheap(int s);
};

void Graph::display() {
    for (auto i = 1; i <= V; i++) {
        if (!adj[i].size())
            continue;
        cout << i  << " - ";
        for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
            cout << "(" << j->first << "," << j->second << ")";
        }
        cout << endl;
    }
}

void Graph::DFSUtil(int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";

    for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[i->first]) {
            DFSUtil(i->first, visited);
        }
    }
}

void Graph::DFS(int s) {
    bool *visited = new bool[V+1];

    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }

    DFSUtil(s, visited);
    cout << "\n";
}

void Graph::BFS(int s) {
    bool *visited = new bool[V+1];
    list<int> queue;

    for (int i = 1; i < V+1; i++) {
        visited[i] = false;
    }

    queue.push_back(s);
    visited[s] = true;

    while(!queue.empty()) {
        s = queue.front(); 
        cout << s << " ";
        queue.pop_front();

        for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[i->first]) {
                visited[i->first] = true;
                queue.push_back(i->first);
            }
        }
    }

    cout << endl;
}

/* Implement pseudo code for:
http://cs.indstate.edu/hgopireddy/pseudo1.pdf
== corrected version of algo
returns the min path weight from s to all other vertices in the graph */
vector <int> Graph::dijkstra(int s) {
    list<int> queue;
    set<int> visited;
    vector<int> dist(V+1, INT_MAX);

    dist[s] = 0;
    queue.push_back(s);
    //for (auto i = 1; i <= V; i++)
    //    queue.push_back(i);

    while (!queue.empty()) {
        int min_val = INT_MAX;
        int u = -1;

        /* Find the min val in the queue - not really a queue operation
          - Hence replaced the datastruct with a list */
        for (auto elem : queue) {
            if (dist[elem] <= min_val) {
                u = elem;
                min_val = dist[elem];
            }
        }

        if (u == -1)
            break; //No such element found
        queue.remove(u);
        visited.insert(u);

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            auto v = i->first;
            //v is already visited continue
            if (visited.find(v) != visited.end())
                continue;
            auto better_path = dist[u] + i->second;
            if (dist[v] > better_path) {
                dist[v] = better_path;
                queue.push_back(v);
            }
        }
    }

    dist.erase (dist.begin()); // one-based array - remove 0th element
    return dist;
}

/* using stl min_heap */
vector <int> Graph::dijkstra_minheap(int s)
{
    priority_queue< intPair, vector <intPair> , greater<intPair> > pq;
 
    vector<int> dist(V+1, INT_MAX);
 
    pq.push(make_pair(0, s));
    dist[s] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
 
        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = i->first;
            int weight = i->second;
 
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    dist.erase (dist.begin()); // one-based array - remove 0th element
    return dist;
}

#define DUMP_VECTOR(_vect)  \
    for (auto num : _vect)  \
        cout << num << " "; \
    cout << endl;

int main() {
    Graph g(5);

    g.addEdge(1, 2, 44);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 4, 14);
    g.addEdge(2, 5, 8);
    g.addEdge(3, 4, 11);
    g.addEdge(3, 2, 2);
    g.addEdge(4, 5, 24);
    g.addEdge(5, 2, 3);

    cout << "display the graph" << endl;
    g.display();

    cout << "BFS of " << 3 << endl;
    g.BFS(3);

    cout << "DFS of " << 5 << endl;
    g.DFS(5);

    cout << "dijkstra of " << 3 << endl;
    auto ret = g.dijkstra(3);
    DUMP_VECTOR(ret);

    /*
    */
    cout << "dijkstra_minheap of " << 3 << endl;
    ret = g.dijkstra_minheap(3);
    DUMP_VECTOR(ret);

    cout << "dijkstra of " << 1 << endl;
    ret = g.dijkstra(1);
    DUMP_VECTOR(ret);

    cout << "dijkstra_minheap of " << 1 << endl;
    ret = g.dijkstra_minheap(1);
    DUMP_VECTOR(ret);
    return 0;
}


