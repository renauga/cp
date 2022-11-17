#include "testlib.h"

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);
    int jury_ans = ans.readInt(0,1000000006,"Correct answer");
    int contestant_output = ouf.readInt(0,1000000006, "Contestant's output");
    if (jury_ans != contestant_output)
        quitf(_wa, "expected %d, found %d", jury_ans, contestant_output);
    quitf(_ok, "answer is %d", jury_ans);
}