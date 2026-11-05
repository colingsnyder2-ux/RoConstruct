// roc 2012-06 0085a460  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085a460
//
// 0085a460  8b442404             mov eax, dword ptr [esp + 4]
// 0085a464  894144               mov dword ptr [ecx + 0x44], eax
// 0085a467  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0085a460 {
    char pad0[68];
    int m_x;
    void f(int a1);
};
void S_func_0085a460::f(int a1)
{
    m_x = (int)a1;
}
