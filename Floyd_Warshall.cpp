#include<bits/stdc++.h>

using namespace std;

int A[105][105];

int main()
{
    int n, e;
    cin >> n >> e;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j)
            {
                A[i][j] = 0;
            }
            else
            {
                A[i][j] = INT_MAX;
            }
        }
    }

    while(e--)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        A[x][y] = wt;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(A[i][k] == INT_MAX || A[k][j] == INT_MAX)
                {
                    continue;
                }
                if(A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}