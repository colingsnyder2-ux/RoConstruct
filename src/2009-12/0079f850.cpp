// from server: 100% by auto
// roc 2009-12 0079f850  unit: seg_00790000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f850
//
// 0079f850  56                   push esi
// 0079f851  8b742408             mov esi, dword ptr [esp + 8]
// 0079f855  56                   push esi
// 0079f856  e895ffffff           call 0x79f7f0
// 0079f85b  6a01                 push 1
// 0079f85d  6880f77900           push 0x79f780
// 0079f862  56                   push esi
// 0079f863  e84896feff           call 0x788eb0
// 0079f868  83c410               add esp, 0x10
// 0079f86b  b801000000           mov eax, 1
// 0079f870  5e                   pop esi
// 0079f871  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_cowrap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
