// roc 2012-06 006cf4e0  unit: CInstanceRecord::CNameItem  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf4e0
//
// 006cf4e0  8b416c               mov eax, dword ptr [ecx + 0x6c]
// 006cf4e3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf4e0 {
    char pad0[108];
    int m_x;
    int f();
};
int S_func_006cf4e0::f()
{
    return m_x;
}
