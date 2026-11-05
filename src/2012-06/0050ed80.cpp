// from server: 53% by atomic.potato
struct S
{
    void *f(void *);
};

extern "C" void *__stdcall removeChild(void *);

void *S::f(void *arg)
{
    void *child = removeChild(arg);
    ((void (*)(S *, void *))0x0050ecf0)(this, child);
    return child;
}
