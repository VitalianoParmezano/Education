1#include <stdio.h>
2#include <stdlib.h>
3#include "example.h"
4
5int main(int argc, char *argv[]) {
6    CLIENT *clnt;
7    int *result;
8    int a = 5, b = 10;
9    
10    clnt = clnt_create(argv[1], EXAMPLE_PROG, EXAMPLE_VERS, "udp");
11    
12    if (clnt == NULL) {
13        clnt_pcreateerror(argv[1]);
14        exit(1);
15    }
16
17    result = add_1(&a, &b, clnt);
18    if (result == NULL) {
19        clnt_perror(clnt, "call failed");
20    } else {
21        printf("Result: %%d\n", *result);
22    }
23
24    clnt_destroy(clnt);
25    return 0;
26}
