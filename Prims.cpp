#include<bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pi>v[n+5];
    while(e--)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        v[x].push_back({wt, y}); // x -> y (wt)
        v[y].push_back({wt, x}); // Undirected
    }

    int src = 1;
    vector<bool>vis(n+5, 0);
    
    priority_queue<pi, vector<pi>, greater<pi>>pq;
    pq.push({0, src}); // {cost, node}

    int ttl_cost = 0;

    // Prim's MST

    while(!pq.empty())
    {
        auto cur = pq.top();
        int cur_wt = cur.first;
        int cur_node = cur.second;
        pq.pop();

        if(vis[cur_node] == 1)
        {
            continue;
        }
        
        vis[cur_node] = 1;
        ttl_cost += cur_wt;

        for(auto x : v[cur_node])
        {
            int ch_wt = x.first;
            int ch_node = x.second;
            if(vis[ch_node] == 0)
            {
                pq.push({ch_wt, ch_node});
            }
        }
    }

    cout << ttl_cost << endl;
}