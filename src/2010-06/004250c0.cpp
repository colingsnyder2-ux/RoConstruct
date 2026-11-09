// from server: 100% by auto
// roc 2010-06 004250c0  unit: ThreadLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004250c0
//
// 004250c0  55                   push ebp
// 004250c1  8bec                 mov ebp, esp
// 004250c3  6aff                 push -1
// 004250c5  6861fa9700           push 0x97fa61
// 004250ca  64a100000000         mov eax, dword ptr fs:[0]
// 004250d0  50                   push eax
// 004250d1  64892500000000       mov dword ptr fs:[0], esp
// 004250d8  83ec0c               sub esp, 0xc
// 004250db  53                   push ebx
// 004250dc  56                   push esi
// 004250dd  8b7508               mov esi, dword ptr [ebp + 8]
// 004250e0  57                   push edi
// 004250e1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004250e4  33db                 xor ebx, ebx
// 004250e6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004250e9  8975ec               mov dword ptr [ebp - 0x14], esi
// 004250ec  895dfc               mov dword ptr [ebp - 4], ebx
// 004250ef  90                   nop 
// 004250f0  3bfb                 cmp edi, ebx
// 004250f2  7648                 jbe 0x42513c
// 004250f4  89750c               mov dword ptr [ebp + 0xc], esi
// 004250f7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004250fa  c645fc01             mov byte ptr [ebp - 4], 1
// 004250fe  3bf3                 cmp esi, ebx
// 00425100  740c                 je 0x42510e
// 00425102  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00425105  50                   push eax
// 00425106  8bce                 mov ecx, esi
// 00425108  ff150ca49e00         call dword ptr [0x9ea40c]
// 0042510e  4f                   dec edi
// 0042510f  83c61c               add esi, 0x1c
// 00425112  885dfc               mov byte ptr [ebp - 4], bl
// 00425115  897508               mov dword ptr [ebp + 8], esi
// 00425118  ebd6                 jmp 0x4250f0
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
