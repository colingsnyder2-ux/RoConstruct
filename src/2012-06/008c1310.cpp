// roc 2012-06 008c1310  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c1310
//
// 008c1310  8a8101010000         mov al, byte ptr [ecx + 0x101]
// 008c1316  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008c1310 {
    char pad0[257];
    char m_x;
    char f();
};
char S_func_008c1310::f()
{
    return m_x;
}
