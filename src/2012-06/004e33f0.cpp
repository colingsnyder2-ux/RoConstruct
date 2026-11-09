// roc 2012-06 004e33f0  unit: Ogre::RbxTextureCompositorSceneManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e33f0
//
// 004e33f0  d981bc000000         fld dword ptr [ecx + 0xbc]
// 004e33f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004e33f0 {
    char pad[188];
    float m_x;
    float f();
};
float S_func_004e33f0::f()
{
    return m_x;
}
