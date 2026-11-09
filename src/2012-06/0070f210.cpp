// roc 2012-06 0070f210  unit: RBX::HopperBin  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0070f210
//
// 0070f210  8a81c0010000         mov al, byte ptr [ecx + 0x1c0]
// 0070f216  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0070f210 {
    char pad0[448];
    char m_x;
    char f();
};
char S_func_0070f210::f()
{
    return m_x;
}
