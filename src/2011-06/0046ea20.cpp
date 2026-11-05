// from server: 65% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

struct T {
    int* g(int*);
};

int S::f(int a) {
    T* t = (T*)this;
    int* p = t->g(&a + 1);
    int idx = *p;
    if (idx < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)idx >= (unsigned)n) return 0;
    return begin[idx];
}
