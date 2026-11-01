// from server: 100% by auto
// roc 2009-12 007d1790  unit: seg_007d0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1790
//
// 007d1790  8b442404             mov eax, dword ptr [esp + 4]
// 007d1794  6888ed9e00           push 0x9eed88
// 007d1799  50                   push eax
// 007d179a  e8a19bfcff           call 0x79b340
// 007d179f  83c408               add esp, 8
// 007d17a2  33c0                 xor eax, eax
// 007d17a4  c3                   ret 
// library lua-5.1/lmem.c (function _luaM_toobig)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmem.c
