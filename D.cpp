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
const ll MAXN = 1e7;
const ll MAX = 5e3+100;
const ll LOG = 30;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll n,dp[MAX][MAX];
vl v,v1;
void solve() {
    cin>>n;
    v.pb(0);
    v1.pb(0);
    FOR(i,1,n) {
        ll x;
        cin>>x;
        if (x) v.pb(i);
          else v1.pb(i);
    }
    if (v.size()==1){
        cout<<0;
        return;
    }
    memset(dp,0x3f,sizeof(dp));
    FOR(i,1,v1.size()-1)
      dp[1][i]=min(abs(v1[i]-v[1]),dp[1][i-1]);
    FOR(i,2,v.size()-1)
      FOR(j,i,v1.size()-1) dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(v[i]-v1[j]));
    // ll x=4557430888798830399;
    // FOR(i,1,v.size()-1)
    //   FOR(j,1,v1.size()-1)
    //     if (dp[i][j]==x) dp[i][j]=0;
    // FOR(i,1,v.size()-1)
    //   {FOR(j,1,v1.size()-1) cout<<dp[i][j]<<" ";en;}
    cout<<dp[v.size()-1][v1.size()-1];
}
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("input.inp", "r", stdin); 
  freopen("output.out", "w", stdout);
  #endif
  // int t;
  // cin>>t;
  // while(t--)
    solve();
}
