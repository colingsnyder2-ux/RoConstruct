// from server: 100% by auto
// roc 2009-12 0079ef00  unit: seg_00790000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079ef00
//
// 0079ef00  56                   push esi
// 0079ef01  8b742408             mov esi, dword ptr [esp + 8]
// 0079ef05  6a05                 push 5
// 0079ef07  6a01                 push 1
// 0079ef09  56                   push esi
// 0079ef0a  e8e1b7feff           call 0x78a6f0
// 0079ef0f  68edd8ffff           push 0xffffd8ed
// 0079ef14  56                   push esi
// 0079ef15  e8469afeff           call 0x788960
// 0079ef1a  6a01                 push 1
// 0079ef1c  56                   push esi
// 0079ef1d  e83e9afeff           call 0x788960
// 0079ef22  56                   push esi
// 0079ef23  e8189efeff           call 0x788d40
// 0079ef28  83c420               add esp, 0x20
// 0079ef2b  b803000000           mov eax, 3
// 0079ef30  5e                   pop esi
// 0079ef31  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_pairs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
