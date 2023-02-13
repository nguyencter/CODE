#include<bits/stdc++.h>
#include <math.h>
#include <stack>

/*** Input Output ***/
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdb pair<db, db>
#define vi vector<int>
#define vl vector<ll>
#define vdb vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpd vector<pd>

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
  #define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MOD = 1e9+7;
using namespace std;
  vector<pair<pair<ll,ll>,ll> > v;
  ll ch[501];
ll find(ll x1){
  if (ch[x1]!=x1) return ch[x1]=find(ch[x1]);
    else return x1; 
}
bool union1(ll x,ll y){
  ll fx=find(x),fy=find(y);
  if (fx==fy) return false;
  ch[max(fx,fy)]=min(fx,fy);
  return true;
}
bool cmp(pair<pair<ll,ll>,ll> c,pair<pair<ll,ll>,ll> b){
  return c.se<b.se;
}
void solve(){
  ll n,m,min1=1e18,x;
  cin>>n>>m;
  ll a[n+9];
  FOR(i,1,n){
  	cin>>a[i];
  	if (min1>a[i]){
  		min1=a[i];
  		x=i; 
  	}
  }
  FOR(i,1,n)
    if (x!=i) v.pb(mp(mp(x,i),a[x]+a[i]));
   FOR(i,1,m){
   	ll x,y,z;
   	cin>>x>>y>>z;
   	v.pb(mp(mp(x,y),z));
   }
  FOR(i,1,n) ch[i]=i;
  sort(all(v),cmp);
  ll s=0;
  FOR(i,0,v.size()-1)     
    if (union1(v[i].fi.fi,v[i].fi.se)) s+=v[i].se;
  cout<<s;
}
int main(){ 
    IOS;
    // #ifndef ONLINE_JUDGE
    // freopen("DP_A9.INP", "r", stdin);
    // freopen("DP_A9.OUT", "w", stdout);
    // #endif
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    // int t;
    // cin>>t;
    // while(t--)
      solve();
  } 

