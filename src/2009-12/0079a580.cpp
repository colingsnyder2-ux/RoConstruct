// from server: 100% by auto
// roc 2009-12 0079a580  unit: lua_exception  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a580
//
// 0079a580  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079a584  8b542404             mov edx, dword ptr [esp + 4]
// 0079a588  8d44240c             lea eax, [esp + 0xc]
// 0079a58c  50                   push eax
// 0079a58d  51                   push ecx
// 0079a58e  52                   push edx
// 0079a58f  e8fcfcffff           call 0x79a290
// 0079a594  83c40c               add esp, 0xc
// 0079a597  c3                   ret 
// library lua-5.1/lobject.c (function _luaO_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lobject.c
