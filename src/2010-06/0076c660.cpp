// from server: 100% by auto
// roc 2010-06 0076c660  unit: RBX::Network::$$A6AXABVChatMessage::?$signal::slot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076c660
//
// 0076c660  6aff                 push -1
// 0076c662  68b8d19b00           push 0x9bd1b8
// 0076c667  64a100000000         mov eax, dword ptr fs:[0]
// 0076c66d  50                   push eax
// 0076c66e  64892500000000       mov dword ptr fs:[0], esp
// 0076c675  83ec0c               sub esp, 0xc
// 0076c678  56                   push esi
// 0076c679  8bf1                 mov esi, ecx
// 0076c67b  89742404             mov dword ptr [esp + 4], esi
// 0076c67f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076c682  8b0e                 mov ecx, dword ptr [esi]
// 0076c684  8b10                 mov edx, dword ptr [eax]
// 0076c686  50                   push eax
// 0076c687  51                   push ecx
// 0076c688  52                   push edx
// 0076c689  51                   push ecx
// 0076c68a  8d442418             lea eax, [esp + 0x18]
// 0076c68e  50                   push eax
// 0076c68f  8bce                 mov ecx, esi
// 0076c691  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0076c699  e882fbffff           call 0x76c220
// 0076c69e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0076c6a1  51                   push ecx
// 0076c6a2  e8f3b20300           call 0x7a799a
// 0076c6a7  8b16                 mov edx, dword ptr [esi]
// 0076c6a9  52                   push edx
// 0076c6aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0076c6b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0076c6b8  e8ddb20300           call 0x7a799a
// 0076c6bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0076c6c1  83c408               add esp, 8
// 0076c6c4  5e                   pop esi
// 0076c6c5  64890d00000000       mov dword ptr fs:[0], ecx
// 0076c6cc  83c418               add esp, 0x18
// 0076c6cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
