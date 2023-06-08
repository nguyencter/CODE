#include <bits/stdc++.h>
#pragma GCC("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define ll  long long
#define db  double
#define vl  vector<ll>
#define pll  pair<ll, ll>
#define vpll  vector<pll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define __lcm(a, b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define BIT(x, i) (((x) >> (i)) & 1) 

#define PROBLEM "cmat"

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int mod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
const double eps = 1e-9;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// ---------------------------------------- 
struct queries {
    int x, y, u, v, c;
};

void solve() {
    int n, m;
    cin >> n >> m;

    int arr[n + 11][m + 11], sum[n + 11][m + 11];
    int preUL[n + 11][m + 11], preDR[n + 11][m + 11];

    memset(sum, 0, sizeof(sum));
    memset(preUL, 0, sizeof(preUL));
    memset(preDR, 0, sizeof(preDR));

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int query;
    cin >> query;
    queries q[query];

    for(int i = 0; i < query; i++) {
        cin >> q[i].x >> q[i].y >> q[i].u >> q[i].v >> q[i].c;

        int a = q[i].x, b = q[i].y, c = q[i].u, d = q[i].v;     

        sum[a][b] += q[i].c;

        sum[a][d + 1] -= q[i].c;

        sum[c + 1][b] -= q[i].c;

        sum[c + 1][d + 1] += q[i].c;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];  

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            sum[i][j] += arr[i][j];
    
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            preUL[i][j] = max({sum[i][j], preUL[i - 1][j - 1], preUL[i - 1][j], preUL[i][j - 1]});

    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--) 
            preDR[i][j] = max({sum[i][j], preDR[i + 1][j + 1], preDR[i + 1][j], preDR[i][j + 1]});

    int ans = 2e9, maxOut, maxIn;

    for(int i = 0; i < query; i++) {
        int a = q[i].x, b = q[i].y, c = q[i].u, d = q[i].v;     

        maxOut = max({preUL[a - 1][m], preUL[n][b - 1], preDR[c + 1][1], preDR[1][d + 1]});

        maxIn  = min(preUL[c][d], preDR[a][b]);
        
        ans = min(ans, max(maxOut, maxIn - q[i].c));
    }

    cout << ans << '\n';
}

int main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    if (fopen(PROBLEM".inp", "r")){
        freopen(PROBLEM".inp", "r", stdin);
        freopen(PROBLEM".out", "w", stdout);
    }
    bool ok = false;
    if(ok) {
        int t; cin >> t;
        while(t--)  solve();
    }   
    else
        solve();
}