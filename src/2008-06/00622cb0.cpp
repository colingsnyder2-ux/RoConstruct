// from server: 100% by auto
// roc 2008-06 00622cb0  unit: lua_exception  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00622cb0
//
// 00622cb0  8b442404             mov eax, dword ptr [esp + 4]
// 00622cb4  8b4040               mov eax, dword ptr [eax + 0x40]
// 00622cb7  c3                   ret 
// library lua-5.1.2/ldebug.c (function _lua_gethook)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldebug.c
