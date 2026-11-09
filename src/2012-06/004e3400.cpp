// roc 2012-06 004e3400  unit: Ogre::RbxTextureCompositorSceneManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e3400
//
// 004e3400  d981c0000000         fld dword ptr [ecx + 0xc0]
// 004e3406  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004e3400 {
    char pad[192];
    float m_x;
    float f();
};
float S_func_004e3400::f()
{
    return m_x;
}
