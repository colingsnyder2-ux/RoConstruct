// from server: 39% by atomic.potato
struct S_func_004db170 {
    char pad0[4];
    int field4;
    int f(int a2, int a3);
};

extern "C" int __stdcall sub_4c1670(int, int);
extern "C" int __stdcall sub_4d9400(int, int);

int S_func_004db170::f(int a2, int a3)
{
    int local = 0;
    sub_4c1670(1, (int)&field4);
    sub_4d9400(a2, a3);
    return a2;
}
