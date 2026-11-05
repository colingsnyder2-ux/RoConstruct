// from server: 100% by auto
// roc 2009-12 00424550  unit: ThreadLogManager  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00424550
//
// 00424550  55                   push ebp
// 00424551  8bec                 mov ebp, esp
// 00424553  6aff                 push -1
// 00424555  687a909200           push 0x92907a
// 0042455a  64a100000000         mov eax, dword ptr fs:[0]
// 00424560  50                   push eax
// 00424561  64892500000000       mov dword ptr fs:[0], esp
// 00424568  83ec24               sub esp, 0x24
// 0042456b  53                   push ebx
// 0042456c  56                   push esi
// 0042456d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00424570  57                   push edi
// 00424571  8d4dd0               lea ecx, [ebp - 0x30]
// 00424574  8965f0               mov dword ptr [ebp - 0x10], esp
// 00424577  8975ec               mov dword ptr [ebp - 0x14], esi
// 0042457a  ff15e8b69800         call dword ptr [0x98b6e8]
// 00424580  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00424583  8b7d08               mov edi, dword ptr [ebp + 8]
// 00424586  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0042458d  8d4900               lea ecx, [ecx]
// 00424590  3bfb                 cmp edi, ebx
// 00424592  7454                 je 0x4245e8
// 00424594  89750c               mov dword ptr [ebp + 0xc], esi
// 00424597  897508               mov dword ptr [ebp + 8], esi
// 0042459a  c645fc02             mov byte ptr [ebp - 4], 2
// 0042459e  85f6                 test esi, esi
// 004245a0  740c                 je 0x4245ae
// 004245a2  8d45d0               lea eax, [ebp - 0x30]
// 004245a5  50                   push eax
// 004245a6  8bce                 mov ecx, esi
// 004245a8  ff15f0b69800         call dword ptr [0x98b6f0]
// 004245ae  57                   push edi
// 004245af  8bce                 mov ecx, esi
// 004245b1  c645fc01             mov byte ptr [ebp - 4], 1
// 004245b5  ff1584b69800         call dword ptr [0x98b684]
// 004245bb  83c61c               add esi, 0x1c
// 004245be  897510               mov dword ptr [ebp + 0x10], esi
// 004245c1  83c71c               add edi, 0x1c
// 004245c4  ebca                 jmp 0x424590
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
