// from server: 100% by auto
// roc 2008-06 00622cc0  unit: lua_exception  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00622cc0
//
// 00622cc0  8b442404             mov eax, dword ptr [esp + 4]
// 00622cc4  0fb64036             movzx eax, byte ptr [eax + 0x36]
// 00622cc8  c3                   ret 
// library lua-5.1.2/ldebug.c (function _lua_gethookmask)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldebug.c
