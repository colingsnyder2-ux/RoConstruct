// from server: 100% by auto
// roc 2010-06 007212a0  unit: RBX::UniversalTool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007212a0
//
// 007212a0  8b442408             mov eax, dword ptr [esp + 8]
// 007212a4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007212a8  83ec10               sub esp, 0x10
// 007212ab  e8f0faffff           call 0x720da0
// 007212b0  83780803             cmp dword ptr [eax + 8], 3
// 007212b4  7417                 je 0x7212cd
// 007212b6  8d0c24               lea ecx, [esp]
// 007212b9  51                   push ecx
// 007212ba  50                   push eax
// 007212bb  e8709e0500           call 0x77b130
// 007212c0  83c408               add esp, 8
// 007212c3  85c0                 test eax, eax
// 007212c5  7506                 jne 0x7212cd
// 007212c7  d9ee                 fldz 
// 007212c9  83c410               add esp, 0x10
// 007212cc  c3                   ret 
// 007212cd  dd00                 fld qword ptr [eax]
// 007212cf  83c410               add esp, 0x10
// 007212d2  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
