// from server: 43% by atomic.potato
struct S
{
    int f();
};

struct T
{
    char *begin;
    char *end;
};

extern "C" T *__cdecl helper(S *);

int S::f()
{
    if (*(int *)((char *)this + 0x3c) != 0)
    {
        T *p = helper(this);
        return p->end - p->begin != 0;
    }
    return 0;
}
