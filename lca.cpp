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
const ll MOD = 1e9+7;
const ll MAXN = 6e5;
const ll INF = 1e18+100;
using namespace std;
#define MAX   100100
#define LOG   30

vector<ll> adj[MAX]; // danh sách kề
ll par[MAX][LOG + 1]; // mảng cha
ll high[MAX]; // số cạnh từ một đỉnh tới gốc (độ sâu)
  ll n,k;

void dfs(ll u) {
  FOR(i,0,adj[u].size()-1)
  if (adj[u][i] != par[u][0]) {
    ll v=adj[u][i];
    par[v][0] = u; // cha trực tiếp của v là u
    high[v] = high[u] + 1;
    dfs(v);
  }
}

ll lca(ll u,ll v){
    if(high[v]>high[u]) swap(u,v);
    for(int i=30;i>=0;i--)
        if(high[par[u][i]]>=high[v])
            u=par[u][i];
    if(u==v)return u;
    for(int i=30;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];v=par[v][i];
        }
    }
    return par[u][0];
}
void read(){
  int u,v;
  cin>>u>>v;
  cout<<lca(u,v)<<"\n";
}
int main(){
  IOS;
  // #ifndef ONLINE_JUDGE
   // freopen("cauluong.INP", "r", stdin);
   // freopen("cauluong.OUT", "w", stdout);
  // #endif
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  // #endif
  cin>>n;
  // cout<<n;
  FOR(i,1,n-1) {
    ll x,y;
    cin>>x>>y;
    // cout<<x<<" "<<y<<endl;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  ll q;
  cin>>q;
  high[0] = -1; // rất quan trọng, không thể bỏ sót
  dfs(1);
  for (int j = 1; j <= LOG; j++) for (int i = 1; i <= n; i++)
    par[i][j] = par[par[i][j - 1]][j - 1];
  FOR(i,1,q) read();
}