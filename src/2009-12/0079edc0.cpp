// from server: 100% by auto
// roc 2009-12 0079edc0  unit: seg_00790000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079edc0
//
// 0079edc0  56                   push esi
// 0079edc1  8b742408             mov esi, dword ptr [esp + 8]
// 0079edc5  6a00                 push 0
// 0079edc7  6a03                 push 3
// 0079edc9  56                   push esi
// 0079edca  e851a8feff           call 0x789620
// 0079edcf  50                   push eax
// 0079edd0  56                   push esi
// 0079edd1  e8aa9ffeff           call 0x788d80
// 0079edd6  83c414               add esp, 0x14
// 0079edd9  b801000000           mov eax, 1
// 0079edde  5e                   pop esi
// 0079eddf  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_gcinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
