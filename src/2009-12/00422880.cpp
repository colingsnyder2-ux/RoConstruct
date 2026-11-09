// from server: 57% by atomic.potato
struct S
{
    int value0c;
    int value5c;
};

struct T
{
    void sub_422670(int);
};

void T::sub_422670(int)
{
}

void __stdcall function_422880(S *p, int *out)
{
    ((T *)p)->sub_422670(p->value5c);
    *out = 0;
}
