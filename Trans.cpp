#include<bits/stdc++.h>
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
const ll MAXN = 1e6+100;
const ll MAX = 2e3+100;
const ll LOG = 31;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll a,b,d,f[MAX],f1[MAX];
vl v,v1;
void solve() {
    cin>>a>>b>>d;
    ll x=__gcd(a,b);
    a/=x;
    b/=x;
    v.pb(0);
    v1.pb(0);
    FOR(i,1,trunc(sqrt(a)))
      if (a%i==0){
        v.pb(i);
        if (trunc(sqrt(a))!=i||trunc(sqrt(a))!=sqrt(a)) v.pb(a/i);
      }
    sort(all(v));
    FOR(i,1,trunc(sqrt(b)))
      if (b%i==0){
        v1.pb(i);
        if (trunc(sqrt(b))!=i||trunc(sqrt(b))!=sqrt(b)) v1.pb(b/i);
      }
    sort(all(v1));
    f[1]=0;
    FOR(i,2,v.size()-1){
        f[i]=INF;
        ROF(j,i-1,1)
          if (v[i]/v[j]>d) break;
            else if (v[i]%v[j]==0&&f[j]>=0) f[i]=min(f[i],f[j]+1ll);
        if (f[i]==INF) f[i]=-1;
    }
    f1[1]=0;
    FOR(i,2,v1.size()-1){
        f1[i]=INF;
        ROF(j,i-1,1)
          if (v1[i]/v1[j]>d) break;
            else if (v1[i]%v1[j]==0&&f1[j]>=0) f1[i]=min(f1[i],f1[j]+1ll);
        if (f1[i]==INF) f1[i]=-1;
    }
    if (f[v.size()-1]<0||f1[v1.size()-1]<0){
        cout<<-1;
        return;
    }
    cout<<f[v.size()-1]+f1[v1.size()-1];
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("Trans.inp", "r", stdin); 
  freopen("Trans.out", "w", stdout);
  #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
