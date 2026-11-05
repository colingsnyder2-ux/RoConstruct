// from server: 100% by auto
// roc 2009-06 006b9020  unit: RBX::UniversalTool  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9020
//
// 006b9020  8b442408             mov eax, dword ptr [esp + 8]
// 006b9024  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b9028  e8a3fbffff           call 0x6b8bd0
// 006b902d  3d78c38e00           cmp eax, 0x8ec378
// 006b9032  740d                 je 0x6b9041
// 006b9034  8b4008               mov eax, dword ptr [eax + 8]
// 006b9037  83f804               cmp eax, 4
// 006b903a  7408                 je 0x6b9044
// 006b903c  83f803               cmp eax, 3
// 006b903f  7403                 je 0x6b9044
// 006b9041  33c0                 xor eax, eax
// 006b9043  c3                   ret 
// 006b9044  b801000000           mov eax, 1
// 006b9049  c3                   ret 
// library lua-5.1/lapi.c (function _lua_isstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
