// from server: 100% by auto
// roc 2007-03 005c26c0  unit: seg_005c0000  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c26c0
//
// 005c26c0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c26c4  85c9                 test ecx, ecx
// 005c26c6  8b542404             mov edx, dword ptr [esp + 4]
// 005c26ca  8b4214               mov eax, dword ptr [edx + 0x14]
// 005c26cd  7e25                 jle 0x5c26f4
// 005c26cf  56                   push esi
// 005c26d0  8b7228               mov esi, dword ptr [edx + 0x28]
// 005c26d3  57                   push edi
// 005c26d4  3bc6                 cmp eax, esi
// 005c26d6  7618                 jbe 0x5c26f0
// 005c26d8  8b7804               mov edi, dword ptr [eax + 4]
// 005c26db  8b3f                 mov edi, dword ptr [edi]
// 005c26dd  83e901               sub ecx, 1
// 005c26e0  807f0600             cmp byte ptr [edi + 6], 0
// 005c26e4  7503                 jne 0x5c26e9
// 005c26e6  2b4814               sub ecx, dword ptr [eax + 0x14]
// 005c26e9  83e818               sub eax, 0x18
// 005c26ec  85c9                 test ecx, ecx
// 005c26ee  7fe4                 jg 0x5c26d4
// 005c26f0  5f                   pop edi
// 005c26f1  5e                   pop esi
// 005c26f2  85c9                 test ecx, ecx
// 005c26f4  752b                 jne 0x5c2721
// 005c26f6  8b5228               mov edx, dword ptr [edx + 0x28]
// 005c26f9  3bc2                 cmp eax, edx
// 005c26fb  7639                 jbe 0x5c2736
// 005c26fd  2bc2                 sub eax, edx
// 005c26ff  8bd0                 mov edx, eax
// 005c2701  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c2706  f7ea                 imul edx
// 005c2708  c1fa02               sar edx, 2
// 005c270b  8bc2                 mov eax, edx
// 005c270d  c1e81f               shr eax, 0x1f
// 005c2710  03c2                 add eax, edx
// 005c2712  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005c2716  b901000000           mov ecx, 1
// 005c271b  894260               mov dword ptr [edx + 0x60], eax
// 005c271e  8bc1                 mov eax, ecx
// 005c2720  c3                   ret 
// 005c2721  85c9                 test ecx, ecx
// 005c2723  7d11                 jge 0x5c2736
// 005c2725  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c2729  b801000000           mov eax, 1
// 005c272e  c7416000000000       mov dword ptr [ecx + 0x60], 0
// 005c2735  c3                   ret 
// 005c2736  33c0                 xor eax, eax
// 005c2738  c3                   ret 
// library lua-5.1.1/ldebug.c (function _lua_getstack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
