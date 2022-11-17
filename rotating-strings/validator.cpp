#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100,"N");
    inf.readSpace();
    int m = inf.readInt(1,10000,"M");
    inf.readSpace();
    long long int k = inf.readLong(1,(long long int)(1e9),"K");
    inf.readEoln();
    string s = inf.readString();
    ensuref(s.length()==n, "length of s is not equal to n");
    for(int i=0;i<n;i++) {
        ensuref('a'<=s[i], "s consists of characters less than lowercase");
        ensuref(s[i]<='z', "s consists of characters more than lowercase");
    }
    string t = inf.readString();
    ensuref(t.length()==m, "length of t is not equal to m");
    for(int i=0;i<m;i++) {
        ensuref('a'<=t[i], "t consists of characters less than lowercase");
        ensuref(t[i]<='z', "t consists of characters more than lowercase");
    }
    inf.readEof();
    return 0;
}