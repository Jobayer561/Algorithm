#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int>v[n+5];
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); 
    }

    vector<bool>vis(n+5, 0);
    vector<int>dis(n+5, -1); 
    int src = 1;
    vis[src] = 1;
    dis[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0; i<(int)v[cur].size(); i++)
        {
            int adj = v[cur][i];
            if(vis[adj] == 0)
            {
                vis[adj] = 1;
                dis[adj] = dis[cur] + 1;
                q.push(adj);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << dis[i] << ' ';
    }
}