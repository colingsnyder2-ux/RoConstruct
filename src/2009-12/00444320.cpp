// from server: 48% by atomic.potato
struct S {
    char pad[8];
    int field8;
    int fieldC;
    void f(int a, unsigned char* b);
};

void S::f(int a, unsigned char* b) {
    if (a != 0) {
        unsigned char v = *b;
        int (*fn)(void*, int) = (int (*)(void*, int))field8;
        void* p = (char*)fieldC + (a - 0x1c);
        fn(p, v);
    } else {
        unsigned char v = *b;
        int (*fn)(void*, int) = (int (*)(void*, int))field8;
        void* p = (char*)fieldC + 0;
        fn(p, v);
    }
}
