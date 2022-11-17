#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = 100;
    int m = (1<<13)+opt<int>(1);
    long long int k = (1LL<<29)+opt<int>(1);
    println(n,m,k);
    string s,t;
    s.resize(n,'a');
    t.resize(m,'a');
    s[(rnd.next(0,n))] = 'b';
    t[(rnd.next(0,m))] = 'b';
    t[(rnd.next(0,m))] = 'b';
    println(s);
    println(t);
}