// from server: 42% by atomic.potato
struct S
{
    void __cdecl f(const char *, const char *);
};

void S::f(const char *a, const char *b)
{
    char buffer[16];
    extern void g(const char *, const char *, char *, int);
    g(a, b, buffer, 4);
}
