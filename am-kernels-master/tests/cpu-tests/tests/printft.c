#include "trap.h"

int main() {
	printf("%s", "Hello world!\n");

	printf("%d + %d = %d\n", 1, 1, 2);

	printf("%d-%d-%d %d:%d:%d\n", 1900, 0, 0, 0, 0, 0);

	printf("%d-%d-%d %d:%d:%d%d%d\n", 222,222323,1901, 2, 0, 0, 0, 0);
	printf("%d-%d-%d %d:%d:%d%d%d\n", 199999222,2221123,1901, 2, 0, 0, 0, 0);
	printf("%d-%d-%d %d:%d:%d%d%d\n", 199999222,22232223,1901, 2, 03, 0, 0, 0);
	printf("%d-%d-%d %d:%d:%d%d%d\n", 199999222,22231123,1901, 2, 0, 1110, 0, 0);
  return 0;
}