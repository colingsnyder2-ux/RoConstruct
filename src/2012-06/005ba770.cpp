// roc 2012-06 005ba770  unit: RakNet::RakPeer  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba770
//
// 005ba770  668b4110             mov ax, word ptr [ecx + 0x10]
// 005ba774  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005ba770 {
    char pad0[16];
    short m_x;
    short f();
};
short S_func_005ba770::f()
{
    return m_x;
}
