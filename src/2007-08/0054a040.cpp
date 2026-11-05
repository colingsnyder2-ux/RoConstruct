// from server: 34% by colin
struct S {
    void f();
};

extern "C" {
    void __stdcall sub_549A10(void*);
    void* __stdcall sub_569800();
    void __stdcall sub_53E720(void*, void*);
    void __stdcall sub_567930(void*, void*);
    void __stdcall sub_566670(void*, void*);
    void __stdcall sub_410250(void*, void*, void*, void*, void*);
    void __stdcall sub_62FC62(void*);
    void __stdcall sub_40F800(void*);
    void __stdcall sub_77E6AC(void*);
    void __stdcall sub_77E624(void*, const char*, int, int, int);
    void __stdcall sub_77E628(void*);
}

void S::f()
{
    char buf[0x20];
    char buf2[0x40];
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;

    sub_549A10(buf);
    if (*(int*)(buf + 0x14) == 0) {
        sub_77E6AC(buf);
        return;
    }
    p = sub_569800();
    sub_53E720(this, p);
    if (*(int*)(buf + 0x1c) >= 0x10)
        q = *(void**)(buf + 8);
    else
        q = buf + 8;
    sub_77E624(buf2, (const char*)q, 0x22, 0x40, 1);
    sub_567930(&r, buf2);
    *(void**)&r = (void*)0x786dd4;
    sub_566670(&r, p);
    s = *(void**)((char*)&r + 4);
    t = *(void**)s;
    sub_410250(&r, &s, t, s, buf2);
    sub_62FC62(*(void**)((char*)&r + 4));
    *(void**)((char*)&r + 4) = 0;
    *(void**)((char*)&r + 8) = 0;
    sub_77E628(buf2);
    if (p) {
        sub_40F800(p);
        sub_62FC62(p);
    }
    sub_77E6AC(buf);
}
