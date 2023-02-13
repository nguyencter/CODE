#include<bits/stdc++.h>
#include <math.h>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <stdio.h>
#include <vector>

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
#define mod 111539786
#define pi acos(-1.0)
#define EPS 1e-7
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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll MOD = 1e9+7;
const ll MAXN = 1e6+100;
const ll MAX = 1e5+10;
const ll LOG = 30;
const ll INF = 1e18;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
// using namespace __gnu_pbds;
// a -> z

struct TrieNode
{
    TrieNode* child[26];
    int cnt;
    TrieNode()
    {
        for (int i = 0; i < 26; ++i) child[i] = NULL;
        cnt = 0;
    }
} *root = new TrieNode();

void Insert(string s)
{
    TrieNode* p = root;

    for (char v : s)
    {
        int nxt = v - 'a';

        if (p->child[nxt] == NULL) p->child[nxt] = new TrieNode();

        p = p->child[nxt];
    }

    ++p->cnt;
}

bool Find(string s)
{
    TrieNode* p = root;
    for (char v : s)
    {
        int nxt = v - 'a';

        if (p->child[nxt] == NULL) return false;

        p = p->child[nxt];
    }

    return p->cnt > 0;
}

void Delete(string s)
{
    TrieNode* p = root;

    for (char v : s)
    {
        int nxt = v - 'a';

        if (p->child[nxt] == NULL) return;

        p = p->child[nxt];
    }

    if (p->cnt > 0) p->cnt--;
}


void solve(){
  ll n;
  vector<string> v,f;
  cin>>n;
  map<str,bool> m;
  bool kt=1;
  FOR(i,1,n){
    str s,s1="";
    char x;
    cin>>s;
    x=s[0];
    s.erase(0,1);
    if (x=='+'){
      Insert(s);
    } else v.pb(s);
  }
  FOR(i,0,v.size()-1){
    str s="";
    if (Find(v[i])) kt=0;
    FOR(j,0,v[i].size()-1){
      s+=v[i][j];
      if (m[s]) break;
      if (!Find(s)){
        f.pb(s);
        m[s]=1;
        break;
      }
    }
  }
  if (!kt) cout<<-1<<"\n";
    else {
      sort(all(f));
      cout<<f.size()<<"\n";
      FOR(i,0,f.size()-1) cout<<f[i]<<"\n";
    }
}  
int main(){
  IOS;
  // #ifndef ONLINE_JUDGE   
    // freopen("SWAP.INP", "r", stdin);
    // freopen("SWAP.OUT", "w", stdout);
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
