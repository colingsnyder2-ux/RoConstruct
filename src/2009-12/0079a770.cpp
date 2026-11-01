// from server: 100% by auto
// roc 2009-12 0079a770  unit: lua_exception  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a770
//
// 0079a770  8b442404             mov eax, dword ptr [esp + 4]
// 0079a774  8b4044               mov eax, dword ptr [eax + 0x44]
// 0079a777  c3                   ret 
// library lua-5.1.3/ldebug.c (function _lua_gethook)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldebug.c
