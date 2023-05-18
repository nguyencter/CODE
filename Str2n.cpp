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
const ll MAX = 1e6+100;
const ll LOG = 31;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll n,j=0;
str f[MAX],s;
map<str,vl> m;
bool cmp(str x,str y){
    return x.size()>y.size();
}
void solve() {
    cin>>n;
    FOR(i,1,n*2){
        cin>>s;
        if (!m[s].size()) j++,f[j]=s;
        m[s].pb(i);
    }
    sort(f+1,f+j+1,cmp);
    FOR(i,1,j){
        while(m[f[i]].size()>1){
            cout<<m[f[i]].back()<<" ";
            m[f[i]].pop_back();
            cout<<m[f[i]].back()<<" ";
            m[f[i]].pop_back();en;
        }
        if (m[f[i]].size()==1){
            cout<<m[f[i]].back()<<" ";
            m[f[i]].pop_back();
            f[i].erase(f[i].size()-1,1);
            while(!m[f[i]].size()) f[i].erase(f[i].size()-1,1);
            cout<<m[f[i]].back()<<" ";
            m[f[i]].pop_back();en;  
        }
    }
}  
int main(){
  IOS;
  #ifndef ONLINE_JUDGE
  freopen("Str2n.inp", "r", stdin); 
  freopen("Str2n.out", "w", stdout);
  #endif
  int t=1;
  // cin>>t;
  while(t--)
    solve();
}
