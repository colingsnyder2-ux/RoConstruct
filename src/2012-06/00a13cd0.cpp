// roc 2012-06 00a13cd0  unit: CXTPControlEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a13cd0
//
// 00a13cd0  c7818401000001000000 mov dword ptr [ecx + 0x184], 1
// 00a13cda  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a13cd0 {
    char pad0[388];
    int m_x;
    void f();
};
void S_func_00a13cd0::f()
{
    m_x = (int)1;
}
