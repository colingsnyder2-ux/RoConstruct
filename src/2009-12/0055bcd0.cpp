// from server: 100% by auto
// roc 2009-12 0055bcd0  unit: RBX::Network::ServerReplicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055bcd0
//
// 0055bcd0  6aff                 push -1
// 0055bcd2  68888f9400           push 0x948f88
// 0055bcd7  64a100000000         mov eax, dword ptr fs:[0]
// 0055bcdd  50                   push eax
// 0055bcde  64892500000000       mov dword ptr fs:[0], esp
// 0055bce5  83ec0c               sub esp, 0xc
// 0055bce8  56                   push esi
// 0055bce9  8bf1                 mov esi, ecx
// 0055bceb  89742404             mov dword ptr [esp + 4], esi
// 0055bcef  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055bcf2  8b0e                 mov ecx, dword ptr [esi]
// 0055bcf4  8b10                 mov edx, dword ptr [eax]
// 0055bcf6  50                   push eax
// 0055bcf7  51                   push ecx
// 0055bcf8  52                   push edx
// 0055bcf9  51                   push ecx
// 0055bcfa  8d442418             lea eax, [esp + 0x18]
// 0055bcfe  50                   push eax
// 0055bcff  8bce                 mov ecx, esi
// 0055bd01  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0055bd09  e882f9ffff           call 0x55b690
// 0055bd0e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0055bd11  51                   push ecx
// 0055bd12  e8437b2900           call 0x7f385a
// 0055bd17  8b16                 mov edx, dword ptr [esi]
// 0055bd19  52                   push edx
// 0055bd1a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0055bd21  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0055bd28  e82d7b2900           call 0x7f385a
// 0055bd2d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055bd31  83c408               add esp, 8
// 0055bd34  5e                   pop esi
// 0055bd35  64890d00000000       mov dword ptr fs:[0], ecx
// 0055bd3c  83c418               add esp, 0x18
// 0055bd3f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
