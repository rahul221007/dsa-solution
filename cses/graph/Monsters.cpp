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

char mat[1000 + 1][1000 + 1];

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char go[] = {'U', 'D', 'R', 'L'};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        queue<pair<int, int>> q;
        int x, y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 'M')
                {
                    q.push({i, j});
                }
                if (mat[i][j] == 'A')
                {
                    x = i;
                    y = j;
                }
            }
        }
        q.push({x, y});
        int parent[n + 1][m + 1];
        parent[x][y] = -1;
        bool found = false;

        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if (mat[x][y] == 'A' and (x == 0 || y == 0 || x == n - 1 || y == m - 1))
            {
                cout << "YES" << endl;

                string ans = "";
                int curr = parent[x][y];
                while (curr != -1)
                {
                    ans += go[curr];
                    x -= fx[curr];
                    y -= fy[curr];
                    curr = parent[x][y];
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                cout << ans;
                found = true;
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int xx = x + fx[i];
                int yy = y + fy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || mat[xx][yy] != '.')
                    continue;

                mat[xx][yy] = mat[x][y];
                if (mat[x][y] == 'A')
                    parent[xx][yy] = i;
                q.push({xx, yy});
            }
        }
        if (!found)
            cout << "NO";
    }
    return 0;
}