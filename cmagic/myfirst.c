#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define PI 3.1415926
#define HALFOF(x) x/2
#define MAX_ROSTER 60

struct roster {
    short number;
    char team[MAX_ROSTER];
    //char *name;
};
typedef struct roster roster;
//struct roster sooners;
//roster sooners;


int printroster(roster r) {
    printf("<%d: %s>\n", r.number, r.team);
    return 0;
}


int main(int argc, char **argv, char **envp) {

    printf("Hello, World\n");

    printf("argc: %d\n", argc);

    int i;
    for (i = 0; i < argc; i+=1) {
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
    i = 0;
    printf("i=%d\n", i);  // 0
    i = 0;
    printf("i++=%d\n", i++); // 0 -- post-increment 
    i = 0;
    printf("++i=%d\n", ++i); // 1
   
    i = 1;
    //int newint = i++; newint->1, i = 2
    //int newint = ++i; newint->2, i = 2

    // pointer
    printf("Pointer---------------------\n");
    int box;
    box = 0xA;
    printf("box value = %d\n", box);
    printf("box sizeof(int) = %ld\n", sizeof(box));
    printf("box address-of = %p\n", &box);

    int *label = &box;
    printf("label value = %p\n", label);
    printf("label sizeof(int) = %ld, %ld\n", sizeof(label), sizeof(int*));
    printf("label address-of = %p\n", &label);
    printf("label *value = %d\n", *label);

    int **qrcode = &label;
    printf("qrcode value = %p\n", qrcode);
    printf("qrcode sizeof(int) = %ld, %ld\n", sizeof(qrcode), sizeof(int**));
    printf("qrcode address-of = %p\n", &qrcode);
    printf("qrcode *value = %p\n", *qrcode);
    printf("qrcode **value = %d\n", **qrcode);

    //int years[4];
    char grades[] = {'a', 'b', 'c', 'd'};
    //char grades[4];
    grades[0] = 'a';
    grades[1] = 'b';
    grades[2] = 'c';
    grades[3] = 'd';

    printf("grades[0] = %c\n", grades[0]);
    printf("sizeof(grades[0]) = %ld\n", sizeof(grades[0]));
    printf("sizeof(grades) = %ld\n", sizeof(grades));
    printf("grades value = %p\n", grades);
    printf("grades *value = %c\n", *grades);


    //int a, *b; // a is an int. b is a pointer to an int [BAD]
    //int* a, b; // a is a pointer to an in. b is an int [BAD]
    //int *a, b; // [GOOD]
    
    // Right to left rule

    // Structs
    roster r;
    r.number = 24;
    //r.team = "Sooners";
    strncpy(r.team, "Sooners", 8);
    printroster(r);

    roster *org;  // roster org[32];
    //*org = r; cannot point value to another value
    //org = r; r not a pointer 
    org = &r;
    printroster(*org);

    // !!Dynamically!! Allocate malloc/calloc on the Heap
    //org = malloc(sizeof(roster)*32);
    org = calloc(32, sizeof(roster));

    org[0].number = 13;
    strncpy(org[0].team, "Dolphins", MAX_ROSTER);

    org[1].number = 3;
    strncpy(org[1].team, "Heat", MAX_ROSTER);

    org[2].number = 0;
    strncpy(org[2].team, "Marlins", MAX_ROSTER);

    //printroster(org[2]);



    // Pointer Arithematic
    printf("Pointer math ---\n");
    printf("sizeof(roster) ---%ld\n", sizeof(roster));
    roster *o = org;
    for (int i = 0; i < 3; ++i,++o) {
        printroster(*o);
	printf("\to: %ld\n", o);
    } 

    free(org);
    // Bit manipulations
    return 0;
}
