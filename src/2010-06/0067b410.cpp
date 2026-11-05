// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_7A79A0(unsigned int size);

struct S {
    void* f();
};

void* S::f() {
    char* p = (char*)sub_7A79A0(0x78);
    if (p) {
        *(int*)(p + 0) = 0;
    }
    if (p + 4) {
        *(int*)(p + 4) = 0;
    }
    if (p + 8) {
        *(int*)(p + 8) = 0;
    }
    p[0x70] = 1;
    p[0x71] = 0;
    return p;
}
