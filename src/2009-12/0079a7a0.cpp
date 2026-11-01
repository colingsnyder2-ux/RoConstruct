// from server: 100% by auto
// roc 2009-12 0079a7a0  unit: lua_exception  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a7a0
//
// 0079a7a0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079a7a4  8b542404             mov edx, dword ptr [esp + 4]
// 0079a7a8  8b4214               mov eax, dword ptr [edx + 0x14]
// 0079a7ab  85c9                 test ecx, ecx
// 0079a7ad  7e23                 jle 0x79a7d2
// 0079a7af  56                   push esi
// 0079a7b0  8b7228               mov esi, dword ptr [edx + 0x28]
// 0079a7b3  57                   push edi
// 0079a7b4  3bc6                 cmp eax, esi
// 0079a7b6  7616                 jbe 0x79a7ce
// 0079a7b8  8b7804               mov edi, dword ptr [eax + 4]
// 0079a7bb  8b3f                 mov edi, dword ptr [edi]
// 0079a7bd  49                   dec ecx
// 0079a7be  807f0600             cmp byte ptr [edi + 6], 0
// 0079a7c2  7503                 jne 0x79a7c7
// 0079a7c4  2b4814               sub ecx, dword ptr [eax + 0x14]
// 0079a7c7  83e818               sub eax, 0x18
// 0079a7ca  85c9                 test ecx, ecx
// 0079a7cc  7fe6                 jg 0x79a7b4
// 0079a7ce  5f                   pop edi
// 0079a7cf  5e                   pop esi
// 0079a7d0  85c9                 test ecx, ecx
// 0079a7d2  752b                 jne 0x79a7ff
// 0079a7d4  8b5228               mov edx, dword ptr [edx + 0x28]
// 0079a7d7  3bc2                 cmp eax, edx
// 0079a7d9  7639                 jbe 0x79a814
// 0079a7db  2bc2                 sub eax, edx
// 0079a7dd  8bd0                 mov edx, eax
// 0079a7df  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0079a7e4  f7ea                 imul edx
// 0079a7e6  c1fa02               sar edx, 2
// 0079a7e9  8bc2                 mov eax, edx
// 0079a7eb  c1e81f               shr eax, 0x1f
// 0079a7ee  03c2                 add eax, edx
// 0079a7f0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079a7f4  b901000000           mov ecx, 1
// 0079a7f9  894260               mov dword ptr [edx + 0x60], eax
// 0079a7fc  8bc1                 mov eax, ecx
// 0079a7fe  c3                   ret 
// 0079a7ff  85c9                 test ecx, ecx
// 0079a801  7d11                 jge 0x79a814
// 0079a803  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0079a807  b801000000           mov eax, 1
// 0079a80c  c7416000000000       mov dword ptr [ecx + 0x60], 0
// 0079a813  c3                   ret 
// 0079a814  33c0                 xor eax, eax
// 0079a816  c3                   ret 
// library lua-5.1/ldebug.c (function _lua_getstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
