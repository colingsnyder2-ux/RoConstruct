// from server: 51% by atomic.potato
extern "C" void destroy_bad_cast(void *);

struct S
{
    int f();
    void *v0;
    char padding[16];
    void *v14;
    void *v18;
};

int S::f()
{
    v0 = (void *)0x00A94814;
    v14 = (void *)0x00A9480C;
    v14 = (void *)0x00A5BFDC;
    if (v18 != 0)
        destroy_bad_cast(v18);
    v0 = (void *)0x00A94524;
    return 0;
}
