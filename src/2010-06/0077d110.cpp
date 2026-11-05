// from server: 100% by auto
// roc 2010-06 0077d110  unit: RBX::PartDropTool  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077d110
//
// 0077d110  53                   push ebx
// 0077d111  55                   push ebp
// 0077d112  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0077d116  56                   push esi
// 0077d117  57                   push edi
// 0077d118  33f6                 xor esi, esi
// 0077d11a  33db                 xor ebx, ebx
// 0077d11c  33ff                 xor edi, edi
// 0077d11e  395d00               cmp dword ptr [ebp], ebx
// 0077d121  8d4e01               lea ecx, [esi + 1]
// 0077d124  7e3d                 jle 0x77d163
// 0077d126  89442414             mov dword ptr [esp + 0x14], eax
// 0077d12a  8d9b00000000         lea ebx, [ebx]
// 0077d130  8b542414             mov edx, dword ptr [esp + 0x14]
// 0077d134  8b02                 mov eax, dword ptr [edx]
// 0077d136  85c0                 test eax, eax
// 0077d138  7e11                 jle 0x77d14b
// 0077d13a  03f0                 add esi, eax
// 0077d13c  8bc1                 mov eax, ecx
// 0077d13e  99                   cdq 
// 0077d13f  2bc2                 sub eax, edx
// 0077d141  d1f8                 sar eax, 1
// 0077d143  3bf0                 cmp esi, eax
// 0077d145  7e04                 jle 0x77d14b
// 0077d147  8bf9                 mov edi, ecx
// 0077d149  8bde                 mov ebx, esi
// 0077d14b  3b7500               cmp esi, dword ptr [ebp]
// 0077d14e  7413                 je 0x77d163
// 0077d150  8344241404           add dword ptr [esp + 0x14], 4
// 0077d155  03c9                 add ecx, ecx
// 0077d157  8bc1                 mov eax, ecx
// 0077d159  99                   cdq 
// 0077d15a  2bc2                 sub eax, edx
// 0077d15c  d1f8                 sar eax, 1
// 0077d15e  3b4500               cmp eax, dword ptr [ebp]
// 0077d161  7ccd                 jl 0x77d130
// 0077d163  897d00               mov dword ptr [ebp], edi
// 0077d166  5f                   pop edi
// 0077d167  5e                   pop esi
// 0077d168  5d                   pop ebp
// 0077d169  8bc3                 mov eax, ebx
// 0077d16b  5b                   pop ebx
// 0077d16c  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
