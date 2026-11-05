// from server: 100% by Intel
struct S {
    int f();
};

int S::f() {
    unsigned int eax = *(unsigned int*)((char*)this + 0xb0);
    eax >>= 2;
    eax &= 1;
    return eax;
}
