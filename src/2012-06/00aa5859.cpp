// from server: 46% by atomic.potato
extern "C" void __cdecl sub_00983270(void *, unsigned int, unsigned int, void *);

struct seg_00aa0000
{
    void f();
};

void seg_00aa0000::f()
{
    extern void *g_00b22dd8;
    char local[0x248];
    sub_00983270(local, 0x10, 6, g_00b22dd8);
}
