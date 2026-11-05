// roc 2012-06 00686460  unit: RBX::VInstance::?$EventDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00686460
//
// 00686460  8a819d000000         mov al, byte ptr [ecx + 0x9d]
// 00686466  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00686460 {
    char pad0[157];
    char m_x;
    char f();
};
char S_func_00686460::f()
{
    return m_x;
}
