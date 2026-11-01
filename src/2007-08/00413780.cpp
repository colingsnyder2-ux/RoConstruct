// from server: 100% by colin
struct S {
    void f();
};

void S::f() {
    int* p = *(int**)((char*)this + 4);
    if (p) {
        void** vt = (void**)*p;
        ((void (__thiscall*)(void*, int))vt[0])(p, 1);
    }
}
