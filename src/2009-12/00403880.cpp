// from server: 75% by atomic.potato
extern "C" void __cdecl free(void *);

struct S
{
    void *p;

    void f();
};

void S::f()
{
    while (p != 0)
    {
        void *q = p;
        p = *(void **)q;
        free(q);
    }
}
