// roc 2009-12 008c6980  unit: CXTPPropertyGridInplaceButtons  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6980
//
// 008c6980  56                   push esi
// 008c6981  8bf1                 mov esi, ecx
// 008c6983  8d8e84000000         lea ecx, [esi + 0x84]
// 008c6989  ff15c0de9800         call dword ptr [0x98dec0]
// 008c698f  8d8e80000000         lea ecx, [esi + 0x80]
// 008c6995  ff15c0de9800         call dword ptr [0x98dec0]
// 008c699b  8d4e7c               lea ecx, [esi + 0x7c]
// 008c699e  ff15c0de9800         call dword ptr [0x98dec0]
// 008c69a4  8d4e78               lea ecx, [esi + 0x78]
// 008c69a7  ff15c0de9800         call dword ptr [0x98dec0]
// 008c69ad  8d4e74               lea ecx, [esi + 0x74]
// 008c69b0  ff15c0de9800         call dword ptr [0x98dec0]
// 008c69b6  8d4e70               lea ecx, [esi + 0x70]
// 008c69b9  ff15c0de9800         call dword ptr [0x98dec0]
// 008c69bf  8bce                 mov ecx, esi
// 008c69c1  5e                   pop esi
// 008c69c2  e98dfa0500           jmp 0x926454
// copied from an identical function in another client (function ?func@CXTPPropertyGridInplaceButtons@ns_ROCX000036@ns_ROCX0000c1@@QAEXXZ)

namespace ns_ROCX000036 {
struct S_func_007b7f90 {
    char pad0[652];
    int m_x;
    int f();
};
int S_func_007b7f90::f()
{
    return m_x;
}
}
