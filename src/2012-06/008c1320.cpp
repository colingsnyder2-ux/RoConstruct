// roc 2012-06 008c1320  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c1320
//
// 008c1320  8a8100010000         mov al, byte ptr [ecx + 0x100]
// 008c1326  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c1320 {
    char pad0[256];
    char m_x;
    char f();
};
char S_func_008c1320::f()
{
    return m_x;
}
