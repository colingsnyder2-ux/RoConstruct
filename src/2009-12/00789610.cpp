// from server: 100% by auto
// roc 2009-12 00789610  unit: RBX::UniversalTool  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789610
//
// 00789610  8b442404             mov eax, dword ptr [esp + 4]
// 00789614  0fb64006             movzx eax, byte ptr [eax + 6]
// 00789618  c3                   ret 
// library lua-5.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
