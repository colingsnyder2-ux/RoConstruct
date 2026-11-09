// roc 2012-06 004cc5c0  unit: Ogre::RbxSceneManagerFactory  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc5c0
//
// 004cc5c0  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004cc5c3  05e0450000           add eax, 0x45e0
// 004cc5c8  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004cc5c0 {
    char pad0[28];
    int m_x;
    int f();
};
int S_func_004cc5c0::f()
{
    return m_x + 0x45e0;
}
