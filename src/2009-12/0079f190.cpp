// from server: 100% by auto
// roc 2009-12 0079f190  unit: seg_00790000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f190
//
// 0079f190  56                   push esi
// 0079f191  8b742408             mov esi, dword ptr [esp + 8]
// 0079f195  6a01                 push 1
// 0079f197  56                   push esi
// 0079f198  e8a3b5feff           call 0x78a740
// 0079f19d  6a01                 push 1
// 0079f19f  56                   push esi
// 0079f1a0  e8cb99feff           call 0x788b70
// 0079f1a5  83c410               add esp, 0x10
// 0079f1a8  85c0                 test eax, eax
// 0079f1aa  751f                 jne 0x79f1cb
// 0079f1ac  50                   push eax
// 0079f1ad  6850b69e00           push 0x9eb650
// 0079f1b2  6a02                 push 2
// 0079f1b4  56                   push esi
// 0079f1b5  e816b6feff           call 0x78a7d0
// 0079f1ba  50                   push eax
// 0079f1bb  6810389a00           push 0x9a3810
// 0079f1c0  56                   push esi
// 0079f1c1  e82aabfeff           call 0x789cf0
// 0079f1c6  83c41c               add esp, 0x1c
// 0079f1c9  5e                   pop esi
// 0079f1ca  c3                   ret 
// 0079f1cb  56                   push esi
// 0079f1cc  e8cf95feff           call 0x7887a0
// 0079f1d1  83c404               add esp, 4
// 0079f1d4  5e                   pop esi
// 0079f1d5  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_assert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
