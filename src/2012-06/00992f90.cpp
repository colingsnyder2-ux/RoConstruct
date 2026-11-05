// roc 2012-06 00992f90  unit: CXTPCommandBar  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992f90
//
// 00992f90  8b442404             mov eax, dword ptr [esp + 4]
// 00992f94  8981c8000000         mov dword ptr [ecx + 0xc8], eax
// 00992f9a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00992f90 {
    char pad0[200];
    int m_x;
    void f(int a1);
};
void S_func_00992f90::f(int a1)
{
    m_x = (int)a1;
}
