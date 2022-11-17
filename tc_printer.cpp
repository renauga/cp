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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long int m = 1e9+7;
long long int calc(int parent, int node, vector<vector<int>> &adjacents) {
    vector<long long int> valueOfChild;
    for(int i=0;i<adjacents[node].size();i++) {
        if(adjacents[node][i]!=parent) {
            valueOfChild.push_back(calc(node, adjacents[node][i],adjacents));
        }
    }
    sort(valueOfChild.begin(), valueOfChild.end());
    long long int sum=1;
    long long int size = valueOfChild.size();
	long long int temp;
    for(long long int i=0;i<size;i++) {
		temp = valueOfChild[i]*(size-i);
		if(temp<valueOfChild[i]) trace(temp,valueOfChild);
		temp%=m;
		temp+=sum;
		if(temp<sum) trace(temp,valueOfChild);
		sum = temp%m;
    }
    return sum;
}

vector<vector<int>> random_tree(long long int n) {
	int p=1;
	vector<vector<int>> adjacents(n+1);
	vector<long long int> prufer(n-1);
	for(int i=1;i<n-1;i++) {
		prufer[i] = 1 + rng()%n;
	}
	vector<int> degree(n+1,1);
	for(int i=1;i<n-1;i++) {
		degree[prufer[i]]++; 
	}
	for(int i=1;i<n-1;i++) {
		for(int j=1;j<=n;j++) {
			if(degree[j]==1) {
				adjacents[prufer[i]].push_back(j);
				adjacents[j].push_back(prufer[i]);
				degree[prufer[i]]--;
				degree[j]--;
				break;
			}
		}
	}
	long long int v,u=0;
	for(int i=1;i<=n;i++) {
		if(degree[i]==1) {
			if(u==0) u=i;
			else {v=i;break;}
		}
	}
	adjacents[u].push_back(v);
	adjacents[v].push_back(u);
	return adjacents;
}

void dfs(int node, int parent, vector<vector<int>>& adjacents, vector<int>& parents) {
	for(int child:adjacents[node]) {
		if(child!=parent) {
			parents[child]=node;
			dfs(child,node,adjacents,parents);
		}
	}
}

void gen_size() {
	int n = 100, m = 79, k = 100000000;

}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	/*  */int g=5;
	long long sum=0;
	long long inc=1e5;
	for(int i=0;;i++) {
		cout<<"gen "<<sum<<" "<<i<<" > $\n";
		if(sum>1000000000000000000-inc) break;
		sum+=inc;
		inc*=2;
	}
	cout<< ((1LL)<<59) + ((1LL)<<58);
	return 0;
}

/*
TEST CASES

1. to catch mistakes in powers. m and/or k ko power of 2 rakhke dekho
2. to cover a lot of pairs of i,j where i and j are starting and ending pfunctions
3. some more edge cases maybe?
4. n>m
5. t is concatenation of blocks of s
6. t is concatenation of blocks of s-1
7. t is concatenation of rotated copies of s
8. cover more letters


*/