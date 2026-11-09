// from server: 89% by atomic.potato
extern "C" void destroy_stream(void *);
extern "C" void __cdecl release_stream(void *);

struct S
{
    void *reserved[20];
    void *f(unsigned char);
};

void *S::f(unsigned char flags)
{
    void *p = (char *)this - 0x50;
    destroy_stream(p);
    if (flags & 1)
        release_stream(p);
    return p;
}
