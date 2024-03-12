#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

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
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll MOD = 998244353;
const ll MOD1 = 1e9+7;
const int MAXN = 1e6+100;
const int MAX = 2e6+100;
const int LOG = 30;
// const ll base = 311;
const ll INF = 1e18+2;
const db pi = acos(1);
const int EPS = 1e-9;
using namespace std;
// using namespace __gnu_pbds;
ll n,m,num[MAX],low[MAX],d=0,d1=0,ans=0;
vl v[MAX],f[MAX];
bool b[MAX];
stack<int> st;
void dfs(ll u){
  st.push(u);
  num[u]=low[u]=++d;
  for(auto x:v[u])
    if (b[x]){
      if (!num[x]){
        dfs(x);
        low[u]=min(low[u],low[x]);
      } else low[u]=min(low[u],num[x]);
    }
  if (num[u]==low[u]){
    ll s=0;
    d1++;
    while(1){
      b[st.top()]=0;
      f[d1].pb(st.top());
      s++;
      if (st.top()==u){
        st.pop();
        break;
      }
      st.pop();
    }
    ans+=(s*(s-1)); 
  }
}
void solve(){
  cin>>n>>m;
  FOR(i,1,m){
    ll x,y;
    cin>>x>>y;
    v[x].pb(y);
  }
  memset(num,0,sizeof(num));
  memset(b,1,sizeof(b));
  FOR(i,1,n)
    if (!num[i]) dfs(i);
  memset(b,0,sizeof(b));
  FOR(i,1,d1){
    for(auto x:f[i]) b[x]=1;
    for(auto x:f[i]) 
      for(auto y:v[x])
        if (b[y]) ans--;
    for(auto x:f[i]) b[x]=0;
  }
  cout<<ans;
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
