// roc 2012-06 004f3c90  unit: Ogre::RbxMeshPartAdapter  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f3c90
//
// 004f3c90  8d4158               lea eax, [ecx + 0x58]
// 004f3c93  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004f3c90 {
    char pad0[88];
    int m_x;
    int* f();
};
int* S_func_004f3c90::f()
{
    return &m_x;
}
