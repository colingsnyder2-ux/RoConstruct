// roc 2012-06 0050cca0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050cca0
//
// 0050cca0  8b81c4010000         mov eax, dword ptr [ecx + 0x1c4]
// 0050cca6  8b4074               mov eax, dword ptr [eax + 0x74]
// 0050cca9  c3                   ret 
// auto-matched from its assembly shape

struct I_func_0050cca0 {
    char pad[116];
    int m_x;
};
struct S_func_0050cca0 {
    char pad[452];
    I_func_0050cca0* m_p;
    int f();
};
int S_func_0050cca0::f()
{
    return m_p->m_x;
}
