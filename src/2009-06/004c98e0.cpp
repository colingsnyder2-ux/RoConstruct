// from server: 5% by atomic.potato
struct Inner {
    char pad[0x4c];
    void ctor();
    void dtor();
};

struct S {
    Inner* p;
    void f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p_, int q, int r, int s);
};

void Inner::ctor() {}
void Inner::dtor() {}

void S::f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p_, int q, int r, int s) {
    Inner tmp;
    if (p) {
        tmp.ctor();
        p->dtor();
    }
    tmp.dtor();
}
