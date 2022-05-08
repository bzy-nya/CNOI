#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(1, 100000, "n");
	inf.readEof();
	return 0;
}
