// from server: 100% by auto
// roc 2010-06 00542c10  unit: RBX::AggregatingSceneManager  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00542c10
//
// 00542c10  6aff                 push -1
// 00542c12  68b8d19b00           push 0x9bd1b8
// 00542c17  64a100000000         mov eax, dword ptr fs:[0]
// 00542c1d  50                   push eax
// 00542c1e  64892500000000       mov dword ptr fs:[0], esp
// 00542c25  83ec0c               sub esp, 0xc
// 00542c28  56                   push esi
// 00542c29  8bf1                 mov esi, ecx
// 00542c2b  89742404             mov dword ptr [esp + 4], esi
// 00542c2f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00542c32  8b0e                 mov ecx, dword ptr [esi]
// 00542c34  8b10                 mov edx, dword ptr [eax]
// 00542c36  50                   push eax
// 00542c37  51                   push ecx
// 00542c38  52                   push edx
// 00542c39  51                   push ecx
// 00542c3a  8d442418             lea eax, [esp + 0x18]
// 00542c3e  50                   push eax
// 00542c3f  8bce                 mov ecx, esi
// 00542c41  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00542c49  e8c2f8ffff           call 0x542510
// 00542c4e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00542c51  51                   push ecx
// 00542c52  e8434d2600           call 0x7a799a
// 00542c57  8b16                 mov edx, dword ptr [esi]
// 00542c59  52                   push edx
// 00542c5a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00542c61  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00542c68  e82d4d2600           call 0x7a799a
// 00542c6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00542c71  83c408               add esp, 8
// 00542c74  5e                   pop esi
// 00542c75  64890d00000000       mov dword ptr fs:[0], ecx
// 00542c7c  83c418               add esp, 0x18
// 00542c7f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
