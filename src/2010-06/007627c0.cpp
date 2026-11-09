// from server: 100% by atomic.potato
extern "C" void __cdecl sub_54D9C0(void *);

struct S
{
    void f();
};

void S::f()
{
    sub_54D9C0(*(void **)((char *)this + 0x18));
    *(int *)((char *)this + 0x18) = 0;
    *(int *)((char *)this + 0x1c) = 0;
    *(int *)((char *)this + 0x20) = 0;
}
