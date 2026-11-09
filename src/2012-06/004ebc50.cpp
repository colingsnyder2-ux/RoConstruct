// roc 2012-06 004ebc50  unit: Ogre::RbxSubEntity  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ebc50
//
// 004ebc50  8a4150               mov al, byte ptr [ecx + 0x50]
// 004ebc53  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004ebc50 {
    char pad0[80];
    char m_x;
    char f();
};
char S_func_004ebc50::f()
{
    return m_x;
}
