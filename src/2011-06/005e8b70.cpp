// from server: 42% by atomic.potato
extern "C" int __cdecl func_005ba5e0();
extern "C" int __cdecl func_005ba420();
extern "C" int __cdecl func_00592b40(int*, int, int*);
extern "C" int __cdecl func_0062d1d0(int*, int*);

struct S {
    char pad0[0x14];
    int field14;
    char pad18[0x18];
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    int* p = &field14;
    *p = func_005ba5e0();
    int v1 = func_005ba5e0();
    int tmp1;
    func_00592b40(&tmp1, v1, &field30);
    func_0062d1d0(p, &tmp1);
    int v2 = func_005ba5e0();
    int tmp2;
    func_00592b40(&tmp2, v2, &field38);
    func_0062d1d0(p, &tmp2);
    int v3 = func_005ba420();
    int tmp3;
    func_00592b40(&tmp3, v3, &field40);
    func_0062d1d0(p, &tmp3);
    return 0;
}
