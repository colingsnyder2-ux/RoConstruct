// from server: 100% by auto
// roc 2009-12 00522c10  unit: RBX::Network::Players  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00522c10
//
// 00522c10  56                   push esi
// 00522c11  8bf1                 mov esi, ecx
// 00522c13  8b460c               mov eax, dword ptr [esi + 0xc]
// 00522c16  85c0                 test eax, eax
// 00522c18  7409                 je 0x522c23
// 00522c1a  50                   push eax
// 00522c1b  e83a0c2d00           call 0x7f385a
// 00522c20  83c404               add esp, 4
// 00522c23  8b06                 mov eax, dword ptr [esi]
// 00522c25  50                   push eax
// 00522c26  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00522c2d  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00522c34  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00522c3b  e81a0c2d00           call 0x7f385a
// 00522c40  83c404               add esp, 4
// 00522c43  5e                   pop esi
// 00522c44  c3                   ret 
// standard library vector<ptr> (function ??1?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
