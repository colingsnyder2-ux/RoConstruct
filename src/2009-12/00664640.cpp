// from server: 40% by atomic.potato
struct S
{
    int f(void *);
};

typedef void (__thiscall *Callback)(void *, int);

int S::f(void *p)
{
    Callback callback = *(Callback *)(*(void **)p);
    callback(this, 0);
    return 0;
}
