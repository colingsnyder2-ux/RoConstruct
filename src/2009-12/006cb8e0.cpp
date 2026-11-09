// from server: 90% by atomic.potato
extern "C" void __stdcall Function006EC360(void *, void *);

struct S
{
    void f();
};

void S::f()
{
    void *p = (char *)this + 0x0c;
    Function006EC360(*(void **)((char *)this + 0x164), p);
}
