// from server: 100% by auto
// roc 2010-06 004c72b0  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c72b0
//
// 004c72b0  6aff                 push -1
// 004c72b2  68b8d19b00           push 0x9bd1b8
// 004c72b7  64a100000000         mov eax, dword ptr fs:[0]
// 004c72bd  50                   push eax
// 004c72be  64892500000000       mov dword ptr fs:[0], esp
// 004c72c5  83ec0c               sub esp, 0xc
// 004c72c8  56                   push esi
// 004c72c9  8bf1                 mov esi, ecx
// 004c72cb  89742404             mov dword ptr [esp + 4], esi
// 004c72cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c72d2  8b0e                 mov ecx, dword ptr [esi]
// 004c72d4  8b10                 mov edx, dword ptr [eax]
// 004c72d6  50                   push eax
// 004c72d7  51                   push ecx
// 004c72d8  52                   push edx
// 004c72d9  51                   push ecx
// 004c72da  8d442418             lea eax, [esp + 0x18]
// 004c72de  50                   push eax
// 004c72df  8bce                 mov ecx, esi
// 004c72e1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004c72e9  e802e9ffff           call 0x4c5bf0
// 004c72ee  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004c72f1  51                   push ecx
// 004c72f2  e8a3062e00           call 0x7a799a
// 004c72f7  8b16                 mov edx, dword ptr [esi]
// 004c72f9  52                   push edx
// 004c72fa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c7301  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004c7308  e88d062e00           call 0x7a799a
// 004c730d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c7311  83c408               add esp, 8
// 004c7314  5e                   pop esi
// 004c7315  64890d00000000       mov dword ptr fs:[0], ecx
// 004c731c  83c418               add esp, 0x18
// 004c731f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
