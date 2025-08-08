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
    vector<int>dis(n+5, INT_MAX);
    dis[src] = 0;
    
    priority_queue<pi, vector<pi>, greater<pi>>pq;
    pq.push({0, src}); // {cost, node}

    while(!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for(auto &adj: v[cur_node])
        {
            int wt = adj.first;
            int to = adj.second;//to means neighbour node
            if(dis[cur_node] + wt < dis[to])
            {
                dis[to] = dis[cur_node] + wt;
                pq.push({dis[to], to});
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout << dis[i] << ' ';
    }
}