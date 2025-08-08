#include<bits/stdc++.h>
using namespace std;
struct A
{
    int u, v, wt;
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<A>Edge;
    while(e--)
    {
        A tmp;
        cin >> tmp.u >> tmp.v >> tmp.wt;
        Edge.push_back(tmp);
    }
    vector<int>dis(n+5, INT_MAX);
    int src = 1;
    dis[src] = 0;

    for(int i=0; i<n-1; i++)
    {
        for(auto &e: Edge)
        {
            if(dis[e.u] + e.wt < dis[e.v])
            {
                dis[e.v] = dis[e.u] + e.wt;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout << dis[i] << ' ';
    }
}
