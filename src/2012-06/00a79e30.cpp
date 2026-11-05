// roc 2012-06 00a79e30  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79e30
//
// 00a79e30  8b442404             mov eax, dword ptr [esp + 4]
// 00a79e34  8981a0000000         mov dword ptr [ecx + 0xa0], eax
// 00a79e3a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a79e30 {
    char pad0[160];
    int m_x;
    void f(int a1);
};
void S_func_00a79e30::f(int a1)
{
    m_x = (int)a1;
}
