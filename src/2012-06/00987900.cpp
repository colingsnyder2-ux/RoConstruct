// roc 2012-06 00987900  unit: CRobloxControlColorSelector  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00987900
//
// 00987900  8d8148010000         lea eax, [ecx + 0x148]
// 00987906  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00987900 {
    char pad0[328];
    int m_x;
    int* f();
};
int* S_func_00987900::f()
{
    return &m_x;
}
