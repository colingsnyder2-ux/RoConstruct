// from server: 100% by auto
// from server: 73% by coldek
// roc 2008-06 00428fb0  unit: MainLogManager  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428fb0
//
// 00428fb0  55                   push ebp
// 00428fb1  8bec                 mov ebp, esp
// 00428fb3  6aff                 push -1
// 00428fb5  6881f27b00           push 0x7bf281
// 00428fba  64a100000000         mov eax, dword ptr fs:[0]
// 00428fc0  50                   push eax
// 00428fc1  64892500000000       mov dword ptr fs:[0], esp
// 00428fc8  83ec0c               sub esp, 0xc
// 00428fcb  53                   push ebx
// 00428fcc  56                   push esi
// 00428fcd  8b7508               mov esi, dword ptr [ebp + 8]
// 00428fd0  57                   push edi
// 00428fd1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00428fd4  33db                 xor ebx, ebx
// 00428fd6  8965f0               mov dword ptr [ebp - 0x10], esp
// 00428fd9  8975ec               mov dword ptr [ebp - 0x14], esi
// 00428fdc  895dfc               mov dword ptr [ebp - 4], ebx
// 00428fdf  90                   nop 
// 00428fe0  3bfb                 cmp edi, ebx
// 00428fe2  7648                 jbe 0x42902c
// 00428fe4  89750c               mov dword ptr [ebp + 0xc], esi
// 00428fe7  8975e8               mov dword ptr [ebp - 0x18], esi
// 00428fea  c645fc01             mov byte ptr [ebp - 4], 1
// 00428fee  3bf3                 cmp esi, ebx
// 00428ff0  740c                 je 0x428ffe
// 00428ff2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00428ff5  50                   push eax
// 00428ff6  8bce                 mov ecx, esi
// 00428ff8  ff155c248000         call dword ptr [0x80245c]
// 00428ffe  4f                   dec edi
// 00428fff  83c61c               add esi, 0x1c
// 00429002  885dfc               mov byte ptr [ebp - 4], bl
// 00429005  897508               mov dword ptr [ebp + 8], esi
// 00429008  ebd6                 jmp 0x428fe0
// 0042900a  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 0042900d  8b7d08               mov edi, dword ptr [ebp + 8]
// 00429010  3bf7                 cmp esi, edi
// 00429012  740f                 je 0x429023
// 00429014  8bce                 mov ecx, esi
// 00429016  ff1568248000         call dword ptr [0x802468]
// 0042901c  83c61c               add esi, 0x1c
// 0042901f  3bf7                 cmp esi, edi
// 00429021  75f1                 jne 0x429014
// 00429023  33db                 xor ebx, ebx
// 00429025  53                   push ebx
// 00429026  53                   push ebx
// 00429027  e860852700           call 0x6a158c
// 0042902c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0042902f  5f                   pop edi
// 00429030  5e                   pop esi
// 00429031  64890d00000000       mov dword ptr fs:[0], ecx
// 00429038  5b                   pop ebx
// 00429039  8be5                 mov esp, ebp
// 0042903b  5d                   pop ebp
// 0042903c  c3                   ret 
// 0042903d  cc                   int3 
// 0042903e  cc                   int3 
// 0042903f  cc                   int3 
// 00429040  6aff                 push -1
// 00429042  6811e87c00           push 0x7ce811
// 00429047  64a100000000         mov eax, dword ptr fs:[0]
// 0042904d  50                   push eax
// 0042904e  64892500000000       mov dword ptr fs:[0], esp
// 00429055  51                   push ecx
// 00429056  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042905a  89442414             mov dword ptr [esp + 0x14], eax
// 0042905e  890424               mov dword ptr [esp], eax
// 00429061  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00429069  85c0                 test eax, eax
// 0042906b  7425                 je 0x429092
// 0042906d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00429071  c70000000000         mov dword ptr [eax], 0
// 00429077  8b11                 mov edx, dword ptr [ecx]
// 00429079  85d2                 test edx, edx
// 0042907b  7415                 je 0x429092
// 0042907d  8910                 mov dword ptr [eax], edx
// 0042907f  8b11                 mov edx, dword ptr [ecx]
// 00429081  83c008               add eax, 8
// 00429084  6a00                 push 0
// 00429086  50                   push eax
// 00429087  8b02                 mov eax, dword ptr [edx]
// 00429089  83c108               add ecx, 8
// 0042908c  51                   push ecx
// 0042908d  ffd0                 call eax
// 0042908f  83c40c               add esp, 0xc
// 00429092  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00429096  64890d00000000       mov dword ptr fs:[0], ecx
// 0042909d  83c410               add esp, 0x10
// 004290a0  c3                   ret 

// from server: 100% by auto
// roc 2008-06 00428fb0  unit: MainLogManager  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428fb0
//
// 00428fb0  55                   push ebp
// 00428fb1  8bec                 mov ebp, esp
// 00428fb3  6aff                 push -1
// 00428fb5  6881f27b00           push 0x7bf281
// 00428fba  64a100000000         mov eax, dword ptr fs:[0]
// 00428fc0  50                   push eax
// 00428fc1  64892500000000       mov dword ptr fs:[0], esp
// 00428fc8  83ec0c               sub esp, 0xc
// 00428fcb  53                   push ebx
// 00428fcc  56                   push esi
// 00428fcd  8b7508               mov esi, dword ptr [ebp + 8]
// 00428fd0  57                   push edi
// 00428fd1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00428fd4  33db                 xor ebx, ebx
// 00428fd6  8965f0               mov dword ptr [ebp - 0x10], esp
// 00428fd9  8975ec               mov dword ptr [ebp - 0x14], esi
// 00428fdc  895dfc               mov dword ptr [ebp - 4], ebx
// 00428fdf  90                   nop 
// 00428fe0  3bfb                 cmp edi, ebx
// 00428fe2  7648                 jbe 0x42902c
// 00428fe4  89750c               mov dword ptr [ebp + 0xc], esi
// 00428fe7  8975e8               mov dword ptr [ebp - 0x18], esi
// 00428fea  c645fc01             mov byte ptr [ebp - 4], 1
// 00428fee  3bf3                 cmp esi, ebx
// 00428ff0  740c                 je 0x428ffe
// 00428ff2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00428ff5  50                   push eax
// 00428ff6  8bce                 mov ecx, esi
// 00428ff8  ff155c248000         call dword ptr [0x80245c]
// 00428ffe  4f                   dec edi
// 00428fff  83c61c               add esi, 0x1c
// 00429002  885dfc               mov byte ptr [ebp - 4], bl
// 00429005  897508               mov dword ptr [ebp + 8], esi
// 00429008  ebd6                 jmp 0x428fe0
// standard library vector<string> (function ??$_Uninit_fill_n@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@IABV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
