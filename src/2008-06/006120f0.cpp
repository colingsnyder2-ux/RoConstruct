// from server: 100% by auto
// roc 2008-06 006120f0  unit: seg_00610000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006120f0
//
// 006120f0  8b442408             mov eax, dword ptr [esp + 8]
// 006120f4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006120f8  e893f9ffff           call 0x611a90
// 006120fd  83780806             cmp dword ptr [eax + 8], 6
// 00612101  750c                 jne 0x61210f
// 00612103  8b00                 mov eax, dword ptr [eax]
// 00612105  80780600             cmp byte ptr [eax + 6], 0
// 00612109  7404                 je 0x61210f
// 0061210b  8b4010               mov eax, dword ptr [eax + 0x10]
// 0061210e  c3                   ret 
// 0061210f  33c0                 xor eax, eax
// 00612111  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tocfunction)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
