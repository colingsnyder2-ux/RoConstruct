// from server: 40% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    struct T
    {
        void (*p)();
    };
    ((T*)0)->p();
}
