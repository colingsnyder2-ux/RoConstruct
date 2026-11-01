// from server: 100% by auto
// roc 2009-12 00788af0  unit: RBX::UniversalTool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788af0
//
// 00788af0  8b442408             mov eax, dword ptr [esp + 8]
// 00788af4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788af8  83ec10               sub esp, 0x10
// 00788afb  e8f0faffff           call 0x7885f0
// 00788b00  83780803             cmp dword ptr [eax + 8], 3
// 00788b04  7417                 je 0x788b1d
// 00788b06  8d0c24               lea ecx, [esp]
// 00788b09  51                   push ecx
// 00788b0a  50                   push eax
// 00788b0b  e8d0530400           call 0x7cdee0
// 00788b10  83c408               add esp, 8
// 00788b13  85c0                 test eax, eax
// 00788b15  7506                 jne 0x788b1d
// 00788b17  d9ee                 fldz 
// 00788b19  83c410               add esp, 0x10
// 00788b1c  c3                   ret 
// 00788b1d  dd00                 fld qword ptr [eax]
// 00788b1f  83c410               add esp, 0x10
// 00788b22  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
