// roc 2012-06 009aac60  unit: CXTCaptionButtonTheme  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009aac60
//
// 009aac60  8b442404             mov eax, dword ptr [esp + 4]
// 009aac64  894128               mov dword ptr [ecx + 0x28], eax
// 009aac67  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009aac60 {
    char pad0[40];
    int m_x;
    void f(int a1);
};
void S_func_009aac60::f(int a1)
{
    m_x = (int)a1;
}
