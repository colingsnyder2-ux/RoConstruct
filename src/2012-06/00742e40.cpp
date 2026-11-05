// from server: 84% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void __cdecl sub_742db0(void *);

void S::f(void *p)
{
    unsigned char value[4];
    sub_742db0(value);
    *(unsigned char *)p = value[0];
    *((unsigned char *)p + 1) = value[1];
    *((unsigned char *)p + 2) = value[2];
}
