// roc 2012-06 0051b170  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b170
//
// 0051b170  8a8189010000         mov al, byte ptr [ecx + 0x189]
// 0051b176  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b170 {
    char pad0[393];
    char m_x;
    char f();
};
char S_func_0051b170::f()
{
    return m_x;
}
