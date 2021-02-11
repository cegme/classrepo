#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define PI 3.1415926
#define HALFOF(x) x/2


int main(int argc, char **argv, char **envp) {

    printf("Hello, World\n");

    printf("argc: %d\n", argc);

    int i;
    for (i = 0; i < argc; ++i) {
        printf("%d --> %s\n", i, argv[i]);
    }
    printf("\n");
    //for (i = 0; i < argc; ++i) {
    //    printf("%d --> %s\n", i, envp[i]);
    //}

    char character;
    //short myshort;
    long mylong;
    double mydouble;
    float myfloat;
    //bool mybool;
    //string mystring;

    unsigned short ushort = 5;
    short myshort = -1;

    printf("sizeof(char): %ld\n", sizeof(char));
    printf("sizeof(int): %ld\n", sizeof(int));
    printf("sizeof(float): %ld\n", sizeof(float));

    // 2**16 = 2^10 * 2^6 = 65536
    printf("sizeof(short): %ld\n", sizeof(short));

    printf("ushort=%d, myshort=%d\n", ushort, myshort);

    // ++i vs i++
    printf("i=%d\n", i); 
    printf("i++=%d\n", i++); 
    printf("++i=%d\n", ++i); 
   
    i = 1;
    //int newint = i++; newint->1, i = 2
    //int newint = ++i; newint->2, i = 2

    // Bit manipulations
    return 0;
}
