// roc 2012-06 009b0c30  unit: CXTPReportControl  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b0c30
//
// 009b0c30  8b442404             mov eax, dword ptr [esp + 4]
// 009b0c34  8981bc010000         mov dword ptr [ecx + 0x1bc], eax
// 009b0c3a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009b0c30 {
    char pad0[444];
    int m_x;
    void f(int a1);
};
void S_func_009b0c30::f(int a1)
{
    m_x = (int)a1;
}
