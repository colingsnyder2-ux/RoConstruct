// from server: 100% by tester
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" void __cdecl sub_7713F0();
extern "C" void __cdecl sub_9831F5(void*);

struct S {
    void f();
};

void S::f() {
    sub_4015A0((void*)0x771450, (void*)0xe4862c);
    sub_7713F0();
    sub_9831F5((void*)0xb1a640);
}
