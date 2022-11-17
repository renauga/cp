#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int t = inf.readInt(1,100000, "t");
    inf.readEoln();
    long long int a;
    for(int i=1;i<=t;i++) {
        a = inf.readLong(0,1000000000000000000, "a");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}