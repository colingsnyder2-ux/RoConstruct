// from server: 77% by atomic.potato
extern "C" void __stdcall sub_785A00(void *);

struct S
{
    S *f(void *);
};

S *S::f(void *arg)
{
    sub_785A00(arg);
    *(unsigned long *)this = 0x009ed48c;
    *(unsigned long *)((char *)this + 4) = 0x009ed470;
    *(unsigned long *)((char *)this + 0x1c) = 0;
    *(unsigned long *)((char *)this + 0x20) = 0;
    return this;
}
