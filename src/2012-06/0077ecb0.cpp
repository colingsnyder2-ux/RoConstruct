// from server: 51% by atomic.potato
extern "C" void *sym(void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    sym((char *)p + 4);
}
