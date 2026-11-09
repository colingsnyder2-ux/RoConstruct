// from server: 100% by colin
struct S_func_0054db70 {
    char pad[92];
    unsigned int m_p;
    unsigned int f();
};

unsigned int S_func_0054db70::f() {
    unsigned int eax = *(unsigned int*)((char*)this + 0x5c);
    eax = eax >> 4;
    eax = eax & 1;
    return eax;
}
