// from server: 100% by auto
// roc 2011-06 0042dad0  unit: ThreadLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0042dad0
//
// 0042dad0  55                   push ebp
// 0042dad1  8bec                 mov ebp, esp
// 0042dad3  6aff                 push -1
// 0042dad5  68a1fb9c00           push 0x9cfba1
// 0042dada  64a100000000         mov eax, dword ptr fs:[0]
// 0042dae0  50                   push eax
// 0042dae1  64892500000000       mov dword ptr fs:[0], esp
// 0042dae8  83ec0c               sub esp, 0xc
// 0042daeb  53                   push ebx
// 0042daec  56                   push esi
// 0042daed  8b7508               mov esi, dword ptr [ebp + 8]
// 0042daf0  57                   push edi
// 0042daf1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 0042daf4  33db                 xor ebx, ebx
// 0042daf6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042daf9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0042dafc  895dfc               mov dword ptr [ebp - 4], ebx
// 0042daff  90                   nop 
// 0042db00  3bfb                 cmp edi, ebx
// 0042db02  7648                 jbe 0x42db4c
// 0042db04  89750c               mov dword ptr [ebp + 0xc], esi
// 0042db07  8975e8               mov dword ptr [ebp - 0x18], esi
// 0042db0a  c645fc01             mov byte ptr [ebp - 4], 1
// 0042db0e  3bf3                 cmp esi, ebx
// 0042db10  740c                 je 0x42db1e
// 0042db12  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0042db15  50                   push eax
// 0042db16  8bce                 mov ecx, esi
// 0042db18  ff15c804a400         call dword ptr [0xa404c8]
// 0042db1e  4f                   dec edi
// 0042db1f  83c61c               add esi, 0x1c
// 0042db22  885dfc               mov byte ptr [ebp - 4], bl
// 0042db25  897508               mov dword ptr [ebp + 8], esi
// 0042db28  ebd6                 jmp 0x42db00
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
