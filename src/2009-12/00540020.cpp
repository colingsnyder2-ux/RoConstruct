// from server: 62% by atomic.potato
struct S
{
};

extern "C" void * __cdecl sub_0053f2f0(void *);

int __cdecl f(void *p)
{
    void *v = sub_0053f2f0(p);
    *(void **)((char *)p + 4) = *(void **)((char *)v + 4);
    *(void **)p = *(void **)v;
    return (int)p;
}
