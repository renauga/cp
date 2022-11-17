#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// PRAGMAS (do these even work?)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

// DEFINE STATEMENTS
const long long inf = 1e18;
const int infi = 1e9;
#define num1 1000000007
#define num2 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define REPd(i,a,n) for(ll i=a; i>=n; i--)
#define pb push_back
#define pob pop_back
#define f first
#define sec second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.000000001)
#define popcount __builtin_popcountll
#define fileio(x) freopen("input.txt", "r", stdin); freopen(x, "w", stdout);
#define out(x) cout << ((x) ? "YES\n" : "NO\n")
#define sz(x) x.size()
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now();
#define measure() auto end_time = std::chrono::high_resolution_clock::now(); cerr << (end_time - start_time)/std::chrono::milliseconds(1) << "ms" << endl;
 
 
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vii;

// DEBUG FUNCTIONS 
#ifndef ONLINE_JUDGE

template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}

}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}

template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif

// CUSTOM HASH TO SPEED UP UNORDERED MAP AND TO AVOID FORCED CLASHES
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  //use rng() to get a random number


int log2n(ll n) {
	return (63-__builtin_clzll(n));
}

/* tree stuff, required for binary lifting
call dfs_calc(1,0)


int LOGN = 18; //will be log2n(n-1)+1 or ceiling of log2n(n)
ll MAXN = 100000;
ll n;
vector<vector<int>> g;
vector<ll> depth(MAXN+1,0);
vector<vector<int>> up(MAXN+1,vector<int>(LOGN,0));//max lift is 2^(LOGN)-1

void dfs_calc(int node, int parent) {
	if(node!=1) depth[node]=depth[parent]+1;
	up[node][0]=parent;
	for(int i=1;i<LOGN;i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(int child:g[node]) {
		if(child!=parent) {
			dfs_calc(child,node);
		}
	}
}

int kthancestor(int a, int k) {
	for(int i=0;i<LOGN;i++) {
		if(k&(1<<i)) {
			a = up[a][i];	
		}
	}
	return a;
}

int lca(int a, int b) {
	if(depth[a]<depth[b]) {
		swap(a,b);
	}
	int diff = depth[a]-depth[b];
	a = kthancestor(a,diff);
	if(a==b) return a;
	for(int step=LOGN-1;up[a][0]!=up[b][0];step--) {
		if(up[a][step]!=up[b][step]) {
			a = up[a][step];
			b = up[b][step];
		}
	}
	return up[a][0];
}

int distance(int a, int b) {
	return depth[a]+depth[b]-2*depth[lca(a,b)];
}

*/


ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0; //xa+yb=a at all times
    ll q, x1 = 0, y1 = 1; //x1a+y1b=b at all times
    while (a&&b) {
		if(a>b) {
			q = a/b;
			x -= q*x1;
			y -= q*y1;
			a -= q*b;
		} else {
			q = b/a;
			x1 -= q*x;
			y1 -= q*y;
			b -= q*a;
		}
    }
	if(a==0){
		x=x1;
		y=y1;
		return b;
	}
    return a;
}

const int mod = 1e9+7;

struct mint {
    ll x;
    mint() : x(0) {}
    mint(ll y) {
        if(y>=0&&y<mod) x=y;
        else {
			x=y%mod;
        	if(x<0) x+=mod;
		}
    }
    mint operator-() {return mint(-x+mod);}
    mint operator ~() const {ll a,b; extgcd(x,mod,a,b); return a;}
    mint& operator+=(const mint& a) {if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a) {if((x-=a.x)<0) x+=mod; return *this;}
    mint& operator*=(const mint& a) {x=(x*a.x)%mod; return *this;}
    mint& operator/=(const mint& a) {this->operator*=(~a);return *this;}
    mint operator ++() { ++x; if(x == mod) x = 0; return (*this); }
	mint operator ++(int) { x++; if(x == mod) x = 0; return mint(x-1); }
	mint operator --() { --x; if(x == -1) x = mod-1; return (*this); }
	mint operator --(int) { x--; if(x == -1) x = mod-1; return mint(x+1); }
    mint pow(ll b) const {
        mint res(1);
        mint a(*this);
        while(b) {
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
    mint operator +(const mint& a) const { return mint(*this) += a;}
    mint operator -(const mint& a) const { return mint(*this) -= a;}
    mint operator *(const mint& a) const { return mint(*this) *= a;}
    mint operator /(const mint& a) const { return mint(*this) /= a;}
    bool operator <(const mint& a) const { return x < a.x;}
    bool operator <=(const mint& a) const { return x <= a.x;}
    bool operator >(const mint& a) const { return x > a.x;}
    bool operator >=(const mint& a) const { return x >= a.x;}
    bool operator ==(const mint& a) const { return x == a.x;}
    bool operator !=(const mint& a) const { return x != a.x;}
    
    friend istream& operator >>(istream& is, mint p) { return is >> p.x; }
    friend ostream& operator <<(ostream& os, mint p){ return os << p.x; }
};

//string stuff

vector<int> zfunc(const string& s) {
	int n=s.length();
	vector<int> z(n,0);
	for(int i=1,l=0,r=0;i<n;i++) {
		if(i<r) z[i] = min(z[i-l],r-i);
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]>r) {
			r = i+z[i];
			l = i;
		} 
	}
	return z;
}

vector<int> pfunc(const string& s) {
	int n=s.length();
	vector<int> pi(n);
	for(int i=1, j=0;i<n;i++) {
		while(j>0&&s[i]!=s[j]) j = pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i]=j;
	}
	return pi;
}

vector<int> suffix_arr(string s) {
	s+='$';
	int n=s.length();
	const int alphabet = 128;
	vector<int> p(n),c(n,0), cnt(max(alphabet,n),0), pn(n),cn(n,0); // p is starting index of suff that is i'th in sorted order
						   // c is equivalence class of suff starting at i
	for(int i=0;i<n;i++) {
		cnt[s[i]]++;
	}
	for(int i=1;i<alphabet;i++) {
		cnt[i]+=cnt[i-1];
	}
	for(int i=n-1;i>=0;i--) {
		p[--cnt[s[i]]]=i;
	}
	for(int i=1;i<n;i++) {
		c[p[i]] = c[p[i-1]];
		if(s[p[i]]!=s[p[i-1]]) c[p[i]]++;
	}
	for(int h=1;h<n;h<<=1) { //suffixes are sorted till length h
		fill(cnt.begin(),cnt.end(),0);
		for(int i=0;i<n;i++) {
			pn[i] = p[i]-h;
			if(pn[i]<0) pn[i]+=n;
			cnt[c[pn[i]]]++;
		}
		for(int i=1;i<n;i++) {
			cnt[i]+=cnt[i-1];
		}
		for(int i=n-1;i>=0;i--) {
			p[--cnt[c[pn[i]]]]=pn[i];
		}
		cn[p[0]]=0;
		for(int i=1;i<n;i++) {
			cn[p[i]]=cn[p[i-1]];
			if(make_pair(c[p[i]],c[(p[i]+h)%n])!=make_pair(c[p[i-1]],c[(p[i-1]+h)%n])) cn[p[i]]++;
		}
		c=cn;
	}
	p.erase(p.begin());
	return p;
}

vector<int> construct_lcp(const string& s, const vector<int>& p) {
	int n = p.size();
	vector<int> rank(n);
	for(int i=0;i<n;i++) {
		rank[p[i]]=i;
	}
	vector<int> lcp(n-1);
	int k=0;
	for(int i=0;i<n;i++) {
		if(rank[i]==n-1) {
			k=0;
			continue;
		}
		int j = p[rank[i]+1];
		while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
		lcp[rank[i]]=k;
		if(k) k--;
	}
	return lcp;
}


struct Matrix {
	vector<vector<int>> a = {{0,0},{0,0}};
	Matrix operator*(const Matrix& other) {
		Matrix product;
		ll temp;
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				temp=0;
				for(int k=0;k<2;k++) {
					temp = temp + (ll)a[i][k]*other.a[k][j]%mod; //take mod inside this loop if k>9
				}
				product.a[i][j] = (int)(temp%mod);
			}
		}
		return product;
	}
};

ll binpow(ll a, ll b, ll m) {
	return mint(a).pow(b).x;
}

vector<mint> fact,invfact;
void init_combo(ll n) {
	fact.resize(n+1,1);
	invfact.resize(n+1);
	for(ll i=1;i<=n;i++) {
		fact[i]=fact[i-1]*i;
	}
	invfact[n]=~fact[n];
	for(ll i=n;i>0;i--) {
		invfact[i-1]=invfact[i]*i;
	}
}

mint ncr(ll n, ll r) {
	if(n<0||r<0||n<r) return mint(0);
	return fact[n]*invfact[r]*invfact[n-r];
}


struct FlowEdge
{
	int u, v;
	long long capacity, flow;
	// int index;  //maybe?
	FlowEdge(int _u, int _v, long long _cap)
	{
		u = _u;
		v = _v;
		capacity = _cap;
		flow = 0;
	}
	bool can_use()
	{
		return (capacity-flow)>0;
	}
	long long residual()
	{
		return capacity-flow;
	}
};

struct Dinic
{
	int s, t;
	int n, m;
	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	vector<int> level, ptr;
	const long long flow_inf = 1e18;
	Dinic(int nx, int source, int sink)
	{
		n = nx;
		m = 0;
		adj.resize(nx);
		level.resize(nx);
		ptr.resize(nx);
		s = source;
		t = sink;
	}
	void add_edge(int from, int to, long long cap)
	{
		//Note that we are storing ids of edges in adjacency list instead of neighbour
		adj[from].push_back(m);
		edges.emplace_back(from, to, cap);
		adj[to].push_back(m+1);
		edges.emplace_back(to, from, 0ll);
		m += 2;
	}
	bool bfs()
	{
		fill(level.begin(), level.end(), -1);
		level[s] = 0;		//source has level 0
		queue<int> q;
		q.push(s);
		while(!q.empty())
		{
			int f = q.front();
			q.pop();
			for(auto &p: adj[f])
			{
				if(level[edges[p].v] != -1 || !edges[p].can_use())
				{
					continue;
				}
				level[edges[p].v] = level[f] + 1;
				q.push(edges[p].v);
			}
		}
		return (level[t] != -1); 			//return whether sink was reachable or not
	}

	long long dfs(int vx, long long pushed)
	{
		if(!pushed) return 0;				//no flow entering means nothing can be pushed ahead
		if(vx == t) return pushed;			//sink can absorb all flow

		//find the first neighbour to which you can push the flow and push as much flow as can be pushed
		for(int& i=ptr[vx]; i<(int)(adj[vx].size()); ++i)		//note that i is a reference so ptr[vx] changes with i
		{
			int edge_id = adj[vx][i];
			int tx = edges[edge_id].v;
			if(level[tx] != level[vx]+1 || !edges[edge_id].can_use()) 
				continue;
			
			long long what = dfs(tx, min(pushed, edges[edge_id].residual()));	//how much flow was used in further dfs

			if(what == 0) continue;

			edges[edge_id].flow += what;
			edges[edge_id^1].flow -= what;
			return what;
		}
		return 0;
	}

	long long flow()
	{
		long long cur_flow = 0;
		while(bfs())
		{
			long long add;
			fill(ptr.begin(), ptr.end(), 0);
			while((add = dfs(s, flow_inf)))
			{
				cur_flow += add;
			}
		}
		return cur_flow;
	}
};



void solve() {
    
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	// cin>>t;
    for(int i=1;i<=t;i++) {
        solve();
    }
	return 0;
}

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/ 
