// from server: 100% by auto
// roc 2009-12 0079ef80  unit: seg_00790000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ef80
//
// 0079ef80  56                   push esi
// 0079ef81  8b742408             mov esi, dword ptr [esp + 8]
// 0079ef85  6a05                 push 5
// 0079ef87  6a01                 push 1
// 0079ef89  56                   push esi
// 0079ef8a  e861b7feff           call 0x78a6f0
// 0079ef8f  68edd8ffff           push 0xffffd8ed
// 0079ef94  56                   push esi
// 0079ef95  e8c699feff           call 0x788960
// 0079ef9a  6a01                 push 1
// 0079ef9c  56                   push esi
// 0079ef9d  e8be99feff           call 0x788960
// 0079efa2  6a00                 push 0
// 0079efa4  56                   push esi
// 0079efa5  e8d69dfeff           call 0x788d80
// 0079efaa  83c424               add esp, 0x24
// 0079efad  b803000000           mov eax, 3
// 0079efb2  5e                   pop esi
// 0079efb3  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_ipairs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
