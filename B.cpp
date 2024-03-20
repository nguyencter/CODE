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

const ll MOD = 1e9+7;
const ll MAXN=1e6;
const ll INF = 1e18;
using namespace std;

void solve(){
  int n,m;
  cin>>n>>m;
  vl v[100001],u[100000],a;
  ll s=0;
  FOR(i,1,n)
  FOR(j,1,m){
    ll x;
    cin>>x;
    if (v[x].size()==0) a.pb(x);
    v[x].pb(i);
    u[x].pb(j);
  }
  FOR(i,0,a.size()-1){
    sort(v[a[i]].begin(),v[a[i]].end());
    sort(u[a[i]].begin(),u[a[i]].end());
    ll x=0,y=0;
    FOR(j,0,v[a[i]].size()-1){
      s+=v[a[i]][j]*j-x+u[a[i]][j]*j-y;
      x+=v[a[i]][j];y+=u[a[i]][j];
    }
  }
  cout<<s<<"\n";
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
  solve();
} 
