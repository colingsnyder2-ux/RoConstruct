// from server: 100% by why2
struct S {
    void f();
};

void S::f() {
    int* p = *(int**)((char*)this + 4);
    if (p) {
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vt[0];
        fn(p, 1);
    }
}
