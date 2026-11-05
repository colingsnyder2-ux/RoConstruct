// from server: 92% by atomic.potato
extern "C" int __cdecl _snprintf(char *, unsigned int, const char *, ...);

struct S
{
    char *f(char *);
    char *a;
    char *b;
    char c[1];
};

char *S::f(char *p)
{
    char *q;
    if (p)
        q = p;
    else
        q = a;
    _snprintf(c, 100, "QPjdV", q, b);
    return c;
}
