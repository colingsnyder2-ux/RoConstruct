// roc 2012-06 00900260  unit: RBX::NormalBreakConnector  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00900260
//
// 00900260  8a8184000000         mov al, byte ptr [ecx + 0x84]
// 00900266  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00900260 {
    char pad0[132];
    char m_x;
    char f();
};
char S_func_00900260::f()
{
    return m_x;
}
