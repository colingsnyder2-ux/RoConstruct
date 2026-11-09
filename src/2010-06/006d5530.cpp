// from server: 46% by atomic.potato
extern "C" void *__cdecl sub_670EE0(void *);

struct RefPropDescriptor
{
    void target(unsigned int a, unsigned int b);
};

void RefPropDescriptor::target(unsigned int a, unsigned int b)
{
    void *v;
    if (a)
        v = sub_670EE0((void *)a);
    else
        v = 0;

    void *p = *((void **)this + 8);
    void *q = *(void **)p;
    void (*fn)(void *, void *) = *(void (**)(void *, void *))((char *)q + 0x10);
    fn(p, v);
}
