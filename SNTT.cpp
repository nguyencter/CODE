//SNT
bool snt(ll k) {
    if(k == 2 || k == 3 || k == 5) return true;
    if(k == 1) return false;
    if(k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return false;
    ll i = 5 ;
    while (i <= round(sqrt(k))) {
        if(k % i == 0 || k % (i-2) == 0 || k % (i+2) == 0) return false;
        i += 6 ;
    }
    return true;
}
// SANG NT
vector <int> prime;
bool is_composite[MAXN];
void sieve () {
  std::fill (is_composite, is_composite + MAXN, false);
  for (int i = 2; i < MAXN; ++i) {
    if (!is_composite[i]) prime.push_back (i);
    for (int j = 0; j < prime.size () && i * prime[j] < MAXN; ++j) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
//TOA DO
C:=Sqrt(Sqr(A[i]-A[j])+Sqr(B[i]-B[j]);
//--------------------------------------------------
void makeSet(int n){
  FOR(i,1,n) f[i]=i;
}
int find(int a){
  if (a==f[a]) return a;
    else return f[a]=find(f[a]);
}
void Union(int a,int b){
  if (find(a)==find(b)) return;
    else return f[b]=find(a);
}
//
  ull n,x,m,k;
ull mul(ull x,ull y){
    if (y==0) return 0;
    ull t=mul(x,y/2);
    if (y%2==0) return (t+t)%m;
      else return (t+t+x)%m;
}
ull power(ull x){
    if (x==0) return 1%m;
    ull t=power(x/2);
    if (x%2==0) return mul(t,t);
      else return (mul(t,t)*10)%m;
}
//---------------------------------------------
template <class T> inline T sqr(T x) { return x * x; };
template <class T> inline ll Power(T x, ll y) { if (!y) return 1; if (y & 1) return sqr(Power(x, y / 2)) % MOD * x % MOD; return sqr(Power(x, y / 2)) % MOD; }
ll C(ll n,ll k){
  return a1[n]*Power(a1[k]*a1[n-k]%MOD,MOD-2)%MOD;
}
//CONVERT
str convert(ll x){
  str s1="";
  while (x!=0){
    char x1='0'+x%10;
    x/=10;
    s1=x1+s1;
  }
  return s1;
}
//Random------------------------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//------------------------------------------
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
//-----------------------------------------
long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k % 2) {
      res = (res * cur) % p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}
int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;

  while (u <= temp) {
    degree_num += temp / u;
    u *= p;
  }
  return degree_num;
}

long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n, p) - get_degree(n - k, p);
  int den_degree = get_degree(k, p);

  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n - k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * ti) % p;
  }
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * degree(ti, p-2, p)) % p;
  }
  return res;
}
//------------------------------------
for(int i=0;i<=k;i++){
    bigint x=power(k-i,n)*(a1[k]/(a1[i]*a1[k-i]));
    if (i&1) ans-=x;
      else ans+=x;
  }