// roc 2012-06 007506d0  unit: RBX::ContentProvider::UCachedContent::?$AsyncHttpCache  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007506d0
//
// 007506d0  d981a8010000         fld dword ptr [ecx + 0x1a8]
// 007506d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007506d0 {
    char pad[424];
    float m_x;
    float f();
};
float S_func_007506d0::f()
{
    return m_x;
}
