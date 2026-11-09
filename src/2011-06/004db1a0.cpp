// from server: 55% by atomic.potato
struct S_func_004db1a0 {
    char pad0[4];
    char field4[4];
    int f(int a1, int a2);
};

extern "C" void __stdcall sub_004c1670(void*, int);
extern "C" void __stdcall sub_004d94d0(void*, int, int);

int S_func_004db1a0::f(int a1, int a2)
{
    sub_004c1670(field4, 1);
    sub_004d94d0(this, a1, a2);
    return a1;
}
