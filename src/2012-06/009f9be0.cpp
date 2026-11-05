// roc 2012-06 009f9be0  unit: RBX::ViewRbxGfx  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f9be0
//
// 009f9be0  8b4124               mov eax, dword ptr [ecx + 0x24]
// 009f9be3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f9be0 {
    char pad0[36];
    int m_x;
    int f();
};
int S_func_009f9be0::f()
{
    return m_x;
}
