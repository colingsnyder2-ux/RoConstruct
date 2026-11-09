// from server: 77% by atomic.potato
struct S;

extern "C" int sub_0076a500(const char *);

struct S
{
    int f(const char *);
};

extern "C" void sub_0076a190(S *, const char *);

int S::f(const char *p)
{
    int value = *(int *)sub_0076a500(p + 4);
    sub_0076a190(this, (const char *)&value);
    return 0;
}
