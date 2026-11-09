// from server: 100% by colin
struct S {
};

void __cdecl f(void* p) {
    void (*fn)() = *(void (**)())p;
    fn();
}
