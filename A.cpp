#include <bits/stdc++.h>

#define ll long long
#define str string
#define db double

#define pi pair<int, int>
#define pl pair<ll, ll>
#define pd pair<db, db>

#define vi vector<int>
#define vl vector<ll>
#define vd vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpi vector<pi>
#define vpl vector<pl>
#define vpd vector<pd>

//pairs
#define mp make_pair
#define fi first
#define se second

//vectors
#define pb push_back
#define pf push_front

//loops
#define FOR(i, a, b) for(int i=(int)a;i<=(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)

const int MODD = 1e9+7;
const ll INF = 1e18;
using namespace std;

void process()
{
  ll n,k;
  cin>>n>>k;
  ll a[k+1],tong = k;
  FOR(i,1,k) a[i] = 1;
  FOR(i,1,k)
    {
      while(true)
          {
            if (tong+a[i]>n) break;
            tong+=a[i];
            a[i]*=2;
          }
    }
  sort(a+1,a+1+k);
  if (tong==n) {
      cout<<"YES"<<endl;
      FOR(i,1,k) cout<<a[i]<<" ";
    }
  else cout<<"NO";
  cout<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

        process();

}
