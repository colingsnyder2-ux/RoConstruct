// from server: 82% by colin
struct Inner {
    virtual void g();
    virtual void f(int);
};

struct Outer {
    Inner* p;
    void m();
};

void Outer::m()
{
    Inner* q = p;
    if (q != 0) {
        q->f(1);
    }
}
