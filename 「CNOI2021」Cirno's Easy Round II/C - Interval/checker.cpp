#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);
    int T = inf.readInt(); 
    cout << T << endl;
    while( T -- ) {
        int a = inf.readInt();
        int b = inf.readInt();
        int c = inf.readInt();
        int d = inf.readInt();
        cout << a << " " << b << " " << c << " " << d << endl;

        int F = ouf.readInt();

        if( F == 1 ) quitf(_wa, "Wrong Answer");
        if( F == 2 ) quitf(_wa, "Too much queries");
        if( F == 3 ) quitf(_wa, "You are tring to hack interactive library" );
    }
    quitf(_ok, "QwQ!");
}