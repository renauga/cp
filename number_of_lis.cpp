#include <bits/stdc++.h>
using namespace std;

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

using ll = long long int;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  //use rng() to get a random number

ll mod = 1e9+7;


/* tree stuff, required for binary lifting
call dfs_calc(1,1)


int LOGN = 18;
ll MAXN = 100000;
ll n;
vector<vector<int>> adjacents;
vector<ll> depth(MAXN+1,0);
vector<vector<int>> up(MAXN+1,vector<int>(LOGN,0));

void dfs_calc(int node, int parent) {
	if(node!=1) depth[node]=depth[parent]+1;
	up[node][0]=parent;
	for(int i=1;i<LOGN;i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(int child:adjacents[node]) {
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
    x = 1, y = 0;
    ll q, x1 = 0, y1 = 1;
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
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res; 
}

int myceil(vector<vector<pair<int,int>>>& lis, int key) { //returns index of greatest element less than key
    int l=0,r=lis.size()-1,mid,best=-1;
    while(l<=r) {
        mid = l + (r-l)/2;
        if(lis[mid].back().first<key) {
            l = mid+1;
            best = mid;
        } else {
            r = mid-1;
        }
    }
    return best;
}

int myceil2(vector<pair<int,int>>& row, int key) {
    int l=0,r=row.size()-1,mid,best=-1;
    while(l<=r) {
        mid = l + (r-l)/2;
        if(row[mid].first<key) {
            r = mid-1;
        } else {
            best = mid;
            l = mid+1;
        }
    }
    return best;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    vector<vector<pair<int,int>>> lis;
    lis.push_back({{1e9,0},{-1e9,1}}); //so that whenever a new minimum is found, it is initialised with count=1
    for(int i=0;i<n;i++) {
        int p = myceil(lis,nums[i]);
        int sum = lis[p].back().second-lis[p][myceil2(lis[p],nums[i])].second;
        if(p==lis.size()-1) { //increase length of lis with tail=nums[i]
            lis.push_back({{1e9,0},{nums[i],sum}});
        } else {
            p++;
            if(lis[p].back().first==nums[i]) {
                lis[p].back().second+=sum;
            } else {
                lis[p].push_back({nums[i], lis[p].back().second+sum});
            }
        }
    }
    cout<<lis.back().back().second;
	return 0;
}