// from server: 56% by colin
struct S {
    void f();
};

extern "C" {
    void __stdcall sub_77E698(void*);
    void __stdcall sub_77E644(void*, const char*, void*);
    void __stdcall sub_77E6AC(void*);
    void* __cdecl sub_408740(void*);
    void __cdecl sub_544F80(void*);
    void __cdecl sub_735110(void*, void*, void*, void*, int, int, double, int);
}

void S::f() {
    char buf1[0x1c];
    char buf2[0x1c];
    char buf3[0x1c];
    void* p;

    sub_77E698(buf3);
    p = sub_408740(buf1);
    sub_544F80(p);
    sub_77E644(buf2, "Sky\\", p);
    sub_735110(*(void**)((char*)this + 0x78), 0, p, buf3, 1, 1, 1.0, 1);
    *(int*)((char*)this + 0x60) |= 1;
    sub_77E6AC(buf2);
    sub_77E6AC(buf1);
    sub_77E6AC(buf3);
}
