// roc 2012-06 007aa560  unit: RBX::KeyframeSequence  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007aa560
//
// 007aa560  d9817c010000         fld dword ptr [ecx + 0x17c]
// 007aa566  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007aa560 {
    char pad[380];
    float m_x;
    float f();
};
float S_func_007aa560::f()
{
    return m_x;
}
