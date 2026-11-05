// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_7f3860(unsigned int size);

struct S {
    int f();
};

int S::f() {
    char* p = (char*)sub_7f3860(0x58);
    if (p) {
        *(int*)p = 0;
    }
    char* q = p + 4;
    if (q) {
        *(int*)q = 0;
    }
    char* r = p + 8;
    if (r) {
        *(int*)r = 0;
    }
    p[0x50] = 1;
    p[0x51] = 0;
    return (int)p;
}
