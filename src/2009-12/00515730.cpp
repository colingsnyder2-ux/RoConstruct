// from server: 54% by atomic.potato
typedef int (__thiscall *FunctionType)(void *, int);

struct S
{
    int f(void *);
};

int S::f(void *a)
{
    FunctionType fn = (FunctionType)*(void **)a;
    return fn(*(void **)((char *)a + 4), *(int *)((char *)a + 8));
}
