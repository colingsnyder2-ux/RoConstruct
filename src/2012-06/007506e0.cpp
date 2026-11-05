// roc 2012-06 007506e0  unit: RBX::ContentProvider::UCachedContent::?$AsyncHttpCache  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007506e0
//
// 007506e0  d981e8010000         fld dword ptr [ecx + 0x1e8]
// 007506e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007506e0 {
    char pad[488];
    float m_x;
    float f();
};
float S_func_007506e0::f()
{
    return m_x;
}
