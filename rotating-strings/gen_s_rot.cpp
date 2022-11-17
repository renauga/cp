#include "testlib.h"

using namespace std;

string gen_rot(string s, int r) {
    return s.substr(r+1)+s.substr(0,r);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = 100;
    int m = 10000;
    long long int k = 1e9;
    println(n,m,k);
    string s,t;
    auto pos = rnd.perm(26);
    string block;
    block.resize(26);
    for(int i=0;i<26;i++) {
        block[i] = 'a'+pos[i];
    }
    while((s.size()+26)<=n) s+=gen_rot(block,rnd.next(26));
    s+=(block.substr(0,n-s.size()));
    while((t.size()+n-1)<=m) t+=gen_rot(s,rnd.next(n));
    t+=(s.substr(0,m-t.size()));

    println(s);
    println(t);
    println(s.size());
    println(t.size());
}