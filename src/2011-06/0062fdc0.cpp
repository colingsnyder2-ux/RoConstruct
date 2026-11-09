// from server: 56% by atomic.potato
struct S_func_0062fdc0 {
    char pad0[4];
    char field1[1];
    int f(int, int);
};

struct T_004c1670 {
    void g(int);
};

extern "C" void __stdcall sub_0062f770(void*, int, int);

int S_func_0062fdc0::f(int a, int b)
{
    ((T_004c1670*)&field1)->g(1);
    sub_0062f770(this, a, b);
    return a;
}
