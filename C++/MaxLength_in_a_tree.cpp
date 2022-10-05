#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz(x) x.size()
#define pb push_back
#define pb2 pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bend(x) x.begin(), x.end()
#define vi vector<ll>
#define mapp map<ll, ll>
#define sett set<ll>
#define ve vector
#define un_m unordered_map<ll, ll>
#define f(i, a, b) for (i = a; i < b; i++)
#define f2(i, a) for (auto i = a.begin(); i != a.end(); i++)
#define maxxx INT32_MAX
#define mp make_pair
#define in(t) scanf("%lld",&t)
#define out(t) printf("%lld",t)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PQ priority_queue
#define ts(s) to_string(s)
#define umapp unordered_map<ll,ll>
/*
    stringstream geek(str);
    nn=0;
    geek>>nn;
     int n,i,j,k,tt=0,sum=0,ans=0;
    double d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));

*/
const unsigned int moduli = 1000000007;
vi arr[100001];
ll vis[100001];

ll maxd,maxn;
void dfs(ll node,ll d){
    vis[node]=1;
    if(d>maxd) maxd=d,maxn=node;
    for(auto tt:arr[node]){
        if(vis[tt]==0) dfs(tt,d+1);
    }

}
void sol() {

    ll dd,ds,e=0,x,n,k;
    ll i,j,tt=0,ww=0,t,y;
    ll cnt=0,m,ans=0,sum=0;
    cin>>n;
    ll a,b;
    f(i,0,n-1){
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    maxd=-1;
    dfs(1,0);
    
    f(i,0,n) vis[i]=0;

    maxd=-1;
    dfs(maxn,0);
    cout<<maxd;
    return;
}

// driver function

int main() {
    ll tc=1;// cin >> tc;
    while (tc--) {
        sol();
        cout << endl;
    }

   return 0;
}
