// from server: 89% by atomic.potato
extern "C" void __stdcall sub_7737f0(void *, int, int);
extern "C" void __stdcall sub_40c080(void *, const void *);

struct S
{
    void f(int);
};

void S::f(int arg)
{
    void *p = *(void **)((char *)this + 0xb4);
    sub_7737f0(p, 0, arg);
    sub_40c080(this, (const void *)0xb956dc);
}
