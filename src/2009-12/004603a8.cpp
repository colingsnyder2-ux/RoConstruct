// from server: 41% by atomic.potato
extern "C" void Target(void *, void *, void *, void *, void *);

struct VerbBinder
{
    void *f(void *, void *, void *, void *);
};

void *VerbBinder::f(void *a, void *b, void *c, void *d)
{
    Target((void *)0x4602c9, a, b, c, d);
    return 0;
}
