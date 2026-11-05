// from server: 60% by atomic.potato
struct Inner {
    int get();
};

struct Outer {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int f(int);
};

int Outer::f(int idx) {
    int v = begin[idx + 1].get();
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v].get();
}
