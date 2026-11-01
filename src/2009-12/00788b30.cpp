// from server: 100% by auto
// roc 2009-12 00788b30  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788b30
//
// 00788b30  8b442408             mov eax, dword ptr [esp + 8]
// 00788b34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788b38  83ec1c               sub esp, 0x1c
// 00788b3b  e8b0faffff           call 0x7885f0
// 00788b40  83780803             cmp dword ptr [eax + 8], 3
// 00788b44  7416                 je 0x788b5c
// 00788b46  8d4c240c             lea ecx, [esp + 0xc]
// 00788b4a  51                   push ecx
// 00788b4b  50                   push eax
// 00788b4c  e88f530400           call 0x7cdee0
// 00788b51  83c408               add esp, 8
// 00788b54  85c0                 test eax, eax
// 00788b56  7504                 jne 0x788b5c
// 00788b58  83c41c               add esp, 0x1c
// 00788b5b  c3                   ret 
// 00788b5c  dd00                 fld qword ptr [eax]
// 00788b5e  dd5c2404             fstp qword ptr [esp + 4]
// 00788b62  dd442404             fld qword ptr [esp + 4]
// 00788b66  db1c24               fistp dword ptr [esp]
// 00788b69  8b0424               mov eax, dword ptr [esp]
// 00788b6c  83c41c               add esp, 0x1c
// 00788b6f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_tointeger)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
