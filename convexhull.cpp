#include <bits/stdc++.h>
 
#define ll long long
#define str string
#define db double
 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdb pair<db, db>
 
#define vi vector<int>
#define vl vector<ll>
#define vdb vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpdb vector<pdb>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
 
//pairs
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front
 
//loops
#define FOR(i, a, b) for(int i=(int)a;i<(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a-1;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)
 
const int MOD = 1e9+7;
const ll INF = 1e18;

using namespace std;

struct TPoint{
    ll x, y;
};

#define TVector  TPoint

ll SqrLen(const TVector& u){
    return u.x*u.x+u.y*u.y;
}

TVector operator +(const TVector& u, const TVector& v){
    TVector t={u.x+v.x, u.y+v.y};
    return t;
}

TVector operator -(const TVector& u, const TVector& v){
    TVector t={u.x-v.x, u.y-v.y};
    return t;
}

ll operator *(const TVector& u, const TVector& v){
    ll t=u.x*v.x+u.y*v.y;
    return t;
}

ll operator /(const TVector& u, const TVector& v){
    ll t=u.x*v.y-u.y*v.x;
    return t;
}

const int MAXN = 1e5+5;
ll n, m;
TPoint p[MAXN], q[MAXN], A;

bool CCW(const TPoint& D, const TPoint& E, const TPoint& F){
    return (E - D) / (F - E) > 0;
}

bool cmp(const TPoint& B, const TPoint& C){
    TPoint u = B-A, v = C-A;
    ll temp = u/v;
    return temp > 0 || (temp == 0 && SqrLen(u) < SqrLen(v));
}

void GrahamScan(){
    sort(p+1, p+n, cmp);
}

void BuildConvexHull(){
    m = 0;
    for(int i = 0; i < n; i++){
        while (m >= 2 && !CCW(q[m - 2], q[m - 1], p[i]))
            --m;
        q[m++] = p[i];
    }
}


void solve(){
    
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    //freopen("allstars.inp", "r", stdin);
    //freopen("allstars.out", "w", stdout);
    #endif
    solve();
}