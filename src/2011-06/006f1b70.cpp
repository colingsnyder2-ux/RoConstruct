// from server: 42% by atomic.potato
struct S {
    char pad0[0x28];
    int m28;
    int m2c;
    int m30;
    int m34;
    void f(int, int);
};

extern "C" int __stdcall sub_80b2ea(int, int, int, int, int);
extern "C" int __stdcall sub_80b0ac(int, int);
extern "C" void __stdcall sub_6f1ab0(int, int, int, int, int);
extern "C" void* __cdecl sub_a40a10(int);

void S::f(int a, int b)
{
    int v8;
    int vc;
    int v2c;

    v8 = m30;
    if (m34) {
        vc = (*(int (__thiscall **)(int))(*(int *)m34 + 8))(m34);
    } else {
        vc = 0;
    }

    int *p = (int *)b;
    (*(void (__thiscall **)(int, int, int *))(*(int *)b + 4))(b, 1, &v8);

    v2c = 0;
    int r = sub_80b2ea(vc, 0, 0xc073f8, 0xc765e0, 0);
    if (r == 0) {
        sub_a40a10(0xa5c10c);
        sub_80b0ac(0xb989fc, (int)&v8);
    }

    sub_6f1ab0(r, m28, m2c, (int)(p + 1), (int)&v8);

    if (vc) {
        (*(void (__thiscall **)(int, int))(*(int *)vc))(vc, 1);
    }
}
