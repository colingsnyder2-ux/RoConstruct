// from server: 100% by auto
// roc 2010-06 004ed190  unit: RBX::Network::Replicator::NewInstanceItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed190
//
// 004ed190  6aff                 push -1
// 004ed192  68b8d19b00           push 0x9bd1b8
// 004ed197  64a100000000         mov eax, dword ptr fs:[0]
// 004ed19d  50                   push eax
// 004ed19e  64892500000000       mov dword ptr fs:[0], esp
// 004ed1a5  83ec0c               sub esp, 0xc
// 004ed1a8  56                   push esi
// 004ed1a9  8bf1                 mov esi, ecx
// 004ed1ab  89742404             mov dword ptr [esp + 4], esi
// 004ed1af  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ed1b2  8b0e                 mov ecx, dword ptr [esi]
// 004ed1b4  8b10                 mov edx, dword ptr [eax]
// 004ed1b6  50                   push eax
// 004ed1b7  51                   push ecx
// 004ed1b8  52                   push edx
// 004ed1b9  51                   push ecx
// 004ed1ba  8d442418             lea eax, [esp + 0x18]
// 004ed1be  50                   push eax
// 004ed1bf  8bce                 mov ecx, esi
// 004ed1c1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004ed1c9  e822ddffff           call 0x4eaef0
// 004ed1ce  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004ed1d1  51                   push ecx
// 004ed1d2  e8c3a72b00           call 0x7a799a
// 004ed1d7  8b16                 mov edx, dword ptr [esi]
// 004ed1d9  52                   push edx
// 004ed1da  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004ed1e1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004ed1e8  e8ada72b00           call 0x7a799a
// 004ed1ed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ed1f1  83c408               add esp, 8
// 004ed1f4  5e                   pop esi
// 004ed1f5  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed1fc  83c418               add esp, 0x18
// 004ed1ff  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
