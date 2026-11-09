// from server: 100% by auto
// roc 2007-08 006120b0  unit: seg_00610000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006120b0
//
// 006120b0  53                   push ebx
// 006120b1  55                   push ebp
// 006120b2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006120b6  56                   push esi
// 006120b7  57                   push edi
// 006120b8  33db                 xor ebx, ebx
// 006120ba  33f6                 xor esi, esi
// 006120bc  33ff                 xor edi, edi
// 006120be  395d00               cmp dword ptr [ebp], ebx
// 006120c1  b901000000           mov ecx, 1
// 006120c6  7e3b                 jle 0x612103
// 006120c8  89442414             mov dword ptr [esp + 0x14], eax
// 006120cc  8d642400             lea esp, [esp]
// 006120d0  8b542414             mov edx, dword ptr [esp + 0x14]
// 006120d4  8b02                 mov eax, dword ptr [edx]
// 006120d6  85c0                 test eax, eax
// 006120d8  7e11                 jle 0x6120eb
// 006120da  03f0                 add esi, eax
// 006120dc  8bc1                 mov eax, ecx
// 006120de  99                   cdq 
// 006120df  2bc2                 sub eax, edx
// 006120e1  d1f8                 sar eax, 1
// 006120e3  3bf0                 cmp esi, eax
// 006120e5  7e04                 jle 0x6120eb
// 006120e7  8bf9                 mov edi, ecx
// 006120e9  8bde                 mov ebx, esi
// 006120eb  3b7500               cmp esi, dword ptr [ebp]
// 006120ee  7413                 je 0x612103
// 006120f0  8344241404           add dword ptr [esp + 0x14], 4
// 006120f5  03c9                 add ecx, ecx
// 006120f7  8bc1                 mov eax, ecx
// 006120f9  99                   cdq 
// 006120fa  2bc2                 sub eax, edx
// 006120fc  d1f8                 sar eax, 1
// 006120fe  3b4500               cmp eax, dword ptr [ebp]
// 00612101  7ccd                 jl 0x6120d0
// 00612103  897d00               mov dword ptr [ebp], edi
// 00612106  5f                   pop edi
// 00612107  5e                   pop esi
// 00612108  5d                   pop ebp
// 00612109  8bc3                 mov eax, ebx
// 0061210b  5b                   pop ebx
// 0061210c  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
