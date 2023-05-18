#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void print()
{
    printf("aaaa");
    printf("\n%d", sizeof(float));
}

void print2()
{
    char a;
    scanf_s("%c", &a);
    printf("%d",a);
}

void print3()
{
    int a = 12;
    printf("%d", a >> 2);
}

int calculator()
{
    double first; double second; char sign; double res;
    scanf("%lf %c %lf",&first, &sign, &second);
    switch (sign)
    {
    case '+':
        res = first + second;
        printf("%lf", res);
        break;
    default:
        break;
    }

    return 0;
}

void swap2(char** ppa, char** ppb)
{
    char* pt;
    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}
void swap1()
{
    char* pa = "success";
    char* pb = "failure";

    printf("pa -> %s, pb-> %s", pa, pb);
    swap2(&pa, &pb);
    printf("pa -> %s, pb-> %s", pa, pb);
}

int main()
{
    //print();
    //print2();
    //print3();
    //calculator();
    //swap1();
    double* p = (double*)calloc(sizeof(double),1);
}
