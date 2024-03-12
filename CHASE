#include<bits/stdc++.h>

/*** Input Output ***/
#define pii pair<int, int>
#define plll pair<ll, pll>
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
#define vplll vector<plll>
#define vpd vector<pd>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
#define ull unsigned long long
#define str string
#define db double

/*** Define Values ***/
//#define mx 200005
// #define mod 111539786
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
#define fi1 cout << "First\n"
#define se2 cout << "Second\n"
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define case cout << "Case " << t++ << ": "
#define whi while (ii<=n)

//loops
#define FOR(i, a, b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i, a, b) for(int i=(int)a;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)
#define MASK(x) (1ll<<(x))
#define BIT(x, i) (((x) >> (i)) & 1) 
#define SQR(x) (x*x)
const ll MOD = 1e9+7;
const ll MOD1 = 1e9+7;
const int MAXN = 2e5+100;
const int MAX = 4e5+100;
const int LOG = 20;
const ll base = 311;
const ll INF = 1e18+2;
const db pi = acos(1);
const int EPS = 1e-9;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
ll n,m,q,d,dst[MAX],dst1[MAX];
pll a[MAX];
vl v[MAX],f;
bool kt,b[MAX];
void dijkstra(ll u1){
  FOR(i,1,n) {
    dst[i]=INF;
    b[i]=1;
  }
  deque<ll> f1;
  f1.pb(u1);
  dst[u1]=0;
  b[u1]=0;
  while(f1.size()){
    ll u=f1.front();
    f1.pop_front();
    for(auto x:v[u])
      if (b[x]){
        b[x]=0;
        dst[x]=dst[u]+1;
        f1.pb(x);
      }
  }
}
void dijkstra1(ll u1){
  FOR(i,1,n) {
    dst1[i]=INF;
    b[i]=1;
  }
  deque<ll> f1;
  f1.pb(u1);
  dst1[u1]=0;
  b[u1]=0;
  while(f1.size()){
    ll u=f1.front();
    f1.pop_front();
    for(auto x:v[u])
      if (b[x]){
        b[x]=0;
        dst1[x]=dst1[u]+1;
        f1.pb(x);
      }
  }
}
void dfs(ll u,ll par){
  b[u]=0;
  for(auto x:v[u]){
    if (x==d&&par!=d) kt=1;
    if (kt) return;
    if (b[x]) dfs(x,u);
  }
}
void solve(){
  cin>>n>>m>>q;
  FOR(i,1,q) cin>>a[i].fi>>a[i].se;
  FOR(i,1,m){
    ll x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  FOR(i,1,n){
    d=i;
    kt=0;
    memset(b,1,sizeof(b));
    dfs(i,i);
    if (kt) f.pb(i);
  }
  FOR(i,1,q){
    kt=1;
    for(auto x:f){
      dijkstra(a[i].fi);
      dijkstra1(a[i].se);
      if (dst[x]>dst1[x]) {
        kt=0;
        break;
      }
    }
    cout<<kt<<"\n";
  }
}   

int main(){ 
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("input.inp", "r", stdin); 
  freopen("output.out", "w", stdout);
  #endif
  int t=1;
  // cin>>t;
  while(t--)
    solve();
}
