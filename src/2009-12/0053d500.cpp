// from server: 44% by atomic.potato
struct S
{
    int f();
};

struct T
{
    int (**vtable)();
    int value;
};

S* S_f(S*);

int S::f()
{
    T* p;
    int (*fn)();

    p = (T*)S_f(this);
    fn = p->vtable[0];
    return fn();
}
