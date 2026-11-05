// from server: 59% by atomic.potato
struct S
{
    void f(void *);
};

typedef void (*Callback)(void *, void *, int);

extern "C" void __cdecl sub_636A50(void *);

void S::f(void *arg)
{
    sub_636A50(arg);
    Callback callback = (Callback)(*(unsigned long *)(*(unsigned long *)arg + 0x0c));
    callback(arg, this, 0);
}
