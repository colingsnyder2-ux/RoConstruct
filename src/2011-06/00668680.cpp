// from server: 64% by atomic.potato
extern "C" void __cdecl sub_0080B15D();

struct BoundFuncDesc
{
    void *f();
};

void *BoundFuncDesc::f()
{
    extern unsigned char g_00CCDE0C;
    extern void *g_00CCDE08;
    g_00CCDE0C += 0;
    sub_0080B15D();
    return g_00CCDE08;
}
