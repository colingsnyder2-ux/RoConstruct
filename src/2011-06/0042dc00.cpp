// from server: 100% by auto
// roc 2011-06 0042dc00  unit: ThreadLogManager  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0042dc00
//
// 0042dc00  55                   push ebp
// 0042dc01  8bec                 mov ebp, esp
// 0042dc03  6aff                 push -1
// 0042dc05  68eafb9c00           push 0x9cfbea
// 0042dc0a  64a100000000         mov eax, dword ptr fs:[0]
// 0042dc10  50                   push eax
// 0042dc11  64892500000000       mov dword ptr fs:[0], esp
// 0042dc18  83ec24               sub esp, 0x24
// 0042dc1b  53                   push ebx
// 0042dc1c  56                   push esi
// 0042dc1d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0042dc20  57                   push edi
// 0042dc21  8d4dd0               lea ecx, [ebp - 0x30]
// 0042dc24  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042dc27  8975ec               mov dword ptr [ebp - 0x14], esi
// 0042dc2a  ff15bc04a400         call dword ptr [0xa404bc]
// 0042dc30  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 0042dc33  8b7d08               mov edi, dword ptr [ebp + 8]
// 0042dc36  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0042dc3d  8d4900               lea ecx, [ecx]
// 0042dc40  3bfb                 cmp edi, ebx
// 0042dc42  7454                 je 0x42dc98
// 0042dc44  89750c               mov dword ptr [ebp + 0xc], esi
// 0042dc47  897508               mov dword ptr [ebp + 8], esi
// 0042dc4a  c645fc02             mov byte ptr [ebp - 4], 2
// 0042dc4e  85f6                 test esi, esi
// 0042dc50  740c                 je 0x42dc5e
// 0042dc52  8d45d0               lea eax, [ebp - 0x30]
// 0042dc55  50                   push eax
// 0042dc56  8bce                 mov ecx, esi
// 0042dc58  ff15c804a400         call dword ptr [0xa404c8]
// 0042dc5e  57                   push edi
// 0042dc5f  8bce                 mov ecx, esi
// 0042dc61  c645fc01             mov byte ptr [ebp - 4], 1
// 0042dc65  ff15d803a400         call dword ptr [0xa403d8]
// 0042dc6b  83c61c               add esi, 0x1c
// 0042dc6e  897510               mov dword ptr [ebp + 0x10], esi
// 0042dc71  83c71c               add edi, 0x1c
// 0042dc74  ebca                 jmp 0x42dc40
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
