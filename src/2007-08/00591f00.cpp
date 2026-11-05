// from server: 24% by colin
struct S {
    char pad[0xE8];
    void f(int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_77E690(void*);
extern "C" void __stdcall sub_77E6AC(void*);
extern "C" void __cdecl sub_5402B0();

void S::f(int, int, int, int, int, int, int) {
    void* p = (char*)this + 0xE8;
    sub_77E690(&p);
    sub_77E6AC(&p);
}
