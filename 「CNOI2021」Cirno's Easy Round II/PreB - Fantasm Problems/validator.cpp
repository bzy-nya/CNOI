#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(1, 100000, "n");
	inf.readSpace();
	int K = inf.readInt(2, 1000, "k");
	inf.readEof();
	return 0;
}
