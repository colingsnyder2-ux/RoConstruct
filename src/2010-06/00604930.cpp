// from server: 100% by auto
// roc 2010-06 00604930  unit: RBX::Workspace  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00604930
//
// 00604930  6aff                 push -1
// 00604932  68b8d19b00           push 0x9bd1b8
// 00604937  64a100000000         mov eax, dword ptr fs:[0]
// 0060493d  50                   push eax
// 0060493e  64892500000000       mov dword ptr fs:[0], esp
// 00604945  83ec0c               sub esp, 0xc
// 00604948  56                   push esi
// 00604949  8bf1                 mov esi, ecx
// 0060494b  89742404             mov dword ptr [esp + 4], esi
// 0060494f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00604952  8b0e                 mov ecx, dword ptr [esi]
// 00604954  8b10                 mov edx, dword ptr [eax]
// 00604956  50                   push eax
// 00604957  51                   push ecx
// 00604958  52                   push edx
// 00604959  51                   push ecx
// 0060495a  8d442418             lea eax, [esp + 0x18]
// 0060495e  50                   push eax
// 0060495f  8bce                 mov ecx, esi
// 00604961  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00604969  e842f9ffff           call 0x6042b0
// 0060496e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00604971  51                   push ecx
// 00604972  e823301a00           call 0x7a799a
// 00604977  8b16                 mov edx, dword ptr [esi]
// 00604979  52                   push edx
// 0060497a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00604981  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00604988  e80d301a00           call 0x7a799a
// 0060498d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00604991  83c408               add esp, 8
// 00604994  5e                   pop esi
// 00604995  64890d00000000       mov dword ptr fs:[0], ecx
// 0060499c  83c418               add esp, 0x18
// 0060499f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
