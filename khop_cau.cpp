#include<bits/stdc++.h>
#include <math.h>
#include <stack>

/*** Input Output ***/
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdb pair<db, db>
#define vi vector<int>
#define vpdb vector<pdb>
#define vl vector<ll>
#define vdb vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpd vector<pd>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
#define str string
#define db double

/*** Define Values ***/
//#define mx 200005
#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7
#define size1 15

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))

/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())

/*** Some Prints ***/
#define en cout << '\n';
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define case cout << "Case " << t++ << ": "
#define whi while (ii<=n)

//loops
#define FOR(i, a, b) for(int i=(int)a;i<=(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)
#define MASK(x) (1ll<<(x))
#define SQR(x) (x*x)
const ll MOD = 1e18+7;
const ll MAXN = 1e18;
const ll MAX = 1e3;
const ll INF = 1e18+100;
using namespace std;
  ll num[10000],low[10000],d=0,ans=0,ans1=0;
  vl v[10000];
  bool b[1000];
void dfs(ll u,ll par){
  ll child=0;
  num[u]=low[u]=++d;
  FOR(i,0,v[u].size()-1){
    if (v[u][i]==par) continue;
    if (!num[v[u][i]]){
      dfs(v[u][i],u);
      low[u]=min(low[u],low[v[u][i]]);
      if (low[v[u][i]]==num[v[u][i]]) ans1++;
      child++;
      
      if (u==par){
        if (child>1) b[u]=1;
      } else if (low[v[u][i]]>=num[u]) b[u]=1;

    } else low[u]=min(low[u],num[v[u][i]]);
  }
}
void solve(){
  ll n,m;
  cin>>n>>m;
  memset(b,0,sizeof(b));
  memset(num,0,sizeof(num));
  FOR(i,1,m){
    ll x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  FOR(i,1,n)
    if (!num[i]) dfs(i,i);
  FOR(i,1,n) 
    if (b[i]) ans++;
  cout<<ans<<" "<<ans1;
}
int main(){
  IOS;
  // #ifndef ONLINE_JUDGE   
    // freopen("caro.INP", "r", stdin);
    // freopen("caro.OUT", "w", stdout);
  // #endif
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin); 
  freopen("output1.txt", "w", stdout);
  #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}