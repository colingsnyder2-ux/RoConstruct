// from server: 60% by atomic.potato
extern "C" void rbx_exception_destructor(void *);

struct S
{
    int f();
    void *v0;
    void *v1;
    void *v2;
    void *v3;
};

int S::f()
{
    v0 = (void *)0x00b46484;
    v3 = (void *)0x00b4647c;
    v3 = (void *)0x00b43e60;

    if (v3 != 0)
    {
        void **table = *(void ***)v3;
        void (*destroy)(void *) =
            (void (*)(void *))table[4];
        destroy(v3);
    }

    rbx_exception_destructor(this);
    return 0;
}
