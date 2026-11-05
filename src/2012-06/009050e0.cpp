// roc 2012-06 009050e0  unit: RBX::HUMAN::HumanoidState  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009050e0
//
// 009050e0  8b442404             mov eax, dword ptr [esp + 4]
// 009050e4  898180020000         mov dword ptr [ecx + 0x280], eax
// 009050ea  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009050e0 {
    char pad0[640];
    int m_x;
    void f(int a1);
};
void S_func_009050e0::f(int a1)
{
    m_x = (int)a1;
}
