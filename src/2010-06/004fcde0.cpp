// from server: 100% by auto
// roc 2010-06 004fcde0  unit: RBX::Network::Replicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004fcde0
//
// 004fcde0  6aff                 push -1
// 004fcde2  68b8d19b00           push 0x9bd1b8
// 004fcde7  64a100000000         mov eax, dword ptr fs:[0]
// 004fcded  50                   push eax
// 004fcdee  64892500000000       mov dword ptr fs:[0], esp
// 004fcdf5  83ec0c               sub esp, 0xc
// 004fcdf8  56                   push esi
// 004fcdf9  8bf1                 mov esi, ecx
// 004fcdfb  89742404             mov dword ptr [esp + 4], esi
// 004fcdff  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fce02  8b0e                 mov ecx, dword ptr [esi]
// 004fce04  8b10                 mov edx, dword ptr [eax]
// 004fce06  50                   push eax
// 004fce07  51                   push ecx
// 004fce08  52                   push edx
// 004fce09  51                   push ecx
// 004fce0a  8d442418             lea eax, [esp + 0x18]
// 004fce0e  50                   push eax
// 004fce0f  8bce                 mov ecx, esi
// 004fce11  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004fce19  e842f6ffff           call 0x4fc460
// 004fce1e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004fce21  51                   push ecx
// 004fce22  e873ab2a00           call 0x7a799a
// 004fce27  8b16                 mov edx, dword ptr [esi]
// 004fce29  52                   push edx
// 004fce2a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004fce31  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004fce38  e85dab2a00           call 0x7a799a
// 004fce3d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004fce41  83c408               add esp, 8
// 004fce44  5e                   pop esi
// 004fce45  64890d00000000       mov dword ptr fs:[0], ecx
// 004fce4c  83c418               add esp, 0x18
// 004fce4f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
