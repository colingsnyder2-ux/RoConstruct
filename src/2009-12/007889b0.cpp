// from server: 100% by auto
// roc 2009-12 007889b0  unit: RBX::UniversalTool  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007889b0
//
// 007889b0  8b442408             mov eax, dword ptr [esp + 8]
// 007889b4  83f8ff               cmp eax, -1
// 007889b7  7506                 jne 0x7889bf
// 007889b9  b8b09c9e00           mov eax, 0x9e9cb0
// 007889be  c3                   ret 
// 007889bf  8b0485a0eb9e00       mov eax, dword ptr [eax*4 + 0x9eeba0]
// 007889c6  c3                   ret 
// library lua-5.1/lapi.c (function _lua_typename)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
