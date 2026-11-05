// roc 2012-06 0051b1d0  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b1d0
//
// 0051b1d0  8a818c000000         mov al, byte ptr [ecx + 0x8c]
// 0051b1d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b1d0 {
    char pad0[140];
    char m_x;
    char f();
};
char S_func_0051b1d0::f()
{
    return m_x;
}
