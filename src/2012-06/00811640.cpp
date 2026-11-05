// roc 2012-06 00811640  unit: RBX::JointInstance  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00811640
//
// 00811640  8b81a8000000         mov eax, dword ptr [ecx + 0xa8]
// 00811646  83c064               add eax, 0x64
// 00811649  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00811640 {
    char pad0[168];
    int m_x;
    int f();
};
int S_func_00811640::f()
{
    return m_x + 0x64;
}
