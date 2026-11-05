// from server: 100% by colin
struct S {
    void f();
};

extern "C" void __cdecl sub_725520(const void*, const void*);
extern "C" void __cdecl sub_58d8a0();
extern "C" void __cdecl sub_58d9f0();
extern "C" void __cdecl sub_58da60();
extern "C" void __cdecl sub_58d910();
extern "C" void __cdecl sub_58d980();
extern "C" void __cdecl sub_58dad0();

void S::f() {
    sub_725520((const void*)0x8c37c8, (const void*)0x58dda0);
    sub_58d8a0();
    sub_725520((const void*)0x8c37d4, (const void*)0x58ddd0);
    sub_58d9f0();
    sub_725520((const void*)0x8c37d8, (const void*)0x58dde0);
    sub_58da60();
    sub_725520((const void*)0x8c37cc, (const void*)0x58ddb0);
    sub_58d910();
    sub_725520((const void*)0x8c37d0, (const void*)0x58ddc0);
    sub_58d980();
    sub_725520((const void*)0x8c37dc, (const void*)0x58ddf0);
    sub_58dad0();
}
