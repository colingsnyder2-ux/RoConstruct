// from server: 100% by auto
// roc 2007-03 005fd380  unit: seg_005f0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd380
//
// 005fd380  8b442404             mov eax, dword ptr [esp + 4]
// 005fd384  68e0037c00           push 0x7c03e0
// 005fd389  50                   push eax
// 005fd38a  e8215dfcff           call 0x5c30b0
// 005fd38f  83c408               add esp, 8
// 005fd392  33c0                 xor eax, eax
// 005fd394  c3                   ret 
// library lua-5.1.1/lmem.c (function _luaM_toobig)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmem.c
