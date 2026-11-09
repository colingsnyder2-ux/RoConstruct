// from server: 80% by atomic.potato
extern "C" void __cdecl boost_thread_destructor(void *);

void f(void *);

struct S
{
    void f();
    void *vtable;
    int a;
    int b;
    void *thread;
};

void S::f()
{
    void *p = thread;
    if (p != 0)
    {
        boost_thread_destructor(p);
        ::f(p);
    }
}
