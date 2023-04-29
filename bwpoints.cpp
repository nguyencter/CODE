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
const ll MAXN = 1e6;
const ll MAX = 1e6+100;
const ll LOG = 30;
const ll INF = 1e18;
using namespace std;
using namespace __gnu_pbds;
ll n,a[MAX],b[MAX];
void solve(){
  cin>>n;
  FOR(i,1,n) cin>>a[i];
  FOR(i,1,n) cin>>b[i];
  sort(a+1,a+n+1);
  sort(b+1,b+n+1);
  ll x=1,y=1,d=0;
  b[n+1]=1e9;
  a[n+1]=1e9;
  while(x<=n&&y<=n){
    d++;
    if (a[x]>b[y]){
      while(b[y]<a[x]) y++;
      x++;
    } else {
      while(a[x]<b[y]) x++;
      y++;
    }
  }
  cout<<d<<"\n";
}
int main(){
  IOS;
  // #ifndef ONLINE_JUDGE   
    freopen("BWPOINTS.INP", "r", stdin);
    freopen("BWPOINTS.OUT", "w", stdout);
  // #endif
  // #ifndef ONLINE_JUDGE
  // freopen("input.inp", "r", stdin); 
  // freopen("output.out", "w", stdout);
  // #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
