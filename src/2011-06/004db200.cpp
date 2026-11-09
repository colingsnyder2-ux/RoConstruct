// from server: 55% by atomic.potato
struct S_func_004db200 {
    char pad0[4];
    char field4[4];
    int f(int a1, int a2);
};

extern "C" void __stdcall sub_004c1670(void*, int);
extern "C" int __stdcall sub_004d9670(void*, int, int);

int S_func_004db200::f(int a1, int a2)
{
    int local = 0;
    sub_004c1670(field4, 1);
    sub_004d9670(this, a1, a2);
    return a1;
}
