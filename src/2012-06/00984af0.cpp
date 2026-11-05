// roc 2012-06 00984af0  unit: CPropertyGridItemBrickColor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984af0
//
// 00984af0  8b810c010000         mov eax, dword ptr [ecx + 0x10c]
// 00984af6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00984af0 {
    char pad0[268];
    int m_x;
    int f();
};
int S_func_00984af0::f()
{
    return m_x;
}
