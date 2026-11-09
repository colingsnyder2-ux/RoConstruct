// roc 2012-06 009b0bf0  unit: CXTPReportControl  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b0bf0
//
// 009b0bf0  8b442404             mov eax, dword ptr [esp + 4]
// 009b0bf4  8981b8020000         mov dword ptr [ecx + 0x2b8], eax
// 009b0bfa  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009b0bf0 {
    char pad0[696];
    int m_x;
    void f(int a1);
};
void S_func_009b0bf0::f(int a1)
{
    m_x = (int)a1;
}
