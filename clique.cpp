#include<bits/stdc++.h>
#include <math.h>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll MOD = 1e9+7;
const ll MAXN = 1e5;
const ll MAX = 3e3+100;
const ll LOG = 30;
const ll INF = 1e18;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll m,k,n,d[MAX],s[MAX];
bool a[MAX][MAX],kt=0;
bool check(ll p){
  FOR(j,1,p-1) 
    if (!a[s[j]][s[p]]) return 0;
  return 1;
}
void kq(){
  kt=1;
  FOR(i,1,k) cout<<s[i]<<" ";en;
}
void recur(ll j,ll d1){
  FOR(i,j+1,n-k+d1){
    if (kt) return;
    if (d[i]>=k-1){
      s[d1]=i;
      if (check(d1)){
        if (d1<k) recur(i,d1+1);
          else kq();
        if (kt) return;
      }
    }
  }
}
void solve(){
  cin>>n>>m>>k;
  memset(a,0,sizeof(a));
  memset(d,0,sizeof(d));
  kt=0;
  FOR(i,1,m){
    ll x,y;
    cin>>x>>y;
    a[x][y]=1;
    a[y][x]=1;
    d[x]++;
    d[y]++;
  }
  recur(0,1);
  if (kt==0) cout<<"-1\n"; 
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE   
    freopen("clique.INP", "r", stdin);
    freopen("clique.OUT", "w", stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
    solve();
}
