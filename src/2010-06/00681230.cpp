// from server: 100% by auto
// roc 2010-06 00681230  unit: seg_00680000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00681230
//
// 00681230  6aff                 push -1
// 00681232  68b8d19b00           push 0x9bd1b8
// 00681237  64a100000000         mov eax, dword ptr fs:[0]
// 0068123d  50                   push eax
// 0068123e  64892500000000       mov dword ptr fs:[0], esp
// 00681245  83ec0c               sub esp, 0xc
// 00681248  56                   push esi
// 00681249  8bf1                 mov esi, ecx
// 0068124b  89742404             mov dword ptr [esp + 4], esi
// 0068124f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00681252  8b0e                 mov ecx, dword ptr [esi]
// 00681254  8b10                 mov edx, dword ptr [eax]
// 00681256  50                   push eax
// 00681257  51                   push ecx
// 00681258  52                   push edx
// 00681259  51                   push ecx
// 0068125a  8d442418             lea eax, [esp + 0x18]
// 0068125e  50                   push eax
// 0068125f  8bce                 mov ecx, esi
// 00681261  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00681269  e872deffff           call 0x67f0e0
// 0068126e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00681271  51                   push ecx
// 00681272  e823671200           call 0x7a799a
// 00681277  8b16                 mov edx, dword ptr [esi]
// 00681279  52                   push edx
// 0068127a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00681281  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00681288  e80d671200           call 0x7a799a
// 0068128d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00681291  83c408               add esp, 8
// 00681294  5e                   pop esi
// 00681295  64890d00000000       mov dword ptr fs:[0], ecx
// 0068129c  83c418               add esp, 0x18
// 0068129f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
