// roc 2012-06 0091cb20  unit: seg_00910000  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091cb20
//
// 0091cb20  c7411c0f000000       mov dword ptr [ecx + 0x1c], 0xf
// 0091cb27  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0091cb20 {
    char pad0[28];
    int m_x;
    void f();
};
void S_func_0091cb20::f()
{
    m_x = (int)0xf;
}
