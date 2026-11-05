// from server: 56% by atomic.potato
extern "C" void CopyString(void *, const void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    void **vtable = *(void ***)this;
    typedef void (*Fn)(void *, int *);
    Fn fn = (Fn)vtable[5];
    int value = 0;
    fn((char *)this + 0x0c, &value);
    CopyString(arg, (char *)this + 0x0c);
    return (int)arg;
}
