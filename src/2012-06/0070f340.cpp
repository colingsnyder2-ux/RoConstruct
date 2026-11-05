// roc 2012-06 0070f340  unit: RBX::HopperBin  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0070f340
//
// 0070f340  8a8125020000         mov al, byte ptr [ecx + 0x225]
// 0070f346  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0070f340 {
    char pad0[549];
    char m_x;
    char f();
};
char S_func_0070f340::f()
{
    return m_x;
}
