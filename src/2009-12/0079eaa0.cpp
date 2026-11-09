// from server: 100% by auto
// roc 2009-12 0079eaa0  unit: seg_00790000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079eaa0
//
// 0079eaa0  56                   push esi
// 0079eaa1  8b742408             mov esi, dword ptr [esp + 8]
// 0079eaa5  6a01                 push 1
// 0079eaa7  56                   push esi
// 0079eaa8  e893bcfeff           call 0x78a740
// 0079eaad  6a01                 push 1
// 0079eaaf  56                   push esi
// 0079eab0  e87ba6feff           call 0x789130
// 0079eab5  83c410               add esp, 0x10
// 0079eab8  85c0                 test eax, eax
// 0079eaba  7510                 jne 0x79eacc
// 0079eabc  56                   push esi
// 0079eabd  e87ea2feff           call 0x788d40
// 0079eac2  83c404               add esp, 4
// 0079eac5  b801000000           mov eax, 1
// 0079eaca  5e                   pop esi
// 0079eacb  c3                   ret 
// 0079eacc  68b4b49e00           push 0x9eb4b4
// 0079ead1  6a01                 push 1
// 0079ead3  56                   push esi
// 0079ead4  e8d7b2feff           call 0x789db0
// 0079ead9  83c40c               add esp, 0xc
// 0079eadc  b801000000           mov eax, 1
// 0079eae1  5e                   pop esi
// 0079eae2  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_getmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
