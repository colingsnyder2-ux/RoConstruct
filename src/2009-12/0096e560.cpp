// from server: 33% by atomic.potato
typedef int (__cdecl *Function)(void);

struct S
{
    int f();
};

int S::f()
{
    return ((Function)(*(int *)((char *)this + 0x40)))();
}
