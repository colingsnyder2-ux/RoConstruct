// from server: 18% by atomic.potato
struct S {
    int f(int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_98B6F0(void*, void*);
extern "C" void __stdcall sub_98B6E4(void*);
extern "C" char __fastcall sub_6C0450(void*, void*);

struct Str {
    char pad[0x1c];
    void* p;
};

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    char buf[0x30];
    int* p = (int*)buf;
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    sub_98B6F0(buf + 0xc, &a4);
    *(int*)(buf + 0x28) = a11;
    *(int*)(buf + 0x2c) = a12;
    char r = sub_6C0450((void*)0xb3c374, buf + 0xc);
    int v = r ? 0xb3c374 : 0;
    *(int*)this = v;
    sub_98B6E4(buf + 0xc);
    return 0;
}
