// roc 2012-06 004e3410  unit: Ogre::RbxTextureCompositorSceneManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004e3410
//
// 004e3410  d981ac010000         fld dword ptr [ecx + 0x1ac]
// 004e3416  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004e3410 {
    char pad[428];
    float m_x;
    float f();
};
float S_func_004e3410::f()
{
    return m_x;
}
