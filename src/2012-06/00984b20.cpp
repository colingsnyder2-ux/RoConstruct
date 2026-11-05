// roc 2012-06 00984b20  unit: CPropertyGridItemBrickColor  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984b20
//
// 00984b20  8b442404             mov eax, dword ptr [esp + 4]
// 00984b24  8981d4000000         mov dword ptr [ecx + 0xd4], eax
// 00984b2a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00984b20 {
    char pad0[212];
    int m_x;
    void f(int a1);
};
void S_func_00984b20::f(int a1)
{
    m_x = (int)a1;
}
