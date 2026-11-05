// from server: 100% by colin
struct S {
    S* f(unsigned int);
};

extern "C" void __cdecl sub_54D4C0();
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void (__cdecl *sub_77E4E4)(void*);

extern int dword_77E4DC;
extern int dword_77E4E0;

S* S::f(unsigned int flags) {
    sub_54D4C0();
    int* p = (int*)((char*)this + 0x18);
    *p = dword_77E4DC;
    *p = dword_77E4E0;
    sub_77E4E4(p);
    if (flags & 1) {
        sub_62FC62(this);
    }
    return this;
}
