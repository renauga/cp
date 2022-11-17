#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int a, c=0;
    cin>>a;
    for(int i=0;i<61;i++) {
        if(((a>>i)&(1LL))&&((a>>(i+1))&(1LL))) {
            a+=(1LL<<i);
            c++;
        }
    }
    cout<<__builtin_popcountll(a)+c<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
    for(int i=1;i<=t;i++) {
        solve();
    }
	return 0;
}
