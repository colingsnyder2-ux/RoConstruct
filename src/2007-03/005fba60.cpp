// from server: 100% by auto
// roc 2007-03 005fba60  unit: seg_005f0000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fba60
//
// 005fba60  53                   push ebx
// 005fba61  55                   push ebp
// 005fba62  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005fba66  56                   push esi
// 005fba67  57                   push edi
// 005fba68  33db                 xor ebx, ebx
// 005fba6a  33f6                 xor esi, esi
// 005fba6c  33ff                 xor edi, edi
// 005fba6e  395d00               cmp dword ptr [ebp], ebx
// 005fba71  b901000000           mov ecx, 1
// 005fba76  7e3b                 jle 0x5fbab3
// 005fba78  89442414             mov dword ptr [esp + 0x14], eax
// 005fba7c  8d642400             lea esp, [esp]
// 005fba80  8b542414             mov edx, dword ptr [esp + 0x14]
// 005fba84  8b02                 mov eax, dword ptr [edx]
// 005fba86  85c0                 test eax, eax
// 005fba88  7e11                 jle 0x5fba9b
// 005fba8a  03f0                 add esi, eax
// 005fba8c  8bc1                 mov eax, ecx
// 005fba8e  99                   cdq 
// 005fba8f  2bc2                 sub eax, edx
// 005fba91  d1f8                 sar eax, 1
// 005fba93  3bf0                 cmp esi, eax
// 005fba95  7e04                 jle 0x5fba9b
// 005fba97  8bf9                 mov edi, ecx
// 005fba99  8bde                 mov ebx, esi
// 005fba9b  3b7500               cmp esi, dword ptr [ebp]
// 005fba9e  7413                 je 0x5fbab3
// 005fbaa0  8344241404           add dword ptr [esp + 0x14], 4
// 005fbaa5  03c9                 add ecx, ecx
// 005fbaa7  8bc1                 mov eax, ecx
// 005fbaa9  99                   cdq 
// 005fbaaa  2bc2                 sub eax, edx
// 005fbaac  d1f8                 sar eax, 1
// 005fbaae  3b4500               cmp eax, dword ptr [ebp]
// 005fbab1  7ccd                 jl 0x5fba80
// 005fbab3  897d00               mov dword ptr [ebp], edi
// 005fbab6  5f                   pop edi
// 005fbab7  5e                   pop esi
// 005fbab8  5d                   pop ebp
// 005fbab9  8bc3                 mov eax, ebx
// 005fbabb  5b                   pop ebx
// 005fbabc  c3                   ret 
// library lua-5.1.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
