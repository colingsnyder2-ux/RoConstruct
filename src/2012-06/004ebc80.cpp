// roc 2012-06 004ebc80  unit: Ogre::RbxSubEntity  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ebc80
//
// 004ebc80  d98164010000         fld dword ptr [ecx + 0x164]
// 004ebc86  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004ebc80 {
    char pad[356];
    float m_x;
    float f();
};
float S_func_004ebc80::f()
{
    return m_x;
}
