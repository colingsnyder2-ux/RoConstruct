// from server: 43% by atomic.potato
extern "C" int __stdcall sub_80B2EA(int, int, int, int, int);
extern "C" void __stdcall sub_80B0AC(int, int);
extern "C" void __stdcall sub_4E32B0(int, int);
extern "C" int __stdcall sub_592B40(int);

struct S {
    char pad[0x28];
    int (__stdcall *fn)(int);
    int ctx;
    void __cdecl method(int a, int b);
};

void S::method(int a, int b)
{
    int r = sub_80B2EA(a, 0, 0xc073f8, 0xc12ef0, 0);
    if (r == 0) {
        char buf[16];
        sub_80B0AC(0xa5c10c, (int)buf);
        sub_80B0AC(0xb989fc, (int)buf);
    }
    int off = fn(ctx + r);
    double d = *(double*)&off;
    sub_4E32B0(b + 4, (int)&d);
}
