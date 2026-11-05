// roc 2012-06 009d7a00  unit: CXTPPropExchange  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7a00
//
// 009d7a00  c7413401000000       mov dword ptr [ecx + 0x34], 1
// 009d7a07  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009d7a00 {
    char pad0[52];
    int m_x;
    void f();
};
void S_func_009d7a00::f()
{
    m_x = (int)1;
}
