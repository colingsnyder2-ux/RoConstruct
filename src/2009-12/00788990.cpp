// from server: 100% by auto
// roc 2009-12 00788990  unit: RBX::UniversalTool  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788990
//
// 00788990  8b442408             mov eax, dword ptr [esp + 8]
// 00788994  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788998  e853fcffff           call 0x7885f0
// 0078899d  3d28aa9e00           cmp eax, 0x9eaa28
// 007889a2  7504                 jne 0x7889a8
// 007889a4  83c8ff               or eax, 0xffffffff
// 007889a7  c3                   ret 
// 007889a8  8b4008               mov eax, dword ptr [eax + 8]
// 007889ab  c3                   ret 
// library lua-5.1/lapi.c (function _lua_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
