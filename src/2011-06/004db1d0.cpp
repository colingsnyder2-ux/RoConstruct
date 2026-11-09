// from server: 39% by atomic.potato
struct S_func_004db1d0 {
    char pad0[4];
    char field4;
    int f(int a1, int a2);
};

extern "C" void __stdcall sub_004c1670(char* p, int v);
extern "C" int __stdcall sub_004d95a0(int a1, int a2);

int S_func_004db1d0::f(int a1, int a2)
{
    sub_004c1670(&field4, 1);
    sub_004d95a0(a1, a2);
    return a1;
}
