// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_8a9850(void *, int);
extern "C" void __cdecl sub_982114(void *);

void S::f()
{
    void *p = *(void **)((char *)this + 0x0c);
    if (p != 0)
    {
        sub_8a9850(p, *(int *)((char *)p + 0x0c));
        sub_982114(p);
    }
}
