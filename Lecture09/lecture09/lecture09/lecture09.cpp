#include <stdlib.h>

void* malloc(int size);
struct Character
{
    int hp;
    int mp;
    void *attack;
};


void* malloc(int size)
{
    static char mem[4096];

    void* ret;
    ret = mem;
    unsigned int e = 8303;
    //ret[0] = e % 256;

    e = e >> 8;

    return ret;
}

int attack()
{
    return 50;
}

/*
int main()
{
    //int* a = malloc(4);

    Character A;
    Character B;

    int (*func_p)();
    func_p = attack;
    A.hp = 100; B.hp = 200;
    A.mp = 10; B.mp = 20;
    A.attack = func_p;
    int (*func_p2)();
    func_p2 = (int(*)())A.attack;
    func_p2();

    return 0;
}
*/