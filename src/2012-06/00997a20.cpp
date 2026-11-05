// roc 2012-06 00997a20  unit: CXTPPropertyGridItemConstraint  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00997a20
//
// 00997a20  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 00997a23  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00997a20 {
    char pad0[44];
    int m_x;
    int f();
};
int S_func_00997a20::f()
{
    return m_x;
}
