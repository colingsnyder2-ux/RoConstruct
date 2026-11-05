// from server: 69% by atomic.potato
extern "C" void __cdecl invalid_parameter_noinfo();

struct S
{
    int f(void **);
};

int S::f(void **p)
{
    unsigned char *a = *(unsigned char **)((char *)this + 4);
    unsigned int b = *(unsigned int *)(a + 0x4c);
    unsigned char *c = a + 0x3c;

    if (*(unsigned int *)(c + 0xc) <= b)
        invalid_parameter_noinfo();

    void **q = p;
    q[0] = this;
    q[1] = *(void **)c;
    q[2] = (void *)b;
    return 0;
}
