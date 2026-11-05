// from server: 100% by atomic.potato
struct S {
    void f();
};

void S::f() {
    if (*(unsigned char*)((char*)this + 0x10) != 0) {
        int* p = *(int**)((char*)this + 0x14);
        typedef void (__thiscall *F)(int*, int);
        ((F)*p)((int*)((char*)this + 0x14), 0);
        *(unsigned char*)((char*)this + 0x10) = 0;
    }
}
