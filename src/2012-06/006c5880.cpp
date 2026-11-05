// from server: 34% by atomic.potato
struct S
{
    int f(int);
};

typedef int (__thiscall *LookupProc)(void *, int *);
typedef int (__thiscall *AssignProc)(void *, int *);

int S::f(int value)
{
    LookupProc lookup = (LookupProc)0x006c3ec0;
    AssignProc assign = (AssignProc)0x0076a190;
    int *result = (int *)lookup(this, &value + 1);
    int temporary = *result;
    return assign(this, &temporary);
}
