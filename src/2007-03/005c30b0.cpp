// from server: 100% by auto
// roc 2007-03 005c30b0  unit: seg_005c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c30b0
//
// 005c30b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c30b4  57                   push edi
// 005c30b5  8b7c2408             mov edi, dword ptr [esp + 8]
// 005c30b9  8d442410             lea eax, [esp + 0x10]
// 005c30bd  50                   push eax
// 005c30be  51                   push ecx
// 005c30bf  57                   push edi
// 005c30c0  e8cb540300           call 0x5f8590
// 005c30c5  50                   push eax
// 005c30c6  e8e5feffff           call 0x5c2fb0
// 005c30cb  57                   push edi
// 005c30cc  e84fffffff           call 0x5c3020
// 005c30d1  83c414               add esp, 0x14
// 005c30d4  5f                   pop edi
// 005c30d5  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_runerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
