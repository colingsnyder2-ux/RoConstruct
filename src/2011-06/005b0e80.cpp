// from server: 48% by atomic.potato
struct S
{
    int f(int);
};

typedef void (__fastcall *VFunc)(void *, void *);

extern "C" void __cdecl StringCopy(void *, const void *);

int S::f(int value)
{
    void *p = *(void **)this;
    VFunc fn = *(VFunc *)((char *)p + 0x14);
    fn(this, 0);
    char *q = (char *)this + 0x0c;
    StringCopy(q, (const void *)value);
    return value;
}
