#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<string>> sol;
int cnt = 0;

bool safe(int row, int col, vector<string>& v)
{
    // same col
    for(int i=0; i<row; i++)
    {
        if(v[i][col] == 'Q')
        {
            return 0;
        }
    }

    // main diag
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
    {
        if(v[i][j] == 'Q')
        {
            return 0;
        }
    }

    // secondary diag
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
    {
        if(v[i][j] == 'Q')
        {
            return 0;
        }
    }

    return 1;
}

void solve(int row, vector<string>& v)
{
    if(row == n)
    {
        cnt++;
        sol.push_back(v);
        return;
    }

    for(int col= 0; col < n; col++)
    {
        if(safe(row, col, v))
        {
            v[row][col] = 'Q';
            solve(row + 1, v);
            v[row][col] = '.';
        }
    }
}

int main()
{
    cin >> n;
    vector<string> v(n, string(n, '.')); // initial board
    
    solve(0, v); // current_row, board

    cout << "Total Solutions: " << cnt << endl;
    for(auto &ans : sol)
    {
        for(auto &row : ans)
        {
            cout << row << endl;
        }
        cout << endl;
    }
}