// from server: 78% by atomic.potato
extern "C" void __stdcall Function0078c270(const char *, const char *, const char *, const char *);

struct S
{
    void f(const char *, const char *);
};

void S::f(const char *a, const char *b)
{
    Function0078c270(a, b, "|$8h", "|$8h");
}
