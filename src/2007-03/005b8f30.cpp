// from server: 100% by auto
// roc 2007-03 005b8f30  unit: seg_005b0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8f30
//
// 005b8f30  8b442408             mov eax, dword ptr [esp + 8]
// 005b8f34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005b8f38  e873f9ffff           call 0x5b88b0
// 005b8f3d  83780806             cmp dword ptr [eax + 8], 6
// 005b8f41  750c                 jne 0x5b8f4f
// 005b8f43  8b00                 mov eax, dword ptr [eax]
// 005b8f45  80780600             cmp byte ptr [eax + 6], 0
// 005b8f49  7404                 je 0x5b8f4f
// 005b8f4b  8b4010               mov eax, dword ptr [eax + 0x10]
// 005b8f4e  c3                   ret 
// 005b8f4f  33c0                 xor eax, eax
// 005b8f51  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_tocfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
