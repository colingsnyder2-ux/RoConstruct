// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0048b720  unit: boost::any::placeholder  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048b720
//
// 0048b720  55                   push ebp
// 0048b721  8bec                 mov ebp, esp
// 0048b723  6aff                 push -1
// 0048b725  68b1617c00           push 0x7c61b1
// 0048b72a  64a100000000         mov eax, dword ptr fs:[0]
// 0048b730  50                   push eax
// 0048b731  64892500000000       mov dword ptr fs:[0], esp
// 0048b738  83ec0c               sub esp, 0xc
// 0048b73b  53                   push ebx
// 0048b73c  56                   push esi
// 0048b73d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0048b740  57                   push edi
// 0048b741  8b7d08               mov edi, dword ptr [ebp + 8]
// 0048b744  33db                 xor ebx, ebx
// 0048b746  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048b749  8975ec               mov dword ptr [ebp - 0x14], esi
// 0048b74c  895dfc               mov dword ptr [ebp - 4], ebx
// 0048b74f  90                   nop 
// 0048b750  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 0048b753  7447                 je 0x48b79c
// 0048b755  897508               mov dword ptr [ebp + 8], esi
// 0048b758  8975e8               mov dword ptr [ebp - 0x18], esi
// 0048b75b  c645fc01             mov byte ptr [ebp - 4], 1
// 0048b75f  3bf3                 cmp esi, ebx
// 0048b761  7409                 je 0x48b76c
// 0048b763  57                   push edi
// 0048b764  8bce                 mov ecx, esi
// 0048b766  ff155c248000         call dword ptr [0x80245c]
// 0048b76c  83c61c               add esi, 0x1c
// 0048b76f  885dfc               mov byte ptr [ebp - 4], bl
// 0048b772  897510               mov dword ptr [ebp + 0x10], esi
// 0048b775  83c71c               add edi, 0x1c
// 0048b778  ebd6                 jmp 0x48b750
// standard library vector<string> (function ??$_Uninit_copy@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PBV10@0PAV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
