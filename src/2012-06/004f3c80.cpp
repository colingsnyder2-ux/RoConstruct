// roc 2012-06 004f3c80  unit: Ogre::RbxMeshPartAdapter  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f3c80
//
// 004f3c80  8d4148               lea eax, [ecx + 0x48]
// 004f3c83  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004f3c80 {
    char pad0[72];
    int m_x;
    int* f();
};
int* S_func_004f3c80::f()
{
    return &m_x;
}
