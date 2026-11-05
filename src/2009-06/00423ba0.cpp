// from server: 100% by auto
// roc 2009-06 00423ba0  unit: MainLogManager  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00423ba0
//
// 00423ba0  55                   push ebp
// 00423ba1  8bec                 mov ebp, esp
// 00423ba3  6aff                 push -1
// 00423ba5  688aea8400           push 0x84ea8a
// 00423baa  64a100000000         mov eax, dword ptr fs:[0]
// 00423bb0  50                   push eax
// 00423bb1  64892500000000       mov dword ptr fs:[0], esp
// 00423bb8  83ec24               sub esp, 0x24
// 00423bbb  53                   push ebx
// 00423bbc  56                   push esi
// 00423bbd  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00423bc0  57                   push edi
// 00423bc1  8d4dd0               lea ecx, [ebp - 0x30]
// 00423bc4  8965f0               mov dword ptr [ebp - 0x10], esp
// 00423bc7  8975ec               mov dword ptr [ebp - 0x14], esi
// 00423bca  ff15c0e48900         call dword ptr [0x89e4c0]
// 00423bd0  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00423bd3  8b7d08               mov edi, dword ptr [ebp + 8]
// 00423bd6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00423bdd  8d4900               lea ecx, [ecx]
// 00423be0  3bfb                 cmp edi, ebx
// 00423be2  7454                 je 0x423c38
// 00423be4  89750c               mov dword ptr [ebp + 0xc], esi
// 00423be7  897508               mov dword ptr [ebp + 8], esi
// 00423bea  c645fc02             mov byte ptr [ebp - 4], 2
// 00423bee  85f6                 test esi, esi
// 00423bf0  740c                 je 0x423bfe
// 00423bf2  8d45d0               lea eax, [ebp - 0x30]
// 00423bf5  50                   push eax
// 00423bf6  8bce                 mov ecx, esi
// 00423bf8  ff15b8e48900         call dword ptr [0x89e4b8]
// 00423bfe  57                   push edi
// 00423bff  8bce                 mov ecx, esi
// 00423c01  c645fc01             mov byte ptr [ebp - 4], 1
// 00423c05  ff154ce48900         call dword ptr [0x89e44c]
// 00423c0b  83c61c               add esi, 0x1c
// 00423c0e  897510               mov dword ptr [ebp + 0x10], esi
// 00423c11  83c71c               add edi, 0x1c
// 00423c14  ebca                 jmp 0x423be0
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
