// from server: 100% by auto
// roc 2009-06 006b9bf0  unit: RBX::UniversalTool  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9bf0
//
// 006b9bf0  8b442404             mov eax, dword ptr [esp + 4]
// 006b9bf4  0fb64006             movzx eax, byte ptr [eax + 6]
// 006b9bf8  c3                   ret 
// library lua-5.1/lapi.c (function _lua_status)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
