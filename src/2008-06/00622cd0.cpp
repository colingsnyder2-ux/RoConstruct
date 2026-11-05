// from server: 100% by auto
// roc 2008-06 00622cd0  unit: lua_exception  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00622cd0
//
// 00622cd0  8b442404             mov eax, dword ptr [esp + 4]
// 00622cd4  8b4038               mov eax, dword ptr [eax + 0x38]
// 00622cd7  c3                   ret 
// library lua-5.1.2/ldebug.c (function _lua_gethookcount)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldebug.c
