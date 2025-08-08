#include<bits/stdc++.h>
using namespace std;
int mat[5][5];
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1; // x -> y
        mat[y][x] = 1; // y -> x (For Undirected)
    }
    for(int i=1; i<=n; i++)
    {
        cout << i << " => ";
        for(int j=1; j<=n; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}