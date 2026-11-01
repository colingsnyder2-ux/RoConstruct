// from server: 100% by auto
// roc 2007-03 00600f70  unit: seg_00600000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600f70
//
// 00600f70  8b442404             mov eax, dword ptr [esp + 4]
// 00600f74  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00600f77  8b542408             mov edx, dword ptr [esp + 8]
// 00600f7b  51                   push ecx
// 00600f7c  52                   push edx
// 00600f7d  50                   push eax
// 00600f7e  e84dffffff           call 0x600ed0
// 00600f83  83c40c               add esp, 0xc
// 00600f86  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_syntaxerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
