// from server: 100% by auto
// roc 2009-12 0079b340  unit: seg_00790000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b340
//
// 0079b340  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079b344  57                   push edi
// 0079b345  8b7c2408             mov edi, dword ptr [esp + 8]
// 0079b349  8d442410             lea eax, [esp + 0x10]
// 0079b34d  50                   push eax
// 0079b34e  51                   push ecx
// 0079b34f  57                   push edi
// 0079b350  e83befffff           call 0x79a290
// 0079b355  50                   push eax
// 0079b356  e8e5feffff           call 0x79b240
// 0079b35b  57                   push edi
// 0079b35c  e84fffffff           call 0x79b2b0
// 0079b361  83c414               add esp, 0x14
// 0079b364  5f                   pop edi
// 0079b365  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_runerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
