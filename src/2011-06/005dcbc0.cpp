// from server: 47% by atomic.potato
struct Inner {
    int get();
};

struct S {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int f(int* p);
};

int S::f(int* p) {
    int idx = p[1];
    if (idx < 0) return 0;
    int count = (int)(end - begin);
    if ((unsigned)idx >= (unsigned)count) return 0;
    return begin[idx].get();
}
