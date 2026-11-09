// from server: 92% by atomic.potato
struct S {
    char pad0[0x14];
    unsigned int count;
    unsigned int cap;
    char buf[1];
    void f(unsigned int* p);
};

void S::f(unsigned int* p) {
    unsigned int i = 0;
    if (p[5] > i) {
        char* base = (char*)p + 4;
        do {
            char* src;
            if (p[6] >= 0x10)
                src = *(char**)base;
            else
                src = base;
            char* dst;
            if (p[6] >= 0x10)
                dst = *(char**)base;
            else
                dst = base;
            dst[i] = src[i] ^ 0x55;
            i++;
        } while (i < p[5]);
    }
}
