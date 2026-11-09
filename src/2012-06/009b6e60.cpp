// roc 2012-06 009b6e60  unit: CInstanceRecord::CNameItem  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b6e60
//
// 009b6e60  8b442404             mov eax, dword ptr [esp + 4]
// 009b6e64  89413c               mov dword ptr [ecx + 0x3c], eax
// 009b6e67  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009b6e60 {
    char pad0[60];
    int m_x;
    void f(int a1);
};
void S_func_009b6e60::f(int a1)
{
    m_x = (int)a1;
}
