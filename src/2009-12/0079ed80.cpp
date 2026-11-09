// from server: 100% by auto
// roc 2009-12 0079ed80  unit: seg_00790000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ed80
//
// 0079ed80  56                   push esi
// 0079ed81  8b742408             mov esi, dword ptr [esp + 8]
// 0079ed85  6a05                 push 5
// 0079ed87  6a01                 push 1
// 0079ed89  56                   push esi
// 0079ed8a  e861b9feff           call 0x78a6f0
// 0079ed8f  6a02                 push 2
// 0079ed91  56                   push esi
// 0079ed92  e8a9b9feff           call 0x78a740
// 0079ed97  6a03                 push 3
// 0079ed99  56                   push esi
// 0079ed9a  e8a1b9feff           call 0x78a740
// 0079ed9f  6a03                 push 3
// 0079eda1  56                   push esi
// 0079eda2  e8099afeff           call 0x7887b0
// 0079eda7  6a01                 push 1
// 0079eda9  56                   push esi
// 0079edaa  e8e1a4feff           call 0x789290
// 0079edaf  83c42c               add esp, 0x2c
// 0079edb2  b801000000           mov eax, 1
// 0079edb7  5e                   pop esi
// 0079edb8  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_rawset)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
