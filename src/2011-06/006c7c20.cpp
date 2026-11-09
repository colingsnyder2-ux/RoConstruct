// from server: 45% by atomic.potato
struct S {
    char pad[8];
    void *field8;
    char *fieldC;
    void method(void *arg1, void *arg2);
};

void S::method(void *arg1, void *arg2)
{
    void *p = arg1;
    if (p) {
        void *v = *(void **)arg2;
        void (*fn)(void *) = (void (*)(void *))field8;
        char *base = fieldC;
        base = (char *)p + ((int)base - 0x1c);
        fn(base);
    } else {
        void *v = *(void **)arg2;
        void (*fn)(void *) = (void (*)(void *))field8;
        char *base = fieldC;
        base = (char *)base + 0;
        fn(base);
    }
}
