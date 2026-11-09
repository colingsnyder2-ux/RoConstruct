// from server: 61% by atomic.potato
struct S
{
    struct Base
    {
        virtual int f(int) = 0;
    };

    int pad0;
    int pad1;
    int pad2;
    int pad3;
    Base *base;

    int f(int);
};

extern "C" void sub_676f40(S *);

int S::f(int a)
{
    Base *p = base;
    int r = p->f(a);
    S *q = this + 4;
    sub_676f40(q);
    q->pad2 = r;
    q->pad1 = 5;
    return r;
}
