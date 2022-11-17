#include "testlib.h"

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);
    int t = inf.readInt(1,100000, "t");
    inf.readEoln();
    long long int a, jans, pans;
    for(int i=0;i<t;i++) {
        a = inf.readLong(0,1000000000000000000, "A");
        jans = ans.readLong(0,1000000000000000000, "correct answer");
        pans = ouf.readLong(0,1000000000000000000, "participant's answer");
        if(jans<pans) quitf(_wa, "wrong answer for test case %d", i+1);
        else if(jans>pans) quitf(_fail, "Partipant's answer is better for test case %d: A = %d, jans = %d, pans = %d", i+1, a, jans, pans);
    }
    quit(_ok, "NOICE");
}