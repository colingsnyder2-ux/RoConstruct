// roc 2012-06 0051b1e0  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b1e0
//
// 0051b1e0  8a81c0000000         mov al, byte ptr [ecx + 0xc0]
// 0051b1e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b1e0 {
    char pad0[192];
    char m_x;
    char f();
};
char S_func_0051b1e0::f()
{
    return m_x;
}
