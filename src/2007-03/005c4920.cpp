// from server: 100% by auto
// roc 2007-03 005c4920  unit: seg_005c0000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4920
//
// 005c4920  51                   push ecx
// 005c4921  55                   push ebp
// 005c4922  56                   push esi
// 005c4923  57                   push edi
// 005c4924  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005c4928  8d44240c             lea eax, [esp + 0xc]
// 005c492c  50                   push eax
// 005c492d  6a01                 push 1
// 005c492f  57                   push edi
// 005c4930  e88b5cffff           call 0x5ba5c0
// 005c4935  8b742418             mov esi, dword ptr [esp + 0x18]
// 005c4939  6a02                 push 2
// 005c493b  57                   push edi
// 005c493c  8be8                 mov ebp, eax
// 005c493e  e8bd5dffff           call 0x5ba700
// 005c4943  83c414               add esp, 0x14
// 005c4946  85c0                 test eax, eax
// 005c4948  7c04                 jl 0x5c494e
// 005c494a  8bf0                 mov esi, eax
// 005c494c  eb04                 jmp 0x5c4952
// 005c494e  8d743001             lea esi, [eax + esi + 1]
// 005c4952  53                   push ebx
// 005c4953  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005c4957  6aff                 push -1
// 005c4959  6a03                 push 3
// 005c495b  57                   push edi
// 005c495c  e80f5effff           call 0x5ba770
// 005c4961  83c40c               add esp, 0xc
// 005c4964  85c0                 test eax, eax
// 005c4966  7d04                 jge 0x5c496c
// 005c4968  8d441801             lea eax, [eax + ebx + 1]
// 005c496c  83fe01               cmp esi, 1
// 005c496f  5b                   pop ebx
// 005c4970  7d05                 jge 0x5c4977
// 005c4972  be01000000           mov esi, 1
// 005c4977  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c497b  3bc1                 cmp eax, ecx
// 005c497d  7e02                 jle 0x5c4981
// 005c497f  8bc1                 mov eax, ecx
// 005c4981  3bf0                 cmp esi, eax
// 005c4983  7f1e                 jg 0x5c49a3
// 005c4985  2bc6                 sub eax, esi
// 005c4987  83c001               add eax, 1
// 005c498a  50                   push eax
// 005c498b  8d4c2eff             lea ecx, [esi + ebp - 1]
// 005c498f  51                   push ecx
// 005c4990  57                   push edi
// 005c4991  e8ea46ffff           call 0x5b9080
// 005c4996  83c40c               add esp, 0xc
// 005c4999  5f                   pop edi
// 005c499a  5e                   pop esi
// 005c499b  b801000000           mov eax, 1
// 005c49a0  5d                   pop ebp
// 005c49a1  59                   pop ecx
// 005c49a2  c3                   ret 
// 005c49a3  6a00                 push 0
// 005c49a5  68ac497800           push 0x7849ac
// 005c49aa  57                   push edi
// 005c49ab  e8d046ffff           call 0x5b9080
// 005c49b0  83c40c               add esp, 0xc
// 005c49b3  5f                   pop edi
// 005c49b4  5e                   pop esi
// 005c49b5  b801000000           mov eax, 1
// 005c49ba  5d                   pop ebp
// 005c49bb  59                   pop ecx
// 005c49bc  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_sub)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
