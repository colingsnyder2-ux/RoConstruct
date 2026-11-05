// roc 2012-06 007d4d10  unit: CXTCaptionButton  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007d4d10
//
// 007d4d10  8b8180000000         mov eax, dword ptr [ecx + 0x80]
// 007d4d16  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007d4d10 {
    char pad0[128];
    int m_x;
    int f();
};
int S_func_007d4d10::f()
{
    return m_x;
}
