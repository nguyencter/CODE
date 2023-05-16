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
const ll MOD = 1e9+7;
const ll MAXN = 1e6;
const ll MAX = 1e6+100;
const ll LOG = 30;
const ll INF = 1e18;
using namespace std;
ll v[MAX][26],d=1,s=0;
void insert(str s){
  ll x1=1;
  FOR(i,0,s.size()-1){
    ll x=s[i]-'a';
    if (!v[x1][x]) v[x1][x]=++d;
    x1=v[x1][x];
  }
}
void dfs(ll x,ll y){
  FOR(i,0,25){
    if (v[y][i]) {
      dfs(y,v[y][i]);
      s+=2;
    }
  }
}
void solve(){
  ll n,j=0,max1=0;
  cin>>n;
  memset(v,0,sizeof(v));
  FOR(i,1,n){
    str s;
    cin>>s;
    // cout<<s<<"\n";
    ll x=s.size();
    max1=max(max1,x);
    insert(s);
  }
  FOR(i,0,25)
    if (v[1][i]) {
      dfs(i,v[1][i]);
      s+=2;
    }
  cout<<s+n-max1;
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("Printer.inp", "r", stdin); 
  freopen("Printer.out", "w", stdout);
  #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
