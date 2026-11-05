// from server: 100% by auto
// roc 2012-06 004323d0  unit: ThreadLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004323d0
//
// 004323d0  55                   push ebp
// 004323d1  8bec                 mov ebp, esp
// 004323d3  6aff                 push -1
// 004323d5  6871cba900           push 0xa9cb71
// 004323da  64a100000000         mov eax, dword ptr fs:[0]
// 004323e0  50                   push eax
// 004323e1  64892500000000       mov dword ptr fs:[0], esp
// 004323e8  83ec0c               sub esp, 0xc
// 004323eb  53                   push ebx
// 004323ec  56                   push esi
// 004323ed  8b7508               mov esi, dword ptr [ebp + 8]
// 004323f0  57                   push edi
// 004323f1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004323f4  33db                 xor ebx, ebx
// 004323f6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004323f9  8975ec               mov dword ptr [ebp - 0x14], esi
// 004323fc  895dfc               mov dword ptr [ebp - 4], ebx
// 004323ff  90                   nop 
// 00432400  3bfb                 cmp edi, ebx
// 00432402  7648                 jbe 0x43244c
// 00432404  89750c               mov dword ptr [ebp + 0xc], esi
// 00432407  8975e8               mov dword ptr [ebp - 0x18], esi
// 0043240a  c645fc01             mov byte ptr [ebp - 4], 1
// 0043240e  3bf3                 cmp esi, ebx
// 00432410  740c                 je 0x43241e
// 00432412  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00432415  50                   push eax
// 00432416  8bce                 mov ecx, esi
// 00432418  ff154426b200         call dword ptr [0xb22644]
// 0043241e  4f                   dec edi
// 0043241f  83c61c               add esi, 0x1c
// 00432422  885dfc               mov byte ptr [ebp - 4], bl
// 00432425  897508               mov dword ptr [ebp + 8], esi
// 00432428  ebd6                 jmp 0x432400
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
