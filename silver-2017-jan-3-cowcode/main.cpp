#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string code;
ll N;
int len;

char recursive(ll cur, ll scope)
{
    if (cur < len)
    {
        // we know
        return code[cur];
    }

    while (cur < scope/2)
    {
        // rescope
        scope /= 2;
    }

    if (cur == scope / 2)
    {
        // special case
        return recursive(cur-1, scope);
    }
    // else
    return recursive(cur - scope/2 - 1, scope);
}

int main()
{
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    cin >> code >> N;

    N--;

    len = code.length();
    ll scope = len;
    while (N >= scope)
    {
        scope *= 2;
    }

    cout << recursive(N, scope) << endl;

    return 0;
}
