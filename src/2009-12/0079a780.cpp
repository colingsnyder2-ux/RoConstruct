// from server: 100% by auto
// roc 2009-12 0079a780  unit: lua_exception  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a780
//
// 0079a780  8b442404             mov eax, dword ptr [esp + 4]
// 0079a784  0fb64038             movzx eax, byte ptr [eax + 0x38]
// 0079a788  c3                   ret 
// library lua-5.1.3/ldebug.c (function _lua_gethookmask)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 ldebug.c
