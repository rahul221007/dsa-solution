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
        vector<int> vis(n + 1);
        vector<pair<int, int>> graph[n + 1];
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].push_back({y, w});
        }

        priority_queue<pair<ll, ll>> pq;
        pq.push({0, 1});
        vector<int> visited[n + 1];
        ll dis[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dis[i] = 1e18;
        }
        dis[1] = 0;
        while (!pq.empty())
        {
            int s = pq.top().second;
            pq.pop();
            if (vis[s])
            {
                continue;
            }
            vis[s] = true;
            for (auto x : graph[s])
            {
                auto [y, w] = x;
                if (dis[s] + w < dis[y])
                {
                    dis[y] = dis[s] + w;
                    pq.push({-dis[y], y});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << dis[i] << " ";
        }
    }
    return 0;
}