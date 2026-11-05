// from server: 48% by atomic.potato
extern "C" void *sub_917690(void *);
extern "C" void __stdcall sub_868bc0(void *);

struct S_008ff6b0
{
    char pad0[148];

    void f();
};

void S_008ff6b0::f()
{
    void *p = 0;
    if (this)
        p = (void *)((char *)this + 148);
    sub_868bc0(sub_917690(p));
}
