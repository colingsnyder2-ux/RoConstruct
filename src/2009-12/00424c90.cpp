// from server: 100% by auto
// roc 2009-12 00424c90  unit: ThreadLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00424c90
//
// 00424c90  55                   push ebp
// 00424c91  8bec                 mov ebp, esp
// 00424c93  6aff                 push -1
// 00424c95  68e1909200           push 0x9290e1
// 00424c9a  64a100000000         mov eax, dword ptr fs:[0]
// 00424ca0  50                   push eax
// 00424ca1  64892500000000       mov dword ptr fs:[0], esp
// 00424ca8  83ec0c               sub esp, 0xc
// 00424cab  53                   push ebx
// 00424cac  56                   push esi
// 00424cad  8b7508               mov esi, dword ptr [ebp + 8]
// 00424cb0  57                   push edi
// 00424cb1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00424cb4  33db                 xor ebx, ebx
// 00424cb6  8965f0               mov dword ptr [ebp - 0x10], esp
// 00424cb9  8975ec               mov dword ptr [ebp - 0x14], esi
// 00424cbc  895dfc               mov dword ptr [ebp - 4], ebx
// 00424cbf  90                   nop 
// 00424cc0  3bfb                 cmp edi, ebx
// 00424cc2  7648                 jbe 0x424d0c
// 00424cc4  89750c               mov dword ptr [ebp + 0xc], esi
// 00424cc7  8975e8               mov dword ptr [ebp - 0x18], esi
// 00424cca  c645fc01             mov byte ptr [ebp - 4], 1
// 00424cce  3bf3                 cmp esi, ebx
// 00424cd0  740c                 je 0x424cde
// 00424cd2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00424cd5  50                   push eax
// 00424cd6  8bce                 mov ecx, esi
// 00424cd8  ff15f0b69800         call dword ptr [0x98b6f0]
// 00424cde  4f                   dec edi
// 00424cdf  83c61c               add esi, 0x1c
// 00424ce2  885dfc               mov byte ptr [ebp - 4], bl
// 00424ce5  897508               mov dword ptr [ebp + 8], esi
// 00424ce8  ebd6                 jmp 0x424cc0
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
