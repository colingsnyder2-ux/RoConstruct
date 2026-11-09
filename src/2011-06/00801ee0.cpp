// from server: 51% by atomic.potato
extern "C" unsigned long __stdcall GetCurrentDirectoryA(unsigned long, char *);

struct S
{
    unsigned long __cdecl f(unsigned long, char *);
};

unsigned long __cdecl S::f(unsigned long a, char *b)
{
    return GetCurrentDirectoryA(a, b);
}
