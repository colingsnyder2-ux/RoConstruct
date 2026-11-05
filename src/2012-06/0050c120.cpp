// roc 2012-06 0050c120  unit: Ogre::RbxArchive  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050c120
//
// 0050c120  c7410800000000       mov dword ptr [ecx + 8], 0
// 0050c127  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0050c120 {
    char pad0[8];
    int m_x;
    void f();
};
void S_func_0050c120::f()
{
    m_x = (int)0;
}
