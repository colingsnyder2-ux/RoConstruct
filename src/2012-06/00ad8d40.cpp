// from server: 40% by atomic.potato
extern "C" void __cdecl sub_00983270(void *, unsigned int, unsigned int, const void *);

struct seg_00ad0000
{
    void f();
};

void seg_00ad0000::f()
{
    unsigned char local[436];
    sub_00983270(local, 0x30, 2, (const void *)0x0059a790);
}
