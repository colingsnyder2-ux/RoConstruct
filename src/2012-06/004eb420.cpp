// roc 2012-06 004eb420  unit: Ogre::RbxSceneNode  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004eb420
//
// 004eb420  8b442404             mov eax, dword ptr [esp + 4]
// 004eb424  894160               mov dword ptr [ecx + 0x60], eax
// 004eb427  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_004eb420 {
    char pad0[96];
    int m_x;
    void f(int a1);
};
void S_func_004eb420::f(int a1)
{
    m_x = (int)a1;
}
