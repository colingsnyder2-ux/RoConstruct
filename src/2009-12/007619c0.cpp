// from server: 13% by atomic.potato
struct Inner {
    char pad0[8];
    void f(int, void*, int);
};

struct Outer {
    Inner* p;
    void g(int, void*, int);
};

void Outer::g(int a, void* b, int c)
{
    Inner* q = p;
    q->f(a, b, c);
}
