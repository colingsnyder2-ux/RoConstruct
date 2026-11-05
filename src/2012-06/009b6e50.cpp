// roc 2012-06 009b6e50  unit: CInstanceRecord::CNameItem  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b6e50
//
// 009b6e50  8b442404             mov eax, dword ptr [esp + 4]
// 009b6e54  894130               mov dword ptr [ecx + 0x30], eax
// 009b6e57  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009b6e50 {
    char pad0[48];
    int m_x;
    void f(int a1);
};
void S_func_009b6e50::f(int a1)
{
    m_x = (int)a1;
}
