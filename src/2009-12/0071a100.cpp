// from server: 96% by sophus
struct Inner {
    virtual int f();
    virtual int f2();
    char pad[4];
    Inner* next;
    void h(int);
};

struct Outer {
    char pad[0xd8];
    Inner* p;
    void g(int);
};

void Outer::g(int x)
{
    Inner* s = p;
    while (s->f2() != 2)
        s = s->next;
    s->h(x);
}
