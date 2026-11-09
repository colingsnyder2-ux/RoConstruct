// from server: 100% by auto
// roc 2009-12 0053ed80  unit: RBX::Network::Replicator::NewInstanceItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053ed80
//
// 0053ed80  6aff                 push -1
// 0053ed82  68888f9400           push 0x948f88
// 0053ed87  64a100000000         mov eax, dword ptr fs:[0]
// 0053ed8d  50                   push eax
// 0053ed8e  64892500000000       mov dword ptr fs:[0], esp
// 0053ed95  83ec0c               sub esp, 0xc
// 0053ed98  56                   push esi
// 0053ed99  8bf1                 mov esi, ecx
// 0053ed9b  89742404             mov dword ptr [esp + 4], esi
// 0053ed9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053eda2  8b0e                 mov ecx, dword ptr [esi]
// 0053eda4  8b10                 mov edx, dword ptr [eax]
// 0053eda6  50                   push eax
// 0053eda7  51                   push ecx
// 0053eda8  52                   push edx
// 0053eda9  51                   push ecx
// 0053edaa  8d442418             lea eax, [esp + 0x18]
// 0053edae  50                   push eax
// 0053edaf  8bce                 mov ecx, esi
// 0053edb1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0053edb9  e832dcffff           call 0x53c9f0
// 0053edbe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053edc1  51                   push ecx
// 0053edc2  e8934a2b00           call 0x7f385a
// 0053edc7  8b16                 mov edx, dword ptr [esi]
// 0053edc9  52                   push edx
// 0053edca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0053edd1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0053edd8  e87d4a2b00           call 0x7f385a
// 0053eddd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0053ede1  83c408               add esp, 8
// 0053ede4  5e                   pop esi
// 0053ede5  64890d00000000       mov dword ptr fs:[0], ecx
// 0053edec  83c418               add esp, 0x18
// 0053edef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
