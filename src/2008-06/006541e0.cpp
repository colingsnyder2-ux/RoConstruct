// from server: 100% by auto
// roc 2008-06 006541e0  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006541e0
//
// 006541e0  6aff                 push -1
// 006541e2  6828d97b00           push 0x7bd928
// 006541e7  64a100000000         mov eax, dword ptr fs:[0]
// 006541ed  50                   push eax
// 006541ee  64892500000000       mov dword ptr fs:[0], esp
// 006541f5  83ec0c               sub esp, 0xc
// 006541f8  56                   push esi
// 006541f9  8bf1                 mov esi, ecx
// 006541fb  89742404             mov dword ptr [esp + 4], esi
// 006541ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 00654202  8b0e                 mov ecx, dword ptr [esi]
// 00654204  8b10                 mov edx, dword ptr [eax]
// 00654206  50                   push eax
// 00654207  51                   push ecx
// 00654208  52                   push edx
// 00654209  51                   push ecx
// 0065420a  8d442418             lea eax, [esp + 0x18]
// 0065420e  50                   push eax
// 0065420f  8bce                 mov ecx, esi
// 00654211  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00654219  e852efffff           call 0x653170
// 0065421e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00654221  51                   push ecx
// 00654222  e853c40400           call 0x6a067a
// 00654227  8b16                 mov edx, dword ptr [esi]
// 00654229  52                   push edx
// 0065422a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00654231  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00654238  e83dc40400           call 0x6a067a
// 0065423d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00654241  83c408               add esp, 8
// 00654244  5e                   pop esi
// 00654245  64890d00000000       mov dword ptr fs:[0], ecx
// 0065424c  83c418               add esp, 0x18
// 0065424f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
