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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll MOD = 1e9+7;
const ll MAXN = 2e6+1e4;
const ll MAX = 2e5+10;
const ll LOG = 30;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
// using namespace __gnu_pbds;
ll n,k,s,m;
map<str,vector<str> > m1;
map<str,int> a;
deque<str> f;
vector<str> v;
void solve() {
  cin>>n>>k>>s>>m;
  FOR(i,1,s){
    str s1;
    cin>>s1;
    a[s1]=k+1;
    f.pb(s1);
  }
  FOR(i,1,m){
    str s1,s2;
    cin>>s1>>s2;
    m1[s1].pb(s2);
    m1[s2].pb(s1);
  }
  while(f.size()){
    str s1=f.front();
    v.pb(s1);
    f.pop_front();
    sort(all(m1[s1]));
    if (m1[s1].size()!=0){
      a[m1[s1][0]]++;
      if (a[m1[s1][0]]==k) f.pb(m1[s1][0]);
    }
    FOR(i,1,m1[s1].size()-1)
      if (m1[s1][i]!=m1[s1][i-1]){
        a[m1[s1][i]]++;
        if (a[m1[s1][i]]==k) f.pb(m1[s1][i]);
      }
  }
  cout<<v.size()<<"\n";
  sort(all(v));
  FOR(i,0,v.size()-1) cout<<v[i]<<" ";
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("specone.inp", "r", stdin); 
  freopen("specone.out", "w", stdout);
  #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
