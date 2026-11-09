// roc 2012-06 00a56490  unit: CXTPPropertyGridInplaceButton  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a56490
//
// 00a56490  8b4144               mov eax, dword ptr [ecx + 0x44]
// 00a56493  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a56490 {
    char pad0[68];
    int m_x;
    int f();
};
int S_func_00a56490::f()
{
    return m_x;
}
