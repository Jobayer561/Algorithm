#include<bits/stdc++.h>

using namespace std;

void dfs(int cur, vector<vector<int>>&v, vector<bool>&vis)
{
    if(vis[cur] == 1)
    {
        return;
    }
    vis[cur] = 1;
    cout << cur << ' ';
    for(int i=0; i<(int)v[cur].size(); i++)
    {
        int adj = v[cur][i];
        if(vis[adj] == 0)
        {
            dfs(adj, v, vis);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>>v(n+5);
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y); // x -> y
        v[y].push_back(x); // y -> x (For Undirected)
    }

    vector<bool>vis(n+5, 0);
    int src = 1;
    dfs(src, v, vis);
}