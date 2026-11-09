// from server: 70% by atomic.potato
typedef void (__cdecl *Callback)(void *, int);

struct S
{
};

void __cdecl f(void *arg)
{
    Callback callback = *(Callback *)arg;
    callback(arg, *(int *)((char *)arg + 4) + *(int *)((char *)arg + 8));
}
