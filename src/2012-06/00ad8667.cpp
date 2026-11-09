// from server: 61% by atomic.potato
extern "C" void __cdecl sub_00983270(void *, int, int, const void *);

struct seg_00ad0000
{
    int pad[58];
    void f();
};

void seg_00ad0000::f()
{
    sub_00983270((char *)this + 0xe8, 0x10, 2, (const void *)0x9611b0);
}
