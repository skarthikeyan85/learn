#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

class Graph {
    int V;                  //Number of vertices
    list<int> *adj;         //Array of lists - per vertex
    bool *visited;
    vector<int> indegree;

    void DFSUtil(int v);
    void TOPUtil(int v, bool visited[], stack<int> & ansStack);
    void alltopologicalSortUtil(vector<int>& res);
    void resetVisited();
    int findElem(list <int>l);

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    void TOP();
    void kahnsTOP();
    void alltopologicalSort();
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int> [V+1];
    visited = new bool[V+1];
    for (int i = 0; i <= V; i++)
        indegree.push_back(0);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    //Only for undirected graph
    //adj[w].push_back(v);
    indegree[w]++;
}

void Graph::resetVisited()
{
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }
}

void Graph::DFSUtil(int s)
{
    visited[s] = true;
    cout << s << " ";
    
    list<int>::iterator i;

    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[*i]) {
            DFSUtil(*i);
        }
    }
}

void Graph::DFS(int s)
{
    resetVisited();
    DFSUtil(s);
    cout << "\n";
}

void Graph::TOPUtil(int s, bool vis[], stack<int> & ans)
{
    list<int>::iterator i;

    vis[s] = true;
    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!vis[*i]) {
            TOPUtil(*i, vis, ans);
        }
    }

    ans.push(s);
}

void Graph::TOP()
{
    stack<int> ansStack;

    bool *vis= new bool[V+1];
    for (int i = 1; i <= V; i++)
        vis[i] = false;

    resetVisited();
    cout << " TOP sort " << endl;
    for (int i = 1; i <= V; i++) {
        if (!vis[i]) {
            TOPUtil(i, vis, ansStack);
        }
    }

    while (!ansStack.empty()) {
       cout <<  ansStack.top() << " ";
       ansStack.pop();
    }

    cout << endl;

    return;
}

void Graph::kahnsTOP()
{
    queue<int> q;
    vector<int> ans;
    vector<int> in(V+1, 0);
    int cnt = 0;

    for (int i = 1; i <= V; i++) {
        list<int>::iterator itr;
        for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
            in[*itr]++;
    }

    for (int i = 1; i <= V; i++) {
        if (in[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        ans.push_back(i);

        list<int>::iterator itr;
        for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
            if(--in[*itr] == 0)
                q.push(*itr);

        cnt++;
    }

    cout << " KHANS TOP sort " << endl;
    
    if (cnt != (V)) {
        cout << "Cycle present - No TOP" << endl;
        cout << cnt << " " << V << endl;
    }

    int i = 0;
    while ( i < ans.size()) {
        cout <<  ans[i] << " ";
        i++;
    }

    cout << endl;

    return;
}

void Graph::alltopologicalSortUtil(vector<int> &ans)
{
    bool flag = false;
    int i = 0;

    for (i=1; i<= V; i++) {
        if (indegree[i] == 0 && !visited[i]) {
            list<int>::iterator j;

            for(j=adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]--;

            ans.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(ans);
        
        
            for(j=adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]++;

            ans.erase(ans.end() - 1);
            visited[i] = false;

            flag = true;
        }
    }

    if (!flag) {
        for (i=0; i<ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return;
}


void Graph::alltopologicalSort()
{
    vector<int> ans;

    cout << " All TOP sort " << endl;

    resetVisited();
    alltopologicalSortUtil(ans);

    cout << endl;

    return;
}

void Graph::BFS(int s)
{
    list<int> queue;
    list<int>::iterator i;

    resetVisited();

    queue.push_back(s);
    visited[s] = true;
    cout << " BFS from " << s << endl;

    while (!queue.empty()) {
        s = queue.front(); 
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    cout << "\n";
}

int Graph::findElem(list <int>ans)
{
    int s = -1;

    for (int i = 1; i <= V; i++) {
        if (adj[i].size()) {
            if ((ans.size() == 0) ||
                (find(ans.begin(), ans.end(), i) == ans.end())) {
                s = i;
                break;
            }
        }
    }

    return s;
}

int main()
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int x;
        int y;
        int c;
        int rem = -1;
        cin >> n >> m >> x >> y;
        Graph g(n);

        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            g.addEdge(city_1, city_2);
            rem = rem == -1 ? city_1 : rem ;
        }
        g.BFS(rem);
        g.TOP();
        g.alltopologicalSort();
        g.kahnsTOP();
    }
    return 0;
}


