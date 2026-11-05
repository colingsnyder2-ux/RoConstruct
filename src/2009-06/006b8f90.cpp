// from server: 100% by auto
// roc 2009-06 006b8f90  unit: RBX::UniversalTool  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8f90
//
// 006b8f90  8b442408             mov eax, dword ptr [esp + 8]
// 006b8f94  83f8ff               cmp eax, -1
// 006b8f97  7506                 jne 0x6b8f9f
// 006b8f99  b8b0ae8e00           mov eax, 0x8eaeb0
// 006b8f9e  c3                   ret 
// 006b8f9f  8b048588db8e00       mov eax, dword ptr [eax*4 + 0x8edb88]
// 006b8fa6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
