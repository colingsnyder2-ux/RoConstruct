// roc 2012-06 005cad70  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005cad70
//
// 005cad70  8d8188000000         lea eax, [ecx + 0x88]
// 005cad76  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005cad70 {
    char pad0[136];
    int m_x;
    int* f();
};
int* S_func_005cad70::f()
{
    return &m_x;
}
