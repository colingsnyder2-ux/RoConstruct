// from server: 44% by atomic.potato
struct S {
    void *field0;
    void *field4;
    void *field8;
    void *fieldC;
    void *field10;
    void *field14;
    void f(int a, unsigned char *b);
};

void S::f(int a, unsigned char *b)
{
    unsigned char v = *b;
    if (a != 0) {
        void (*fn)(void *, unsigned int) = (void (*)(void *, unsigned int))field10;
        fn((char *)field14 + (a - 0x1c), v);
    } else {
        void (*fn)(void *, unsigned int) = (void (*)(void *, unsigned int))field10;
        fn((char *)field14, v);
    }
}
