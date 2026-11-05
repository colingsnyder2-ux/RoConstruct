// roc 2012-06 009f9ca0  unit: CXTPControlGallery  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f9ca0
//
// 009f9ca0  8b81f8010000         mov eax, dword ptr [ecx + 0x1f8]
// 009f9ca6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f9ca0 {
    char pad0[504];
    int m_x;
    int f();
};
int S_func_009f9ca0::f()
{
    return m_x;
}
