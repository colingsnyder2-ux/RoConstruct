// roc 2012-06 0051b1a0  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b1a0
//
// 0051b1a0  8a81e8000000         mov al, byte ptr [ecx + 0xe8]
// 0051b1a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b1a0 {
    char pad0[232];
    char m_x;
    char f();
};
char S_func_0051b1a0::f()
{
    return m_x;
}
