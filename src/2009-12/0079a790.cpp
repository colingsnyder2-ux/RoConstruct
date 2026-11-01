// from server: 100% by auto
// roc 2009-12 0079a790  unit: lua_exception  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a790
//
// 0079a790  8b442404             mov eax, dword ptr [esp + 4]
// 0079a794  8b403c               mov eax, dword ptr [eax + 0x3c]
// 0079a797  c3                   ret 
// library lua-5.1.3/ldebug.c (function _lua_gethookcount)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldebug.c
