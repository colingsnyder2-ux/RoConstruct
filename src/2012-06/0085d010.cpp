// roc 2012-06 0085d010  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085d010
//
// 0085d010  8d4140               lea eax, [ecx + 0x40]
// 0085d013  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0085d010 {
    char pad0[64];
    int m_x;
    int* f();
};
int* S_func_0085d010::f()
{
    return &m_x;
}
