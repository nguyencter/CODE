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
const ll MAXN = 1e5;
const ll MAX = 2e5+100;
const ll LOG = 30;
const ll INF = 1e18;
using namespace std;
using namespace __gnu_pbds;
ll ch[MAX],f[1000][1000];
  ll n,m,s,t;
ll bfs(ll x,ll y){
  memset(ch,-1,sizeof(ch));
  ch[x]=-2;
  queue<pll> q;
  q.push(mp(x,INF));
  ll d=0;
  while(!q.empty()){
    ll x1=q.front().fi,y1=q.front().se;
    q.pop();
    FOR(i,1,n)
      if (f[x1][i]>0&&ch[i]<0){
        ch[i]=x1;
        ll min1=min(f[x1][i],y1);
        if (i==y) return min1;
        q.push(mp(i,min1));
      }
  }
  return 0;
}
ll maxFlow(ll s,ll t){
  ll flow=0,d1=0,newFlow;
  while(newFlow=bfs(s,t)){
    d1++;
    flow+=newFlow;
    ll cur=t;
    // cout<<newFlow<<"\n\n";
    while(cur!=s){
      ll pre=ch[cur];
      // cout<<cur<<"\n";
      f[pre][cur]-=newFlow;
      f[cur][pre]+=newFlow;
      cur=pre;
    }
    // en;en;
  }
  // cout<<d1<<"\n";
  return flow;
}
void solve(){
  cin>>n>>m>>s>>t;
  memset(f,0,sizeof(f));
  FOR(i,1,m){
    ll x,y,z;
    cin>>x>>y>>z;
    f[x][y]=z;
  }
  cout<<maxFlow(s,t);en;
}
int main(){
  IOS;
  // #ifndef ONLINE_JUDGE   
    // freopen("gstree.INP", "r", stdin);
    // freopen("gstree.OUT", "w", stdout);
  // #endif
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
    solve();
}
