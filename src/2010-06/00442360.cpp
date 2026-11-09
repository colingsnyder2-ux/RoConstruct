// from server: 100% by auto
// roc 2010-06 00442360  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00442360
//
// 00442360  6aff                 push -1
// 00442362  68b8d19b00           push 0x9bd1b8
// 00442367  64a100000000         mov eax, dword ptr fs:[0]
// 0044236d  50                   push eax
// 0044236e  64892500000000       mov dword ptr fs:[0], esp
// 00442375  83ec0c               sub esp, 0xc
// 00442378  56                   push esi
// 00442379  8bf1                 mov esi, ecx
// 0044237b  89742404             mov dword ptr [esp + 4], esi
// 0044237f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00442382  8b0e                 mov ecx, dword ptr [esi]
// 00442384  8b10                 mov edx, dword ptr [eax]
// 00442386  50                   push eax
// 00442387  51                   push ecx
// 00442388  52                   push edx
// 00442389  51                   push ecx
// 0044238a  8d442418             lea eax, [esp + 0x18]
// 0044238e  50                   push eax
// 0044238f  8bce                 mov ecx, esi
// 00442391  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00442399  e842feffff           call 0x4421e0
// 0044239e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004423a1  51                   push ecx
// 004423a2  e8f3553600           call 0x7a799a
// 004423a7  8b16                 mov edx, dword ptr [esi]
// 004423a9  52                   push edx
// 004423aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004423b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004423b8  e8dd553600           call 0x7a799a
// 004423bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004423c1  83c408               add esp, 8
// 004423c4  5e                   pop esi
// 004423c5  64890d00000000       mov dword ptr fs:[0], ecx
// 004423cc  83c418               add esp, 0x18
// 004423cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
