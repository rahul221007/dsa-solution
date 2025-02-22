#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define fill(a, val) memset(a, val, sizeof(a))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
ll modpower(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1LL)
            res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
const int N = 500500;
ll fact[N];
ll modinv(ll n, ll p)
{
    return modpower(n, p - 2, p);
}
ll ncr(ll n, ll r, ll md)
{
    return ((fact[n] * modinv(fact[r], md) % md) * modinv(fact[n - r], md)) % md;
}
void facto(ll md)
{
    fact[0] = 1;
    for (int i = 1; i <= 500000; i++)
        fact[i] = (fact[i - 1] * i) % md;
}
int flag = false;
int cycle_start;
int cycle_end;
int parent[100001];
bool dfs(int s, int par, int vis[], vector<int> graph[])
{
    vis[s] = 1;
    for (auto x : graph[s])
    {
        if (x == par)
            continue;
        if (vis[x] == 1)
        {
            flag = true;
            cycle_start = x; // start bcz its already visited before s;
            cycle_end = s;
            return true;
        }
        parent[x] = s;
        if (dfs(x, s, vis, graph))
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;

    while (t--)
    {
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        memset(parent, -1, sizeof parent);

        vector<int> graph[n + 1];
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int vis[n + 1] = {0};
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, parent[i], vis, graph))
                    break;
            }
        }
        if (!flag)
        {
            cout << "IMPOSSIBLE";
            continue;
        }
        vector<int> cycle;
        int x = cycle_end;
        while (x != cycle_start)
        {
            cycle.push_back(x);
            x = parent[x];
        }
        cycle.push_back(cycle_start);
        cout << cycle.size() + 1 << endl;
        cout << cycle_start << " ";
        for (auto x : cycle)
        {
            cout << x << " ";
        }
    }
    return 0;
}