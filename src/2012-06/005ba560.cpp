// roc 2012-06 005ba560  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba560
//
// 005ba560  8b442404             mov eax, dword ptr [esp + 4]
// 005ba564  894104               mov dword ptr [ecx + 4], eax
// 005ba567  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_005ba560 {
    char pad0[4];
    int m_x;
    void f(int a1);
};
void S_func_005ba560::f(int a1)
{
    m_x = (int)a1;
}
