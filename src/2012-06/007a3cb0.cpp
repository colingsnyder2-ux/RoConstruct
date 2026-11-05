// from server: 60% by atomic.potato
struct S
{
    int a;
    int b;
    int c[4];
    int d;
    int e[24];
    int f();

    S();
};

S::S()
{
    a = 0x00bb5344;
    b = 0x00bb5338;
    c[2] = 0x00bb532c;
    d = 0x00bb5320;
    e[8] = 0x00bb5314;
}

int S::f()
{
    return 0;
}
