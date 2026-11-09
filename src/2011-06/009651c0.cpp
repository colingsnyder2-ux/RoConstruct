// from server: 92% by atomic.potato
extern "C" void __cdecl G1_func_00500ae0();
extern "C" void __cdecl free(void *);

struct S
{
    void *f(unsigned char flag);
};

void *S::f(unsigned char flag)
{
    G1_func_00500ae0();
    if (flag & 1)
        free((char *)this - 4);
    return this;
}
