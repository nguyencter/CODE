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
const ll MAX = 2e6+100;
const ll LOG = 31;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll n,x;
vl v[MAX];
bool b[MAX];
void dfs(ll u){
    cout<<u<<"\n";
    b[u]=0;
    ll s=u;
    ROF(i,n-1,0){
      if (s>=(1<<i)){
        s-=((1<<i));
        if (b[u-(1<<i)]) {
            dfs(u-(1<<i));
            break;
        }
      } else {
        if (b[u+(1<<i)]) {
            dfs(u+(1<<i));
            break;
        }
      }
    }
}
void solve() {
    cin>>n;
    FOR(i,0,(1<<n)) b[i]=1;
    b[(1<<n)]=0;
    cin>>x;
    b[x]=0;
    if (x%2==0) dfs(x+1);
      else dfs(x-1);
}
int main(){
  // IOS;
  // #ifndef ONLINE_JUDGE
  // freopen("QN.inp", "r", stdin); 
  // freopen("QN.out", "w", stdout);
  // #endif
    solve();
}
