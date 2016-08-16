#include <stdio.h>
#include <stdlib.h>

#define INT 10
/*
int testIO();
int testIONew();
int testIO2();
int testIOcountChar();
int testCombineBlock();
int countString();
int showWordsByLine();
*/

void testArrayCopy();
void testArrayChange();
void testOutter();

void change1(int a){
    a = 11;
}

void change2(int a){
    a = 12;
}

int main()
{
    testOutter();
    return 0;
}

