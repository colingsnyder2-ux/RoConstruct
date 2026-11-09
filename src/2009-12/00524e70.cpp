// from server: 8% by atomic.potato
struct T
{
    void f();
};

struct S
{
    void f();
};

void T::f()
{
}

void S::f()
{
    T *p = (T *)((char *)this + 0x20);
    p->f();
}
