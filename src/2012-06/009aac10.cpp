// roc 2012-06 009aac10  unit: CXTPReportControl  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009aac10
//
// 009aac10  8b442404             mov eax, dword ptr [esp + 4]
// 009aac14  8981c0010000         mov dword ptr [ecx + 0x1c0], eax
// 009aac1a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009aac10 {
    char pad0[448];
    int m_x;
    void f(int a1);
};
void S_func_009aac10::f(int a1)
{
    m_x = (int)a1;
}
