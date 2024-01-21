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
const ll MAX = 2e6+3000;
const ll LOG = 21;
int n, m[MAX],a[MAX],k, T[MAX], ans, d[MAX];
vl v[MAX],v1[MAX];
vpll f;
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
        if(d[T[x]] == t) continue;
        if(!DFS(T[x], t)) continue;
        T[x] = u;
        if (v1[u].size()==0) v1[u].pb(x);
          else v1[u][0]=x;
        return 1;
    }
    return 0;
}
void solve(){
  cin>>n;
  FOR(i,1,n){
    ll x=0;
    FOR(j,1,n) {
        cin>>x;
        if (x==1) v[i].pb(j);        
    }
  }
  for(int i=1; i<=n; i++) ans+=DFS(i, i);
  FOR(i,1,n) a[i]=m[i]=i;
  FOR(i,1,n)
    if (v1[i].size()!=0){
        if (a[i]!=v1[i][0]) {
            f.pb({i,m[v1[i][0]]});
            swap(a[i],a[m[v1[i][0]]]);
            swap(m[v1[i][0]],m[a[m[v1[i][0]]]]);
        }
    }
  cout<<f.size()<<"\n";
  for(auto x:f) cout<<"2 "<<x.fi<<" "<<x.se<<"\n";
}  
int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin); 
    freopen("output.out", "w", stdout);
    #endif
        solve();
}
