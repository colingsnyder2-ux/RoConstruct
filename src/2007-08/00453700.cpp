// from server: 57% by colin
struct S {
    void* f(int);
};

extern "C" int __cdecl sub_652220(int);
extern "C" void __cdecl sub_657E40();
extern "C" void __cdecl sub_6607C0(void*, int);
extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void* __cdecl sub_65E750(void*, int, int, int, int, int, int, int);
extern "C" void* __cdecl sub_655F00(void*, void*);
extern "C" void __cdecl sub_65E930(void*, int);

void* S::f(int a) {
    if (sub_652220(a) == -1)
        return 0;
    void* p = (*(void* (__thiscall**)(void*))(*(int*)this + 0x18c))(this);
    *(int*)((char*)p + 0x160) = 0;
    sub_657E40();
    (*(void (__thiscall**)(void*))(*(int*)p + 0x154))(p);
    *(int*)(*(int*)((char*)p + 0x200) + 0x88) = 0;
    *(int*)(*(int*)((char*)p + 0x200) + 0x7c) = 0;
    sub_6607C0(*(void**)((char*)p + 0x200), 1);
    void* q = sub_62FEF6(0xb4);
    if (q != 0)
        q = sub_65E750(q, 0, 0x787ed4, 0xc8, 1, -1, 1, 1);
    else
        q = 0;
    void* r = sub_655F00(p, q);
    sub_65E930(r, 1);
    *(int*)((char*)r + 0xac) = 0;
    void* s = sub_62FEF6(0xb4);
    if (s != 0)
        s = sub_65E750(s, 1, 0x791ec4, 0xc8, 1, -1, 1, 1);
    else
        s = 0;
    void* t = sub_655F00(p, s);
    *(int*)((char*)t + 0xac) = 0;
    return 0;
}
