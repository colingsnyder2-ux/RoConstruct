// from server: 86% by atomic.potato
struct Inner {
    virtual int f();
    char pad[4];
    Inner* next;
    void g(int);
};

struct Outer {
    char pad[0xd8];
    Inner* p;
    void g(int);
};

void Outer::g(int x) {
    Inner* s = p;
    while (s->f() != 9) {
        s = s->next;
    }
    s->g(x);
}
