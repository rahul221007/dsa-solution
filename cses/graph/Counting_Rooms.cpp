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
ll modpower(ll a,ll b,ll c)
{
ll res=1;
while(b)
{
if(b&1LL)
res=(res*a)%c;
a=(a*a)%c;
b>>=1;
}
return res;
}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a,ll b){
if(b==0)
return a;
 return gcd(b,a%b);
}
long long lcm(ll a, ll b)
{
return (a / gcd(a, b)) * b;
}
const int N   = 500500;
ll fact[N];
ll modinv(ll n, ll p)
{
return modpower(n, p-2, p);
}
ll ncr(ll n, ll r, ll md)
{
return ((fact[n]*modinv(fact[r],md)%md)*modinv(fact[n-r],md))%md;
}
void facto(ll md)
{
fact[0]=1;
for(int i=1; i<=500000; i++)
fact[i]=(fact[i-1]*i)%md;
}
int arr[1001][1001];
int vis[1001][1001];
int dir[5]={0,-1,0,1,0};
void dfs(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m  || arr[i][j]==1 || vis[i][j]){
        return ;
    }
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dir[k];
        int y=j+dir[k+1];
        dfs(x,y,n,m);
    }
    


}
int main()
{ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
ll t;
t=1;
while(t--)
{
ll n,m;
cin>>n>>m;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char x;
        cin>>x;
       arr[i][j]=(x=='#'?1:0);
    }
}

int ans=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==0 and vis[i][j]==0){
            ans++;
            dfs(i,j,n,m);
        }
    }
}

cout<<ans<<endl;




}

return 0;
}