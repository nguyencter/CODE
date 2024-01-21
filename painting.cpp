#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;

#define str string
#define ll long long
#define vl vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MASK(x) (1ll<<(x))
#define all(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=(int)a;i>=(int)b;i--)           
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll INF = 1e18+7;
const ll MOD = 1e9+7;
const ll MAXN = 1e6+3000;
const ll MAX = 2e5+3000;
const ll LOG = 21;
ll n, s, k, T[MAX],ans, d[MAX],a[150][150],dp[60][60][60][60];
vl v[MAX],v1[MAX];
bool DFS(int u, int t)
{
    d[u] = t;
    FOR(i,0,v[u].size()-1)
    { 
        ll x=v[u][i];
        if(T[x]) continue;
        T[x] = u;
        if (v1[u].size()==0) v1[u].pb(x);
          else v1[u][0]=x;
        return 1;
    }
    FOR(i,0,v[u].size()-1)
    {
        ll x=v[u][i];
        // cout<<u<<" "<<x<<'\n';
        if(d[T[x]] == t) continue;
        if(!DFS(T[x], t)) continue;
        T[x] = u;
        if (v1[u].size()==0) v1[u].pb(x);
          else v1[u][0]=x;
        return 1;
    }
    return 0;
}
ll f(ll x,ll y,ll u,ll v){
    if (dp[x][y][u][v]!=-1) return dp[x][y][u][v];
    ll ans=a[u][v]-a[x-1][v]-a[u][y-1]+a[x-1][y-1];
    if (ans==0) return dp[x][y][u][v]=0;
    ans=min(ans,max(u-x+1,v-y+1));
    FOR(i,x,u-1) ans=min(ans,f(x,y,i,v)+f(i+1,y,u,v));
    FOR(i,y,v-1) ans=min(ans,f(x,y,u,i)+f(x,i+1,u,v));
    return dp[x][y][u][v]=ans;
}
void solve(){
    cin>>k>>n>>s;
    if (k==1){
        FOR(i,1,s){
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
        }
        for(int i=1; i<=n; i++) ans+=DFS(i, i);
        cout<<ans;
    } else {
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        FOR(i,1,s){
            ll x,y;
            cin>>x>>y;
            a[x][y]=1;
        }
        FOR(i,1,n)
          FOR(j,1,n) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        cout<<f(1,1,n,n);
    }
}  
int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin); 
    freopen("output.out", "w", stdout);
    #endif
        solve();
}
