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
const ll MAXN = 1e2;
const ll MAX = 5e3+100;
const ll LOG = 30;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
// using namespace __gnu_pbds;

void solve() {
  ll p1,p2,p3,t1,t2,t3,ans=0,min1;
  cin>>p1>>p2>>p3>>t1>>t2>>t3;
  // cout<<p1<<" "<<p2<<" "<<p3<<" "<<t1<<" "<<t2<<" "<<t3<<"\n";
  min1=min(p3,t3);
  ans+=9*min1;
  p3-=min1;t3-=min1;

  min1=min(p3,min(t1,t2));
  ans+=9*min1;
  p3-=min1;t1-=min1;t2-=min1;

  min1=min(p3,t1/3);
  ans+=9*min1;
  p3-=min1;t1-=3*min1;

  // min1=min(p1/3,t3);
  // ans+=9*min1;
  // p1-=min1*3;t3-=min1;

  min1=min(min(p1,p2),t3);
  ans+=9*min1;
  p1-=min1;p2-=min1;t3-=min1;

  min1=min(min(p1,p3),t2/2);
  ans+=12*min1;
  p1-=min1;p3-=min1;t2-=2*min1;

  min1=min(min(t1,t3),p2/2);
  ans+=12*min1;
  t1-=min1,t2-=min1;p2-=2*min1;

  min1=min(p2/3,t3/2);
  ans+=24*min1;
  p2-=min1*3;t3-=min1*2;

  min1=min(t2/3,p3/2);
  ans+=24*min1;
  t2-=min1*3;p3-=min1*2;

  min1=min(p2,t2);
  ans+=4*min1;
  p2-=min1;t2-=min1;

  min1=min(p2,t1/2);
  ans+=4*min1;
  p2-=min1;t1-=min1*2;

  min1=min(p1,t1);
  ans+=min1;
  p1-=min1;t1-=min1;

  min1=min(p1/2,t2);
  ans+=4*min1;
  p1-=min1*2;t2-=min1;

  cout<<ans<<"\n";
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  // #else 
  freopen("ANTPATH.inp", "r", stdin); 
  freopen("ANTPATH.out", "w", stdout);
  #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
