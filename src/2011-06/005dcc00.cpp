// from server: 57% by atomic.potato
struct Inner {
    int get(int* p);
};

struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int* p);
};

int S::f(int* p) {
    int idx = Inner().get(p + 1);
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
