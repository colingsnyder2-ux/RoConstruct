// roc 2012-06 00a79e40  unit: CXTCaptionButtonThemeOfficeXP  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79e40
//
// 00a79e40  8b442404             mov eax, dword ptr [esp + 4]
// 00a79e44  8981ac000000         mov dword ptr [ecx + 0xac], eax
// 00a79e4a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a79e40 {
    char pad0[172];
    int m_x;
    void f(int a1);
};
void S_func_00a79e40::f(int a1)
{
    m_x = (int)a1;
}
