// roc 2012-06 00928ec0  unit: RBX::PolyContact  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00928ec0
//
// 00928ec0  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 00928ec6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00928ec0 {
    char pad0[204];
    int m_x;
    int f();
};
int S_func_00928ec0::f()
{
    return m_x;
}
