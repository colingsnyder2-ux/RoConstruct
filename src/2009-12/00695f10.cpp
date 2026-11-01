// from server: 100% by auto
// roc 2009-12 00695f10  unit: RBX::ArrowTool  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00695f10
//
// 00695f10  8b442404             mov eax, dword ptr [esp + 4]
// 00695f14  6a00                 push 0
// 00695f16  50                   push eax
// 00695f17  e884c4e7ff           call 0x5123a0
// 00695f1c  83c408               add esp, 8
// 00695f1f  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_match)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
