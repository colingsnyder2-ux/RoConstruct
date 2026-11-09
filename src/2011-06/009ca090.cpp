// from server: 52% by atomic.potato
extern "C" int __cdecl _strnicmp(const char *, const char *, unsigned int);

struct S
{
    int __cdecl f(const char *, const char *, unsigned int);
};

int __cdecl S::f(const char *a, const char *b, unsigned int n)
{
    return _strnicmp(a, b, n);
}
