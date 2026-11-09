// from server: 28% by atomic.potato
extern "C" void __stdcall sub_401630(int, int);
extern "C" int __cdecl sub_6537e0();
extern "C" int __cdecl sub_64ed50();
extern "C" void __cdecl sub_662b90();
extern "C" void* __cdecl sub_7f3860(int);

struct S {
    void f(int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5)
{
    sub_401630(0xb8fd38, 0x653840);
    int edi = sub_6537e0();
    sub_64ed50();
    sub_662b90();
    *(int*)((char*)this + 0x1c) = edi;
    *(int*)this = 0x9dc33c;
    void* p = sub_7f3860(0xc);
    if (p) {
        *(int*)p = 0x9dbd34;
        *(int*)((char*)p + 4) = a4;
        *(int*)((char*)p + 8) = a5;
    } else {
        p = 0;
    }
    *(void**)((char*)this + 0x20) = p;
}
