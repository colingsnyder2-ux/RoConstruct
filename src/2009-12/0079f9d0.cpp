// from server: 100% by auto
// roc 2009-12 0079f9d0  unit: seg_00790000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f9d0
//
// 0079f9d0  56                   push esi
// 0079f9d1  8b742408             mov esi, dword ptr [esp + 8]
// 0079f9d5  e8f6feffff           call 0x79f8d0
// 0079f9da  6868b49e00           push 0x9eb468
// 0079f9df  6874b79e00           push 0x9eb774
// 0079f9e4  56                   push esi
// 0079f9e5  e836b1feff           call 0x78ab20
// 0079f9ea  83c40c               add esp, 0xc
// 0079f9ed  b802000000           mov eax, 2
// 0079f9f2  5e                   pop esi
// 0079f9f3  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaopen_base)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
