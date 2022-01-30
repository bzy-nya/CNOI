#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(1, 100000, "n");
	inf.readEoln();
	
	int pre = -1;
	
	for( int i = 0; i < N; i ++ ) {
		int a = inf.readInt(1, 10000, "a_i");
		ensuref( a >= pre, "Monotonicity Broken" );
		pre = a;
		inf.readSpace();
	} inf.readEoln();
	
	pre = -1;
	
	for( int i = 0; i < N; i ++ ) {
		int b = inf.readInt(1, 10000, "b_i");
		ensuref( b >= pre, "Monotonicity Broken" );
		pre = b;
		inf.readSpace();
	} inf.readEoln();
	
	inf.readEof();
	return 0;
}
