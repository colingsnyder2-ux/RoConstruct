// roc 2012-06 005bb150  unit: RakNet::RakPeer  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb150
//
// 005bb150  8b442404             mov eax, dword ptr [esp + 4]
// 005bb154  898168040000         mov dword ptr [ecx + 0x468], eax
// 005bb15a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_005bb150 {
    char pad0[1128];
    int m_x;
    void f(int a1);
};
void S_func_005bb150::f(int a1)
{
    m_x = (int)a1;
}
