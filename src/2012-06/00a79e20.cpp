// roc 2012-06 00a79e20  unit: CXTCaptionButtonThemeOfficeXP  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79e20
//
// 00a79e20  8b442404             mov eax, dword ptr [esp + 4]
// 00a79e24  898194000000         mov dword ptr [ecx + 0x94], eax
// 00a79e2a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a79e20 {
    char pad0[148];
    int m_x;
    void f(int a1);
};
void S_func_00a79e20::f(int a1)
{
    m_x = (int)a1;
}
