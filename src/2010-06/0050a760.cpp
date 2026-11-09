// from server: 100% by auto
// roc 2010-06 0050a760  unit: RBX::Network::ServerReplicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0050a760
//
// 0050a760  6aff                 push -1
// 0050a762  68b8d19b00           push 0x9bd1b8
// 0050a767  64a100000000         mov eax, dword ptr fs:[0]
// 0050a76d  50                   push eax
// 0050a76e  64892500000000       mov dword ptr fs:[0], esp
// 0050a775  83ec0c               sub esp, 0xc
// 0050a778  56                   push esi
// 0050a779  8bf1                 mov esi, ecx
// 0050a77b  89742404             mov dword ptr [esp + 4], esi
// 0050a77f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0050a782  8b0e                 mov ecx, dword ptr [esi]
// 0050a784  8b10                 mov edx, dword ptr [eax]
// 0050a786  50                   push eax
// 0050a787  51                   push ecx
// 0050a788  52                   push edx
// 0050a789  51                   push ecx
// 0050a78a  8d442418             lea eax, [esp + 0x18]
// 0050a78e  50                   push eax
// 0050a78f  8bce                 mov ecx, esi
// 0050a791  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0050a799  e842f9ffff           call 0x50a0e0
// 0050a79e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0050a7a1  51                   push ecx
// 0050a7a2  e8f3d12900           call 0x7a799a
// 0050a7a7  8b16                 mov edx, dword ptr [esi]
// 0050a7a9  52                   push edx
// 0050a7aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0050a7b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0050a7b8  e8ddd12900           call 0x7a799a
// 0050a7bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050a7c1  83c408               add esp, 8
// 0050a7c4  5e                   pop esi
// 0050a7c5  64890d00000000       mov dword ptr fs:[0], ecx
// 0050a7cc  83c418               add esp, 0x18
// 0050a7cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
