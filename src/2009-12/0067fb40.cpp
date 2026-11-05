// from server: 60% by atomic.potato
typedef void (__thiscall *Helper1)(void *, void *);
typedef void (__cdecl *Helper2)(void *, void *, void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    char buffer[104];
    Helper1 h1 = (Helper1)0x0067f9b0;
    Helper2 h2 = (Helper2)0x007e17f0;
    h1((char *)this - 0xA4, buffer);
    h2(buffer, b, a);
}
