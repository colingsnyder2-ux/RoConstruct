// from server: 100% by auto
// roc 2009-12 0079ee90  unit: seg_00790000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ee90
//
// 0079ee90  56                   push esi
// 0079ee91  8b742408             mov esi, dword ptr [esp + 8]
// 0079ee95  6a01                 push 1
// 0079ee97  56                   push esi
// 0079ee98  e8a3b8feff           call 0x78a740
// 0079ee9d  6a01                 push 1
// 0079ee9f  56                   push esi
// 0079eea0  e8eb9afeff           call 0x788990
// 0079eea5  50                   push eax
// 0079eea6  56                   push esi
// 0079eea7  e8049bfeff           call 0x7889b0
// 0079eeac  50                   push eax
// 0079eead  56                   push esi
// 0079eeae  e82d9ffeff           call 0x788de0
// 0079eeb3  83c420               add esp, 0x20
// 0079eeb6  b801000000           mov eax, 1
// 0079eebb  5e                   pop esi
// 0079eebc  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_type)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
