#include<bits/stdc++.h>
using namespace std;

// 1 3

const int N = 8;
const int M = 10000;

void gen_vector() {
    vector<int>V;
    for( int i = 1; i <= N; i ++ )
      { V.push_back( rand() % M + 1 ); }
    sort( V.begin(), V.end() );
    for( auto c : V ) cout << c << " "; 
    cout << "\n";
}

int main( int argc, char **argv ) {
    string s = string(argv[1]); s += "\\0.in";
    cerr << s << "\n";
	srand( time(NULL) ); 
    freopen( s.c_str(), "w", stdout );
    cout << N << "\n";
    
    gen_vector();
    gen_vector();
}

//cmd /k g++ -W -Wall -O2 -std=c++17 "$(FULL_CURRENT_PATH)" -o "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" && (echo --------------------------------编译成功------------------------------- & "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" "$(CURRENT_DIRECTORY)" ) & PAUSE & EXIT