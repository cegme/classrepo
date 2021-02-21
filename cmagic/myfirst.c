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

// Return integer
// > 0 if left > right
// < 0 if left < right
// == 0 if left == right
int rostercmp(const void *left, const void *right) {

    const roster *a = (const roster*) left;
    const roster *b = (const roster*) right;

    //printroster(*a);
    //printroster(*b);
    //printf("\t%d - %d = %d\n", (*a).number, (*b).number, (*a).number - (*b).number);
    

    return - (*a).number + (*b).number;
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

    org[3].number = 9;
    strncpy(org[3].team, "Sooners", MAX_ROSTER);

    org[4].number = 44;
    strncpy(org[4].team, "Thunder", MAX_ROSTER);


    printf("-------------------\n");
    // Print all Org
    for (i = 0; i < 5; ++i) {
        printroster(org[i]);
    }
    
    printf("-------------------\n");
    // Sort all org
    qsort(org, 5, sizeof(roster), rostercmp);
    
    // Print all org
    for (i = 0; i < 5; ++i) {
        printroster(org[i]);
    }
    printf("-------------------\n");



    // Pointer Arithematic
    //printf("Pointer math ---\n");
    //printf("sizeof(roster) ---%ld\n", sizeof(roster));
    //roster *o = org;
    //for (int i = 0; i < 3; ++i,++o) {
    //    printroster(*o);
	//printf("\to: %ld\n", o);
    //} 

    free(org);


    // Bit manipulations
    // Traffic Bits
    // [0 0 0 0 0 0 0 0] -- ERROR
    // [0 0 0 0 0 0 0 1] -- Go
    // [0 0 0 0 0 0 1 0] -- Slow Down
    // [0 0 0 0 0 1 0 0] -- Stop
    // [0 0 0 0 1 0 0 0] -- Turn left Go
    // [0 0 0 1 0 0 0 0] -- Turn left Slow
    
    u_int8_t trafficsignal;

    // Set to go
    //trafficsignal = 1;
    trafficsignal = 0b00000001; // Go
    trafficsignal = 0b00000010; // Slow Down
    
    const unsigned char T_ERROR = 0b00000000; // -- ERROR
    const unsigned char T_GO = 0b00000001 ;// -- Go
    const unsigned char T_SLOW = (1 << 1);// -- Slow Down
    const unsigned char T_STOP = (1 << 2) ;// -- Stop
    const unsigned char T_LGO = 0b00001000 ;// -- Turn left Go
    const unsigned char T_LS = 0b00010000 ;// -- Turn left Slow

    // IS this go? (BAD)
    if (trafficsignal == T_GO) {
        printf("Greenlight\n");
    }
    else if (trafficsignal == T_LGO) {
        printf("Left Greenlight\n");
    }

    // Is this Go? Good
    trafficsignal = 0b00001001; // Slow Down
    unsigned char is_go = T_GO | T_LGO;
    if (trafficsignal == is_go) {
        printf("Greenlight AND Left Greenlight: %x\n", trafficsignal);
    }

    // Set a new value?
    // Make left turn slow down (turn off left turn go, turn on left turn slow down)
    // Keep go
    trafficsignal &= (~T_LGO);
    trafficsignal |= T_LS;
    printf("Traffic signal %x\n", trafficsignal);
    printf("T_GO | T_LS  %x\n", T_GO | T_LS);
    printf("T_GO %x | T_LS %x =   %x\n", T_GO, T_LS, T_GO | T_LS);

    return 0;
}
