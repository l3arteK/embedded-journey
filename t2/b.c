#include <stdio.h>
extern int shared;
extern int hidden;
int main(void) { printf("%d %d\n", shared, hidden); return 0; }