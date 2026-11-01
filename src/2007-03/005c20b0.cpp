// from server: 100% by auto
// roc 2007-03 005c20b0  unit: seg_005c0000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c20b0
//
// 005c20b0  56                   push esi
// 005c20b1  57                   push edi
// 005c20b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005c20b6  68f4987b00           push 0x7b98f4
// 005c20bb  6a01                 push 1
// 005c20bd  57                   push edi
// 005c20be  e8ed83ffff           call 0x5ba4b0
// 005c20c3  8bf0                 mov esi, eax
// 005c20c5  83c40c               add esp, 0xc
// 005c20c8  833e00               cmp dword ptr [esi], 0
// 005c20cb  750e                 jne 0x5c20db
// 005c20cd  68fc987b00           push 0x7b98fc
// 005c20d2  57                   push edi
// 005c20d3  e8787affff           call 0x5b9b50
// 005c20d8  83c408               add esp, 8
// 005c20db  8b36                 mov esi, dword ptr [esi]
// 005c20dd  56                   push esi
// 005c20de  b802000000           mov eax, 2
// 005c20e3  e878feffff           call 0x5c1f60
// 005c20e8  83c404               add esp, 4
// 005c20eb  5f                   pop edi
// 005c20ec  5e                   pop esi
// 005c20ed  c3                   ret 
// library lua-5.1.1/liolib.c (function _f_write)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
