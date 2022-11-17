#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t=100000;
    cout<<t<<'\n';
    long long int x = opt<long long int>(1);
    if(x<0) {
        for(int i=0;i<t;i++) {
            cout<<rnd.next(0LL,1000000000000000000LL)<<'\n';
        }
    } else {
        long long int y = opt<long long int>(2);
        for(int i=0;i<t;i++) {
            cout<<min(x+y*i,1000000000000000000)<<'\n';
        }
    }
}