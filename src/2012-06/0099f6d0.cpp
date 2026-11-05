// roc 2012-06 0099f6d0  unit: CXTPToolBar  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0099f6d0
//
// 0099f6d0  8b442404             mov eax, dword ptr [esp + 4]
// 0099f6d4  8981ec000000         mov dword ptr [ecx + 0xec], eax
// 0099f6da  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0099f6d0 {
    char pad0[236];
    int m_x;
    void f(int a1);
};
void S_func_0099f6d0::f(int a1)
{
    m_x = (int)a1;
}
