// from server: 75% by colin
struct S
{
    char pad0[0x14];
    int* p14;
    char pad18[0x0c];
    int* p24;
    char pad28[0x0c];
    int* p34;
    char pad38[0x18];
    int v50;
    int v54;
    int v5c;
    void f();
};

void S::f()
{
    if ((v5c >> 3) & 1)
    {
        int a = v50;
        int b = v54;
        *p14 = a;
        *p24 = a;
        *p34 = b + a - a;
    }
    else
    {
        *p14 = 0;
        *p24 = 0;
        *p34 = 0;
    }
}
