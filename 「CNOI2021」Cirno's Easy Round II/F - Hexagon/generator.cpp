#include<bits/stdc++.h>
using namespace std;

// 3 3 5 10

const int N = 1000000;

int Rand() { return (rand() << 16) | rand(); }

int main(int argc, char *argv[]) {
    srand(time(NULL));
    for( int i = 12; i < 12 + 10; i ++ ) {
        string s = string(argv[1]) + "//" + to_string(i) + ".in";
        freopen( s.c_str(), "w", stdout );
        cout << Rand() % N << " " << Rand() % N << " " << Rand() % N << "\n";
        fclose(stdout);
    }
    return 0;
}