// roc 2012-06 0051b210  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b210
//
// 0051b210  8a81f4000000         mov al, byte ptr [ecx + 0xf4]
// 0051b216  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b210 {
    char pad0[244];
    char m_x;
    char f();
};
char S_func_0051b210::f()
{
    return m_x;
}
