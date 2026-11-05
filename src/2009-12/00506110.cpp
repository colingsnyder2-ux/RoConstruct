// from server: 47% by atomic.potato
struct T
{
    int (**vtable)();
    int value;
    int offset;
};

struct S
{
    void f(T *);
};

void S::f(T *arg)
{
    int (**fn)() = arg->vtable;
    fn[0]();
}
