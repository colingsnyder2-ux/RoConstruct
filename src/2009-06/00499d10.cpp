// from server: 49% by atomic.potato
struct S {
    void f();
};

void S::f() {
    int* p = (int*)((char*)this + 4);
    while (p) {
        int* q = (int*)((char*)p - 4);
        if (*p == (int)q) break;
        int* r = (int*)*p;
        *p = r[1];
        r[1] = (int)r;
        int* v = (int*)*r;
        void (*fn)(int) = (void (*)(int))v[0];
        fn(1);
    }
    if (this) {
        int* v = (int*)*(int*)this;
        void (*fn)(int) = (void (*)(int))v[0];
        fn(1);
    }
}
