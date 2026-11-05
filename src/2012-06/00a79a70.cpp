// roc 2012-06 00a79a70  unit: VWiniInetRequest_source::?$stream_buffer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79a70
//
// 00a79a70  8b442404             mov eax, dword ptr [esp + 4]
// 00a79a74  89414c               mov dword ptr [ecx + 0x4c], eax
// 00a79a77  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a79a70 {
    char pad0[76];
    int m_x;
    void f(int a1);
};
void S_func_00a79a70::f(int a1)
{
    m_x = (int)a1;
}
