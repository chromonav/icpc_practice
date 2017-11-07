#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <utility>
#include <cassert>
#include <complex>
#include <algorithm>

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
#define sz(x) (int)((x).size())
#define X first
#define Y second
#define sqr(x) ((x) * (x))
#define bit(i) (1 << (i))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define mp make_pair
#define pb push_back
 #define MOD 1000000007
#define cnb(x) __builtin_popcount(x)
#define cnlz(x) __builtin_clz(x)
#define cnlzll(x) __builtin_clzll(x)
#define cntz(x) __builtin_ctz(x)
#define cntzll(x) __builtin_ctzll(x)

typedef double DB;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<DB> VDB;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;

template <class T> inline void chkmax(T &a, T b) {
    if (a < b) a = b;
}
template <class T> inline void chkmin(T &a, T b) {
    if (b < a) a = b;
}

#define MN 100004
long long ans[1000010];
long long arr[1000010];
bool f[1000010];
int main()
 {
  int t;
  cin>>t;
  while(t--) 
  {
   for(int i=0;i<=1000002 ;i++)
   {    
         ans[i]=0;
         f[i]=0;
   }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     {
              cin>>arr[i];
              ans[arr[i]]=1;
              f[arr[i]]=true;
     }
     for(long long i=1;i<=1000000;i++) 
      {
               if(f[i]==1)
                   for(long long j=i*1LL*2;j<=1000000;j+=i) 
                  {
                      ans[j] = (ans[j]+1LL*ans[i])%MOD;
                   }
      }
    long long res=0;
    for(int i=1;i<=1000000;i++) 
    {
           if(f[i])    
                res=(res+ans[i])%MOD;
    }
    if(ans[0]==1)
    {
        res*=2;
        res++;
    }
    cout<<res<<endl;
  }
  return 0;
}