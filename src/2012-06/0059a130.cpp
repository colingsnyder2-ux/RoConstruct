// roc 2012-06 0059a130  unit: RBX::Network::Marker  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059a130
//
// 0059a130  8a81bc080000         mov al, byte ptr [ecx + 0x8bc]
// 0059a136  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0059a130 {
    char pad0[2236];
    char m_x;
    char f();
};
char S_func_0059a130::f()
{
    return m_x;
}
