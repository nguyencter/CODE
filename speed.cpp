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
const ll MAXN = 2e5;
const ll MAX = 3e5;
const ll LOG = 30;
const ll INF = 1e18;
using namespace std;
using namespace __gnu_pbds;
ll ch[MAX];
ll findA(ll x){
  if (x==ch[x]) return x;
    else return ch[x]=findA(ch[x]);
}
bool union1(ll x,ll y){
  ll fx=findA(x),fy=findA(y);
  if (fx==fy) return 0;
  ch[max(fx,fy)]=min(fx,fy);
  return 1;
}
bool cmp(pair<pll,ll> x,pair<pll,ll> y){
  return x.se<y.se;
}
void solve(){
  ll n,m,x=-1e9,y=1e9;
  cin>>n>>m;
  pair<pll,ll> a[m+89];
  FOR(i,1,m) cin>>a[i].fi.fi>>a[i].fi.se>>a[i].se;
  sort(a+1,a+m+1,cmp);
  FOR(i,1,m){
    FOR(ii,1,n) ch[ii]=ii;
    ll min1=a[i].se,d=n;
    FOR(j,i,m)
      if (union1(a[j].fi.se,a[j].fi.fi)){
        d--;
        min1=max(min1,a[j].se);
      }
    if (d==1&&y-x>min1-a[i].se){
        x=a[i].se;
        y=min1;
    }
  }
  cout<<x<<" "<<y;
}
int main(){
  IOS;  
  // #ifndef ONLINE_JUDGE   
      freopen("speed.INP", "r", stdin);
      freopen("speed.OUT", "w", stdout);
  // #endif 
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  // #endif
  // int t;
  // cin>>t;
  // while(t--)  
    solve();
}
