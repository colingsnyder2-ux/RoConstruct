// from server: 100% by auto
// roc 2009-12 00695f00  unit: RBX::ArrowTool  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00695f00
//
// 00695f00  8b442404             mov eax, dword ptr [esp + 4]
// 00695f04  6a00                 push 0
// 00695f06  50                   push eax
// 00695f07  e8a4c4e7ff           call 0x5123b0
// 00695f0c  83c408               add esp, 8
// 00695f0f  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_match)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
