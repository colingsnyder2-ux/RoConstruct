// roc 2012-06 0051b190  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b190
//
// 0051b190  8a8198000000         mov al, byte ptr [ecx + 0x98]
// 0051b196  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b190 {
    char pad0[152];
    char m_x;
    char f();
};
char S_func_0051b190::f()
{
    return m_x;
}
