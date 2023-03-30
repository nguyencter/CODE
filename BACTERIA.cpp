#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

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
#define no cout << "No\n"
#define yes cout << "Yes\n"
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
const ll MAXN = 1e4;
const ll MAX = 1e4+100;
const ll LOG = 30;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
// using namespace __gnu_pbds;
vector <int> prime;
bool is_composite[MAXN];
void sieve () {
  std::fill (is_composite, is_composite + MAXN, false);
  for (int i = 2; i < MAXN; ++i) {
    if (!is_composite[i]) prime.push_back (i);
    for (int j = 0; j < prime.size () && i * prime[j] < MAXN; ++j) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
ll n,m,c;
map<int,int> a,b;
bool kt=0;
void solve() {
  cin>>n>>m>>c;
  if (m>c||n>c){
    cout<<"Impossible";
    return;
  }
  ll i=0,x=n;
  while(x!=1){
    if (x%prime[i]!=0) i++;
      else {
        x/=prime[i];
        a[prime[i]]++;
        b[prime[i]]=0;
      }
  }
  i=0;x=m;
  while(x!=1){
    if (x%prime[i]!=0) i++;
      else {
        x/=prime[i];
        b[prime[i]]++;
        if (b[prime[i]]>a[prime[i]]) kt=1;
        if (a[prime[i]]==0){
          cout<<"Impossible";
          return;
        }
      }
  } 
  vl v,f[100];
  if (n==m) {
    cout<<0;
    return;
  }
    else if (!kt){
      for(auto x:a){
        while(x.se>b[x.fi]){
          v.pb(x.fi);
          x.se--;
        }
      }
    } else {
      ll max1=0;
      for(auto x:b)
        if (x.se>a[x.fi]){
          FOR(i,1,1000)
            if ((1<<i)*a[x.fi]>=x.se){
              max1=max(max1,i*1ll);
              break;
            }
        }
      for(auto x:b){
        ll y=(1<<max1)*a[x.fi]-x.se,k=max1;
        while(y!=0){
          while(y>=(1<<k)){
            f[max1-k].pb(x.fi);
            y-=(1<<k);
          }
          k--;
        }
      }
      FOR(i,0,max1){
        FOR(j,0,f[i].size()-1) v.pb(f[i][j]);
        v.pb(0);
      }
      v.pop_back();
    }
  cout<<v.size()<<"\n";
  FOR(i,0,v.size()-1) cout<<v[i]<<" ";
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("BACTERIA.inp", "r", stdin); 
  freopen("BACTERIA.out", "w", stdout);
  #endif
  sieve();
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
