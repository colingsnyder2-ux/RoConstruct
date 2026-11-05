// from server: 100% by auto
// roc 2009-06 006b90d0  unit: RBX::UniversalTool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b90d0
//
// 006b90d0  8b442408             mov eax, dword ptr [esp + 8]
// 006b90d4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b90d8  83ec10               sub esp, 0x10
// 006b90db  e8f0faffff           call 0x6b8bd0
// 006b90e0  83780803             cmp dword ptr [eax + 8], 3
// 006b90e4  7417                 je 0x6b90fd
// 006b90e6  8d0c24               lea ecx, [esp]
// 006b90e9  51                   push ecx
// 006b90ea  50                   push eax
// 006b90eb  e8a00d0300           call 0x6e9e90
// 006b90f0  83c408               add esp, 8
// 006b90f3  85c0                 test eax, eax
// 006b90f5  7506                 jne 0x6b90fd
// 006b90f7  d9ee                 fldz 
// 006b90f9  83c410               add esp, 0x10
// 006b90fc  c3                   ret 
// 006b90fd  dd00                 fld qword ptr [eax]
// 006b90ff  83c410               add esp, 0x10
// 006b9102  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
