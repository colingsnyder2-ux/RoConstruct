// roc 2012-06 009b6f40  unit: RBX::DS::CVideoStream  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b6f40
//
// 009b6f40  8b4130               mov eax, dword ptr [ecx + 0x30]
// 009b6f43  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009b6f40 {
    char pad0[48];
    int m_x;
    int f();
};
int S_func_009b6f40::f()
{
    return m_x;
}
