// roc 2012-06 004cc5e0  unit: Ogre::RbxSceneManagerFactory  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc5e0
//
// 004cc5e0  8b442404             mov eax, dword ptr [esp + 4]
// 004cc5e4  898188080000         mov dword ptr [ecx + 0x888], eax
// 004cc5ea  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_004cc5e0 {
    char pad0[2184];
    int m_x;
    void f(int a1);
};
void S_func_004cc5e0::f(int a1)
{
    m_x = (int)a1;
}
