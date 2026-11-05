// from server: 100% by auto
// roc 2010-06 00424800  unit: ThreadLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00424800
//
// 00424800  55                   push ebp
// 00424801  8bec                 mov ebp, esp
// 00424803  6aff                 push -1
// 00424805  68b1f99700           push 0x97f9b1
// 0042480a  64a100000000         mov eax, dword ptr fs:[0]
// 00424810  50                   push eax
// 00424811  64892500000000       mov dword ptr fs:[0], esp
// 00424818  83ec0c               sub esp, 0xc
// 0042481b  53                   push ebx
// 0042481c  56                   push esi
// 0042481d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00424820  57                   push edi
// 00424821  8b7d08               mov edi, dword ptr [ebp + 8]
// 00424824  33db                 xor ebx, ebx
// 00424826  8965f0               mov dword ptr [ebp - 0x10], esp
// 00424829  8975ec               mov dword ptr [ebp - 0x14], esi
// 0042482c  895dfc               mov dword ptr [ebp - 4], ebx
// 0042482f  90                   nop 
// 00424830  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 00424833  7447                 je 0x42487c
// 00424835  897508               mov dword ptr [ebp + 8], esi
// 00424838  8975e8               mov dword ptr [ebp - 0x18], esi
// 0042483b  c645fc01             mov byte ptr [ebp - 4], 1
// 0042483f  3bf3                 cmp esi, ebx
// 00424841  7409                 je 0x42484c
// 00424843  57                   push edi
// 00424844  8bce                 mov ecx, esi
// 00424846  ff150ca49e00         call dword ptr [0x9ea40c]
// 0042484c  83c61c               add esi, 0x1c
// 0042484f  885dfc               mov byte ptr [ebp - 4], bl
// 00424852  897510               mov dword ptr [ebp + 0x10], esi
// 00424855  83c71c               add edi, 0x1c
// 00424858  ebd6                 jmp 0x424830
// standard library vector<string> (function ??$_Uninit_copy@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PBV10@0PAV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
