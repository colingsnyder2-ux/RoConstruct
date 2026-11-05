// from server: 100% by auto
// roc 2009-12 0079ed10  unit: seg_00790000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ed10
//
// 0079ed10  56                   push esi
// 0079ed11  8b742408             mov esi, dword ptr [esp + 8]
// 0079ed15  6a01                 push 1
// 0079ed17  56                   push esi
// 0079ed18  e823bafeff           call 0x78a740
// 0079ed1d  6a02                 push 2
// 0079ed1f  56                   push esi
// 0079ed20  e81bbafeff           call 0x78a740
// 0079ed25  6a02                 push 2
// 0079ed27  6a01                 push 1
// 0079ed29  56                   push esi
// 0079ed2a  e8419dfeff           call 0x788a70
// 0079ed2f  50                   push eax
// 0079ed30  56                   push esi
// 0079ed31  e81aa2feff           call 0x788f50
// 0079ed36  83c424               add esp, 0x24
// 0079ed39  b801000000           mov eax, 1
// 0079ed3e  5e                   pop esi
// 0079ed3f  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
