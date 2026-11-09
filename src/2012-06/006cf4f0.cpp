// roc 2012-06 006cf4f0  unit: CInstanceRecord::CNameItem  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf4f0
//
// 006cf4f0  8b4168               mov eax, dword ptr [ecx + 0x68]
// 006cf4f3  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006cf4f0 {
    char pad0[104];
    int m_x;
    int f();
};
int S_func_006cf4f0::f()
{
    return m_x;
}
