// from server: 100% by auto
// roc 2009-06 00424390  unit: MainLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424390
//
// 00424390  55                   push ebp
// 00424391  8bec                 mov ebp, esp
// 00424393  6aff                 push -1
// 00424395  6811eb8400           push 0x84eb11
// 0042439a  64a100000000         mov eax, dword ptr fs:[0]
// 004243a0  50                   push eax
// 004243a1  64892500000000       mov dword ptr fs:[0], esp
// 004243a8  83ec0c               sub esp, 0xc
// 004243ab  53                   push ebx
// 004243ac  56                   push esi
// 004243ad  8b7508               mov esi, dword ptr [ebp + 8]
// 004243b0  57                   push edi
// 004243b1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004243b4  33db                 xor ebx, ebx
// 004243b6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004243b9  8975ec               mov dword ptr [ebp - 0x14], esi
// 004243bc  895dfc               mov dword ptr [ebp - 4], ebx
// 004243bf  90                   nop 
// 004243c0  3bfb                 cmp edi, ebx
// 004243c2  7648                 jbe 0x42440c
// 004243c4  89750c               mov dword ptr [ebp + 0xc], esi
// 004243c7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004243ca  c645fc01             mov byte ptr [ebp - 4], 1
// 004243ce  3bf3                 cmp esi, ebx
// 004243d0  740c                 je 0x4243de
// 004243d2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004243d5  50                   push eax
// 004243d6  8bce                 mov ecx, esi
// 004243d8  ff15b8e48900         call dword ptr [0x89e4b8]
// 004243de  4f                   dec edi
// 004243df  83c61c               add esi, 0x1c
// 004243e2  885dfc               mov byte ptr [ebp - 4], bl
// 004243e5  897508               mov dword ptr [ebp + 8], esi
// 004243e8  ebd6                 jmp 0x4243c0
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
