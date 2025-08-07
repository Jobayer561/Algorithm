#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int>v[n+1];
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y); // x -> y
        v[y].push_back(x); // y -> x (For Undirected)
    }

    for(int i=1; i<=n; i++)
    {
        cout << i << " => ";
        int len = (int)v[i].size();
        for(int j=0; j<len; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}