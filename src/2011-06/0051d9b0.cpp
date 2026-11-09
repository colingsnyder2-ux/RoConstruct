// from server: 41% by atomic.potato
extern "C" void __cdecl free(void *);

struct S
{
    void *f(unsigned char);
};

void *S::f(unsigned char flag)
{
    void *p = (char *)this - 4;
    if (flag & 1)
        free(p);
    return this;
}
