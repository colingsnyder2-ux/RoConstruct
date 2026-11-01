// from server: 100% by auto
// roc 2007-08 00428fc0  unit: MainLogManager  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428fc0
//
// 00428fc0  55                   push ebp
// 00428fc1  8bec                 mov ebp, esp
// 00428fc3  6aff                 push -1
// 00428fc5  6881cc7300           push 0x73cc81
// 00428fca  64a100000000         mov eax, dword ptr fs:[0]
// 00428fd0  50                   push eax
// 00428fd1  83ec0c               sub esp, 0xc
// 00428fd4  53                   push ebx
// 00428fd5  56                   push esi
// 00428fd6  57                   push edi
// 00428fd7  a188518b00           mov eax, dword ptr [0x8b5188]
// 00428fdc  33c5                 xor eax, ebp
// 00428fde  50                   push eax
// 00428fdf  8d45f4               lea eax, [ebp - 0xc]
// 00428fe2  64a300000000         mov dword ptr fs:[0], eax
// 00428fe8  8965f0               mov dword ptr [ebp - 0x10], esp
// 00428feb  8b7508               mov esi, dword ptr [ebp + 8]
// 00428fee  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00428ff1  33db                 xor ebx, ebx
// 00428ff3  8975ec               mov dword ptr [ebp - 0x14], esi
// 00428ff6  895dfc               mov dword ptr [ebp - 4], ebx
// 00428ff9  8da42400000000       lea esp, [esp]
// 00429000  3bfb                 cmp edi, ebx
// 00429002  764a                 jbe 0x42904e
// 00429004  89750c               mov dword ptr [ebp + 0xc], esi
// 00429007  8975e8               mov dword ptr [ebp - 0x18], esi
// 0042900a  3bf3                 cmp esi, ebx
// 0042900c  c645fc01             mov byte ptr [ebp - 4], 1
// 00429010  740c                 je 0x42901e
// 00429012  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00429015  50                   push eax
// 00429016  8bce                 mov ecx, esi
// 00429018  ff159ce67700         call dword ptr [0x77e69c]
// 0042901e  83ef01               sub edi, 1
// 00429021  83c61c               add esi, 0x1c
// 00429024  885dfc               mov byte ptr [ebp - 4], bl
// 00429027  897508               mov dword ptr [ebp + 8], esi
// 0042902a  ebd4                 jmp 0x429000
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
