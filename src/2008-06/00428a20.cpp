// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00428a20  unit: MainLogManager  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428a20
//
// 00428a20  55                   push ebp
// 00428a21  8bec                 mov ebp, esp
// 00428a23  6aff                 push -1
// 00428a25  680af27b00           push 0x7bf20a
// 00428a2a  64a100000000         mov eax, dword ptr fs:[0]
// 00428a30  50                   push eax
// 00428a31  64892500000000       mov dword ptr fs:[0], esp
// 00428a38  83ec24               sub esp, 0x24
// 00428a3b  53                   push ebx
// 00428a3c  56                   push esi
// 00428a3d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00428a40  57                   push edi
// 00428a41  8d4dd0               lea ecx, [ebp - 0x30]
// 00428a44  8965f0               mov dword ptr [ebp - 0x10], esp
// 00428a47  8975ec               mov dword ptr [ebp - 0x14], esi
// 00428a4a  ff1560248000         call dword ptr [0x802460]
// 00428a50  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00428a53  8b7d08               mov edi, dword ptr [ebp + 8]
// 00428a56  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00428a5d  8d4900               lea ecx, [ecx]
// 00428a60  3bfb                 cmp edi, ebx
// 00428a62  7454                 je 0x428ab8
// 00428a64  89750c               mov dword ptr [ebp + 0xc], esi
// 00428a67  897508               mov dword ptr [ebp + 8], esi
// 00428a6a  c645fc02             mov byte ptr [ebp - 4], 2
// 00428a6e  85f6                 test esi, esi
// 00428a70  740c                 je 0x428a7e
// 00428a72  8d45d0               lea eax, [ebp - 0x30]
// 00428a75  50                   push eax
// 00428a76  8bce                 mov ecx, esi
// 00428a78  ff155c248000         call dword ptr [0x80245c]
// 00428a7e  57                   push edi
// 00428a7f  8bce                 mov ecx, esi
// 00428a81  c645fc01             mov byte ptr [ebp - 4], 1
// 00428a85  ff15f0238000         call dword ptr [0x8023f0]
// 00428a8b  83c61c               add esi, 0x1c
// 00428a8e  897510               mov dword ptr [ebp + 0x10], esi
// 00428a91  83c71c               add edi, 0x1c
// 00428a94  ebca                 jmp 0x428a60
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
