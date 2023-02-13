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
#define MASK(x) (1ll<<(x))
const ll MOD = 1e9+7;
const ll MAXN = 6e5;
const ll INF = 1e18+100;
using namespace std;
ll num[100000],low[100000],d=0,ans=0;
vl v[100000];
stack<int> st;
bool b[100000];
void dfs(int x){
  num[x]=low[x]=d++;
  st.push(x);
  FOR(i,0,v[x].size()-1)
    if (b[v[x][i]]){
      if (num[v[x][i]]==0){
        dfs(v[x][i]);
        low[x]=min(low[x],low[v[x][i]]);
      } else low[x]=min(low[x],num[v[x][i]]);
    }
  if (num[x]==low[x]){               
    ans++;
    while(st.top()!=x) {
      b[st.top()]=0;
      st.pop();
    }
    b[st.top()]=0;
    st.pop();
  }
}
void solve(){
  ll n;
    cin >> n;
    vl arr(n + 10);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0, cur = -1;
    for(int i = n - 1; i >= 1; i--) {
        if(arr[i] < arr[i - 1]) {
            cur = i - 1;
            break;
        }
    }
    map<ll, ll> m;
    for(int i = 0; i <= cur; i++) 
        m[arr[i]]++;
    for(int i = n - 1; i > cur; i--) {
        if(m[arr[i]]) {
            cur = i;
            break;
        }
    }
    for(int i = 0; i <= cur; i++) 
        m[arr[i]]++;
    for(auto x : m) 
        if(x.se != 0)
            ans++;
    cout << ans << '\n';
}
int main(){ 
  IOS;
  // #ifndef ONLINE_JUDGE
   // freopen("cauluong.INP", "r", stdin);
   // freopen("cauluong.OUT", "w", stdout);
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
