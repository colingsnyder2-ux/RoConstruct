// roc 2012-06 004cc450  unit: Ogre::RbxSceneManagerFactory  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc450
//
// 004cc450  8b8148080000         mov eax, dword ptr [ecx + 0x848]
// 004cc456  c3                   ret 
// auto-matched from its assembly shape

struct S_func_004cc450 {
    char pad0[2120];
    int m_x;
    int f();
};
int S_func_004cc450::f()
{
    return m_x;
}
