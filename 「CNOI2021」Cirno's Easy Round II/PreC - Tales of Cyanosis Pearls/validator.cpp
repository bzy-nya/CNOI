#include "testlib.h"

int bin[1005];

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(1, 1000, "n"); 
	inf.readEoln();
	
	for( int i = 0; i < N; i ++ ) {
		for( int j = 0; j < N; j ++ ) {
			int c = inf.readInt(1, N, "c");
			bin[c] ++;
			ensuref( bin[c] <= N, "number of a color exceed" );
			inf.readSpace();
		}
		inf.readEoln();
	} 
	
	inf.readEof();
	return 0;
}
