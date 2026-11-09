// from server: 53% by atomic.potato
typedef unsigned long DWORD;

typedef void (__thiscall *Callback)(void *, void *);

struct S
{
    Callback callback;
    void *context;
    void f(void *, void *, void *, void *);
};

void S::f(void *a, void *b, void *c, void *d)
{
    void *args[4];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    callback(context, args);
}
