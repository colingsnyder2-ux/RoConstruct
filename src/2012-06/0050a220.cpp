// roc 2012-06 0050a220  unit: Ogre::RbxArchiveFactory  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050a220
//
// 0050a220  8d4108               lea eax, [ecx + 8]
// 0050a223  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0050a220 {
    char pad0[8];
    int m_x;
    int* f();
};
int* S_func_0050a220::f()
{
    return &m_x;
}
