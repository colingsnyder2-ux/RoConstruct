// roc 2012-06 005ba880  unit: RakNet::RakPeer  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba880
//
// 005ba880  668b410e             mov ax, word ptr [ecx + 0xe]
// 005ba884  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005ba880 {
    char pad0[14];
    short m_x;
    short f();
};
short S_func_005ba880::f()
{
    return m_x;
}
