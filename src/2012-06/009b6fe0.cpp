// roc 2012-06 009b6fe0  unit: CInstanceRecord::CNameItem  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b6fe0
//
// 009b6fe0  8b4158               mov eax, dword ptr [ecx + 0x58]
// 009b6fe3  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009b6fe0 {
    char pad0[88];
    int m_x;
    int f(int a1);
};
int S_func_009b6fe0::f(int a1)
{
    return m_x;
}
