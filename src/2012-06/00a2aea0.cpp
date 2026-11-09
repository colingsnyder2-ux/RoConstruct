// from server: 52% by atomic.potato
extern "C" void __stdcall Imported(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    Imported(p, (char *)this + 0x74);
}
