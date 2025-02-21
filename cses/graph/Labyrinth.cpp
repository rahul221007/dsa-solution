#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define fill(a, val) memset(a, val, sizeof(a))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;

int arr[1001][1001];

int dir[5] = {0, -1, 0, 1, 0};  
int vis[1001][1001];

char fun(int x, int y, int x1, int y1) {
    if (x == x1) {
        if (y < y1) return 'L';  // Right
        else return 'R';         // Left
    }
    else if (y == y1) {
        if (x < x1) return 'U';  // Up
        else return 'D';         // Down
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    t = 1;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        int s1 = 0, s2 = 0, e1 = 0, e2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                arr[i][j] = (x == '#' ? 1 : 0); // '#' is blocked, 0 is open
                if (x == 'A') { s1 = i; s2 = j; }  // Starting point A
                if (x == 'B') { e1 = i; e2 = j; }  // Ending point B
            }
        }

        bool ans = false;
        queue<pair<int, int>> q;
        map<pair<int, int>, pair<int, int>> mp;
        mp[{s1, s2}] = {-1, -1};  // Mark starting point with a "dummy" parent
        vis[s1][s2] = 1;

        q.push({s1, s2});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == e1 && y == e2) {
                ans = true;
                break;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 1 || vis[nx][ny] == 1) {
                    continue;
                }
                vis[nx][ny] = 1;
                q.push({nx, ny});
                mp[{nx, ny}] = {x, y};  // Store parent of each cell
            }
        }

        if (!ans) {
            cout << "NO";
            continue;
        }

        // Reconstruct path
        string path = "";
        int x = e1, y = e2;
        while (x != s1 || y != s2) {
            auto p = mp[{x, y}];
            path += fun(x, y, p.first, p.second);  // Add direction to path
            x = p.first;
            y = p.second;
        }

        reverse(path.begin(), path.end());  

        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}
