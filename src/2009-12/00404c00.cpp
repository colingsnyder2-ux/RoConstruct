// from server: 90% by atomic.potato
typedef int (__thiscall *Function)(void *);

struct S
{
    int f();
};

S g_object;

int S::f()
{
    int value = ((Function *)(*(int *)((char *)&g_object + 12)))[0](&g_object);
    *(int *)this = value + 16;
    return (int)this;
}
