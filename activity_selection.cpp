#include<bits/stdc++.h>

using namespace std;

struct A
{
    int st, ed;
};

bool cmp(A &x, A &y)
{
    return (x.ed < y.ed);
}

int main()
{
    int n;
    cin >> n;
    vector<A>v(n);
    for(int i=0; i<n; i++)cin >> v[i].st;
    for(int i=0; i<n; i++)cin >> v[i].ed;
    sort(v.begin(), v.end(), cmp);
    int last = v[0].ed, cnt = 1;
    for(int i=1; i<n; i++)
    {
        if(v[i].st >= last)
        {
            cnt++;
            last = v[i].ed;
        }
    }
    cout << cnt << endl;

    return 0;
}