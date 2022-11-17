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


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  //use rng() to get a random number

long long int mod = 1e9+7;

struct Matrix {
	vector<vector<int>> a = {{0,0},{0,0}};
	Matrix operator*(const Matrix& other) {
		Matrix product;
		long long temp;
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				temp=0;
				for(int k=0;k<2;k++) {
					temp = temp + (long long)a[i][k]*other.a[k][j]%mod; //take mod inside this loop if k>9
				}
				product.a[i][j] = (int)(temp%mod);
			}
		}
		return product;
	}
};

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res; 
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    int max=0;
    int previous;
	string temp="";
	string lcs="";
    for(int i=1;i<=n;i++) {
        previous=0;
		temp="";
        for(int j=1;(j<=m) && (i+j-1<=n);j++) {
            if(a[i+j-2]==b[j-1]) {
                previous++;
				temp+=b[j-1];
            } else {
                previous=0;
				temp="";
            }
            if(previous>max) {
                max = previous;
				lcs=temp;
            }
        }
    }
    for(int i=2;i<=m;i++) {
        previous=0;
		temp="";
        for(int j=1;(j<=n) && (i+j-1<=m);j++) {
            if(a[j-1]==b[i+j-2]) {
                previous++;
				temp+=a[j-1];
            } else {
                previous=0;
				temp="";
            }
            if(previous>max) {
                max = previous;
				lcs=temp;
            }
        }
    }
	lcs+="\0";
    cout<<max<<"\n";
	cout<<lcs;
	return 0;
}