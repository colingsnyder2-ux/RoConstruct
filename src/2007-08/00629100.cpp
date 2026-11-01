// from server: 100% by auto
// roc 2007-08 00629100  unit: RBX::AssemblyStage  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00629100
//
// 00629100  53                   push ebx
// 00629101  56                   push esi
// 00629102  e8f9feffff           call 0x629000
// 00629107  8b03                 mov eax, dword ptr [ebx]
// 00629109  8d48ff               lea ecx, [eax - 1]
// 0062910c  83c408               add esp, 8
// 0062910f  83f90b               cmp ecx, 0xb
// 00629112  0f87c2000000         ja 0x6291da
// 00629118  ff248ddc916200       jmp dword ptr [ecx*4 + 0x6291dc]
// 0062911f  6a01                 push 1
// 00629121  57                   push edi
// 00629122  56                   push esi
// 00629123  e858fdffff           call 0x628e80
// 00629128  83c40c               add esp, 0xc
// 0062912b  897b08               mov dword ptr [ebx + 8], edi
// 0062912e  c7030c000000         mov dword ptr [ebx], 0xc
// 00629134  c3                   ret 
// 00629135  33c9                 xor ecx, ecx
// 00629137  83f802               cmp eax, 2
// 0062913a  0f94c1               sete cl
// 0062913d  6a00                 push 0
// 0062913f  51                   push ecx
// 00629140  57                   push edi
// 00629141  6a02                 push 2
// 00629143  56                   push esi
// 00629144  e837fcffff           call 0x628d80
// 00629149  83c414               add esp, 0x14
// 0062914c  897b08               mov dword ptr [ebx + 8], edi
// 0062914f  c7030c000000         mov dword ptr [ebx], 0xc
// 00629155  c3                   ret 
// 00629156  8b5308               mov edx, dword ptr [ebx + 8]
// 00629159  52                   push edx
// 0062915a  57                   push edi
// 0062915b  6a01                 push 1
// 0062915d  56                   push esi
// 0062915e  e84dfcffff           call 0x628db0
// 00629163  83c410               add esp, 0x10
// 00629166  897b08               mov dword ptr [ebx + 8], edi
// 00629169  c7030c000000         mov dword ptr [ebx], 0xc
// 0062916f  c3                   ret 
// 00629170  dd4308               fld qword ptr [ebx + 8]
// 00629173  83ec08               sub esp, 8
// 00629176  dd1c24               fstp qword ptr [esp]
// 00629179  56                   push esi
// 0062917a  e8a1f8ffff           call 0x628a20
// 0062917f  50                   push eax
// 00629180  57                   push edi
// 00629181  6a01                 push 1
// 00629183  56                   push esi
// 00629184  e827fcffff           call 0x628db0
// 00629189  83c41c               add esp, 0x1c
// 0062918c  897b08               mov dword ptr [ebx + 8], edi
// 0062918f  c7030c000000         mov dword ptr [ebx], 0xc
// 00629195  c3                   ret 
// 00629196  8b0e                 mov ecx, dword ptr [esi]
// 00629198  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0062919b  8b4308               mov eax, dword ptr [ebx + 8]
// 0062919e  8bcf                 mov ecx, edi
// 006291a0  c1e106               shl ecx, 6
// 006291a3  330c82               xor ecx, dword ptr [edx + eax*4]
// 006291a6  8d0482               lea eax, [edx + eax*4]
// 006291a9  81e1c03f0000         and ecx, 0x3fc0
// 006291af  3108                 xor dword ptr [eax], ecx
// 006291b1  897b08               mov dword ptr [ebx + 8], edi
// 006291b4  c7030c000000         mov dword ptr [ebx], 0xc
// 006291ba  c3                   ret 
// 006291bb  8b4308               mov eax, dword ptr [ebx + 8]
// 006291be  3bf8                 cmp edi, eax
// 006291c0  740f                 je 0x6291d1
// 006291c2  6a00                 push 0
// 006291c4  50                   push eax
// 006291c5  57                   push edi
// 006291c6  6a00                 push 0
// 006291c8  56                   push esi
// 006291c9  e8b2fbffff           call 0x628d80
// 006291ce  83c414               add esp, 0x14
// 006291d1  897b08               mov dword ptr [ebx + 8], edi
// 006291d4  c7030c000000         mov dword ptr [ebx], 0xc
// 006291da  c3                   ret 
// 006291db  90                   nop 
// 006291dc  1f                   pop ds
// 006291dd  91                   xchg ecx, eax
// 006291de  6200                 bound eax, qword ptr [eax]
// 006291e0  3591620035           xor eax, 0x35006291
// 006291e5  91                   xchg ecx, eax
// 006291e6  6200                 bound eax, qword ptr [eax]
// 006291e8  56                   push esi
// 006291e9  91                   xchg ecx, eax
// 006291ea  6200                 bound eax, qword ptr [eax]
// 006291ec  7091                 jo 0x62917f
// 006291ee  6200                 bound eax, qword ptr [eax]
// 006291f0  da916200da91         ficom dword ptr [ecx - 0x6e25ff9e]
// 006291f6  6200                 bound eax, qword ptr [eax]
// 006291f8  da916200da91         ficom dword ptr [ecx - 0x6e25ff9e]
// 006291fe  6200                 bound eax, qword ptr [eax]
// 00629200  da9162009691         ficom dword ptr [ecx - 0x6e69ff9e]
// 00629206  6200                 bound eax, qword ptr [eax]
// library lua-5.1/lcode.c (function _discharge2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
