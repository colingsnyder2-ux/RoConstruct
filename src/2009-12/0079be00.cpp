// from server: 100% by auto
// roc 2009-12 0079be00  unit: seg_00790000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079be00
//
// 0079be00  56                   push esi
// 0079be01  8b742408             mov esi, dword ptr [esp + 8]
// 0079be05  6a05                 push 5
// 0079be07  6a01                 push 1
// 0079be09  56                   push esi
// 0079be0a  e8e1e8feff           call 0x78a6f0
// 0079be0f  6a01                 push 1
// 0079be11  56                   push esi
// 0079be12  e8f9cdfeff           call 0x788c10
// 0079be17  50                   push eax
// 0079be18  56                   push esi
// 0079be19  e862cffeff           call 0x788d80
// 0079be1e  83c41c               add esp, 0x1c
// 0079be21  b801000000           mov eax, 1
// 0079be26  5e                   pop esi
// 0079be27  c3                   ret 
// library lua-5.1/ltablib.c (function _getn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltablib.c
