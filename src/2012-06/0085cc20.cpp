// roc 2012-06 0085cc20  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085cc20
//
// 0085cc20  8b442404             mov eax, dword ptr [esp + 4]
// 0085cc24  89818c000000         mov dword ptr [ecx + 0x8c], eax
// 0085cc2a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_0085cc20 {
    char pad0[140];
    int m_x;
    void f(int a1);
};
void S_func_0085cc20::f(int a1)
{
    m_x = (int)a1;
}
