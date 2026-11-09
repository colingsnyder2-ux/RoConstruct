// from server: 52% by atomic.potato
extern "C" unsigned long __stdcall inet_addr(const char *);

struct S
{
    void __cdecl f(unsigned long *);
};

void S::f(unsigned long *value)
{
    *value = inet_addr((const char *)0);
}
