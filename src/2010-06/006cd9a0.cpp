// from server: 57% by atomic.potato
struct S
{
    typedef void (__thiscall *Callback)(S *, float, float, void *);
    Callback callback;
    int offset;

    void __cdecl f(void *arg, float x, float y);
};

void S::f(void *arg, float x, float y)
{
    callback = *(Callback *)((char *)arg);
    callback((S *)((char *)arg + *(int *)((char *)arg + 4) + *(int *)((char *)arg + 8)), x, y, this);
}
