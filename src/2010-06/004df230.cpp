// from server: 100% by auto
// roc 2010-06 004df230  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004df230
//
// 004df230  6aff                 push -1
// 004df232  68b8d19b00           push 0x9bd1b8
// 004df237  64a100000000         mov eax, dword ptr fs:[0]
// 004df23d  50                   push eax
// 004df23e  64892500000000       mov dword ptr fs:[0], esp
// 004df245  83ec0c               sub esp, 0xc
// 004df248  56                   push esi
// 004df249  8bf1                 mov esi, ecx
// 004df24b  89742404             mov dword ptr [esp + 4], esi
// 004df24f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004df252  8b0e                 mov ecx, dword ptr [esi]
// 004df254  8b10                 mov edx, dword ptr [eax]
// 004df256  50                   push eax
// 004df257  51                   push ecx
// 004df258  52                   push edx
// 004df259  51                   push ecx
// 004df25a  8d442418             lea eax, [esp + 0x18]
// 004df25e  50                   push eax
// 004df25f  8bce                 mov ecx, esi
// 004df261  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004df269  e882f5ffff           call 0x4de7f0
// 004df26e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004df271  51                   push ecx
// 004df272  e823872c00           call 0x7a799a
// 004df277  8b16                 mov edx, dword ptr [esi]
// 004df279  52                   push edx
// 004df27a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004df281  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004df288  e80d872c00           call 0x7a799a
// 004df28d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004df291  83c408               add esp, 8
// 004df294  5e                   pop esi
// 004df295  64890d00000000       mov dword ptr fs:[0], ecx
// 004df29c  83c418               add esp, 0x18
// 004df29f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
