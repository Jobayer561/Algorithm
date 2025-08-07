#include<bits/stdc++.h>

using namespace std;

struct A
{
    int u, v, wt;
};

bool cmp(A x, A y)
{
    return (x.wt < y.wt);
}

// DSU

const int N = 105;
int par[N];

void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        par[i] = i;
    }
}

int find_par(int x)
{
    if(par[x] == x)return x;
    return par[x] = find_par(par[x]);
}

bool Union(int x, int y)
{
    int par_x = find_par(x);
    int par_y = find_par(y);
    if(par_x == par_y)return 0;
    par[par_x] = par_y;
    return 1;
}

// DSU

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

    sort(Edge.begin(), Edge.end(), cmp);

    for(auto e: Edge)
    {
        cout << e.u << ' ' << e.v << ' ' << e.wt << endl;
    }

    int ttl_cost = 0;

    init(n);

    for(auto e:Edge)
    {
        if(Union(e.u, e.v) == 1)
        {
            ttl_cost += e.wt;
        }
    }

    cout << ttl_cost << endl;
}