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
const ll MAXN = 1e6+100;
const ll MAX = 1e3+100;
const ll LOG = 31;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll n,a[MAX][MAX],f[MAX],ans[MAX];
vl v;
bool kt;
bool cmp(ll x,ll y){
    if (f[x]!=f[y]) return f[x]<f[y];
      else return x<y;
}
void recur(){
    sort(all(v),cmp);
    if (f[v[0]]==0) return;
    if (v.size()==1){
        // cout<<v[0]<<" "<<f[v[0]]<<"\n";
        FOR(i,1,n)
          if (a[v[0]][i]){
            ans[v[0]]=i;
            // cout<<i<<"\n";
            break;
          }
        kt=1;
        return;
    }
    ll x=v[0],f1=f[x];
    swap(v[0],v[v.size()-1]);
    v.pop_back();
    FOR(j,1,n)
      if (a[x][j]){
        vpll v1;
        f[x]=0;
        FOR(i,1,n)
          if (a[i][j]&&f[i]!=0){
            f[i]--;
            a[i][j]=0;
            v1.pb(mp(i,j));
          }
        ll x1=x,y=j;
        while(x1<=n&&y<=n){
            if (a[x1][y]&&f[x1]!=0){
                f[x1]--;
                a[x1][y]=0;
                v1.pb(mp(x1,y));
            }
            x1++;y++;
        }
        x1=x,y=j;
        while(x1<=n&&y>0){
            if (a[x1][y]&&f[x1]!=0){
                f[x1]--;
                a[x1][y]=0;
                v1.pb(mp(x1,y));
            }
            x1++;y--;
        }
        ans[x]=j;
        // cout<<x<<" "<<j<<"\n";
        recur();
        if (kt) return;
        FOR(i,0,v1.size()-1){
            f[v1[i].fi]++;
            a[v1[i].fi][v1[i].se]=1;
        }
      }
    v.pb(x);
    f[x]=f1;
}
void solve() {  
    while(cin>>n){
        FOR(i,1,n){
            f[i]=n;
            FOR(j,1,n) a[i][j]=1;
        }
        FOR(i,1,n) {
            ll x;
            cin>>x;
            if (x!=0){
                ans[i]=x;
                f[i]=0;
                FOR(ii,1,n)
                  if (a[ii][x]&&f[ii]!=0) {
                    f[ii]--;
                    a[ii][x]=0;
                  }
                ll x1=i-min(x,i*1ll)+1,y=x-min(x,i*1ll)+1;
                // cout<<x1<<" "<<y<<"\n";
                while(x1<=n&&y<=n){
                  if (a[x1][y]&&f[x1]!=0) {
                    f[x1]--;
                    a[x1][y]=0;
                  }
                  x1++;y++;
                }
                x1=i-min(x,i*1ll),y=x+min(x,i*1ll);
                // cout<<x1<<" "<<y<<"\n";
                while(x1<=n&&y>0){
                  if (a[x1][y]&&f[x1]!=0) {
                    f[x1]--;
                    a[x1][y]=0;
                  }
                  x1++;y--;
                }
            }
        }
        // FOR(i,1,n) cout<<f[i]<<" ";en;
        v.clear();
        FOR(i,1,n) 
          if (f[i]!=0) v.pb(i);
        kt=0;
        recur();
        FOR(i,1,n) cout<<ans[i]<<" ";en;
        // FOR(i,0,v.size()-1) cout<<f[v[i]]<<" ";en;
        // FOR(i,1,n){
        //     FOR(j,1,n) cout<<a[i][j]<<" ";en;
        // }
    }
}  
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("NQUEEN2.inp", "r", stdin); 
  freopen("NQUEEN2.out", "w", stdout);
  #endif
  int t=1;
  // cin>>t;
  while(t--)
    solve();
}
