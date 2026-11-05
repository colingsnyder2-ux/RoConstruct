// from server: 57% by atomic.potato
struct S
{
    int f();
};

extern "C" void __stdcall callee_5728d0(void *);
extern "C" void __stdcall callee_721250(void *, int);

int S::f()
{
    callee_5728d0((char *)this + 0x1d0);
    callee_721250(this, 0);
    return 0;
}
