#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

/* TBD: does graph contain cycle ?? */

/* directed acyclic graph */
class Graph {
    int V;                  //Number of vertices
    list<int> *adj;         //Array of lists - per vertex
    void DFSUtil(int v, bool visited[]);
    int findElem(list <int>l);
    bool DFSCustom(int s, vector<int> &marker, list<int> &order);

    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    void display();
    list<int> topSort();
    list<int> dfsTopSort();
    bool isCycle();
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int> [V+1];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::DFSUtil(int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    list<int>::iterator i;

    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFSUtil(s, visited);
    cout << "\n";
}

void Graph::display() {
    for (auto i = 1; i <= V; i++) {
        if (!adj[i].size())
            continue;
        cout << i  << " - ";
        for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
            cout << "(" << *j << ")";
        }
        cout << endl;
    }
}

/* cormen - algorithms unlocked */
/* kind of: Kahns topSort */
list<int> Graph::topSort() {
    vector<int> inDeg(V+1, 0);
    list<int> order;
    list<int> next;

    // Calculate indegree
    for (auto i = 1; i <= V; i++) {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
            inDeg[*j] += 1;
        }
    }

    // populate list next with indegree of 0
    for (auto i = 1; i <= V; i++)
        if (!inDeg[i])
            next.push_back(i);

    while (!next.empty()) {
        int u = next.front();
        next.pop_front();
        order.push_back(u);
        for (auto j = adj[u].begin(); j != adj[u].end(); j++) {
            inDeg[*j] -= 1;
            if (!inDeg[*j])
                next.push_back(*j);
        }
    }

    return order;
}

#define INV  0
#define TMP  1
#define PERM 2

bool Graph::DFSCustom(int s, vector<int> &marker, list<int> &order) {
    bool ret = false;
    if (marker[s] == PERM)
        return false;
    if (marker[s] == TMP)
        return true;  // Not a DAG - cycle ??

    marker[s] = TMP;
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        ret = DFSCustom(*i, marker, order);
        if (ret)
            return ret;
    }
    marker[s] = PERM;
    order.push_front(s);
    return ret;
}

/* DFS topSort */
list<int> Graph::dfsTopSort() {
    vector<int> marker(V+1, 0);
    list<int> order;

    // populate list next with indegree of 0
    for (auto i = 1; i <= V; i++)
        if (marker[i] == INV)
            DFSCustom(i, marker, order);

    return order;
}

/* isCycle */
bool Graph::isCycle() {
    vector<int> marker(V+1, 0);
    list<int> order;

    // populate list next with indegree of 0
    for (auto i = 1; i <= V; i++) {
        if (marker[i] == INV) {
            auto val = DFSCustom(i, marker, order);
            if (val)
                return val;
        }
    }

    return false;
}


#define DUMP_LIST(_vect)    \
    for (auto num : _vect)  \
cout << num << " "; \
cout << endl;

int main() {
    Graph g(5);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(5,3);

    g.display();

    cout << "topSort" << endl;
    auto lst = g.topSort();
    DUMP_LIST(lst);

    cout << "dfsTopSort" << endl;
    lst = g.dfsTopSort();
    DUMP_LIST(lst);

    cout << "isCycle: " << g.isCycle() << endl;
    return 0;
}


