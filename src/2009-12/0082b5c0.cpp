// from server: 86% by atomic.potato
extern "C" double __cdecl atof(const char *);

struct S
{
    char padding[0x80];
    double value;
    void f(const char *);
};

void S::f(const char *text)
{
    value = atof(text);
}
