// from server: 38% by atomic.potato
struct Inner {
    void f(int, int, int, int);
};

struct Outer {
    char pad0[0x70];
    Inner inner;
    char pad1[0x0c];
    int mode;
    virtual int g(int);
    void h(int, int, int, int);
};

void Outer::h(int a, int b, int c, int d)
{
    if (mode == 4) {
        int v1 = g(a);
        int v2 = g(b);
        int v3 = g(c);
        int v4 = g(d);
        inner.f(v1, v2, v3, v4);
        int w1 = g(a);
        int w2 = g(d);
        int w3 = g(b);
        inner.f(w1, w2, w3, w1);
    } else if (mode == 7) {
        int v1 = g(d);
        int v2 = g(c);
        int v3 = g(b);
        int v4 = g(a);
        inner.f(v1, v2, v3, v4);
    }
}
