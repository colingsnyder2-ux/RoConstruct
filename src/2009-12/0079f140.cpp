// from server: 100% by auto
// roc 2009-12 0079f140  unit: seg_00790000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f140
//
// 0079f140  53                   push ebx
// 0079f141  56                   push esi
// 0079f142  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0079f146  57                   push edi
// 0079f147  6a00                 push 0
// 0079f149  6a00                 push 0
// 0079f14b  6a01                 push 1
// 0079f14d  56                   push esi
// 0079f14e  e87db6feff           call 0x78a7d0
// 0079f153  56                   push esi
// 0079f154  8bf8                 mov edi, eax
// 0079f156  e84596feff           call 0x7887a0
// 0079f15b  57                   push edi
// 0079f15c  56                   push esi
// 0079f15d  8bd8                 mov ebx, eax
// 0079f15f  e89cb1feff           call 0x78a300
// 0079f164  83c41c               add esp, 0x1c
// 0079f167  85c0                 test eax, eax
// 0079f169  7409                 je 0x79f174
// 0079f16b  56                   push esi
// 0079f16c  e8afa5feff           call 0x789720
// 0079f171  83c404               add esp, 4
// 0079f174  6aff                 push -1
// 0079f176  6a00                 push 0
// 0079f178  56                   push esi
// 0079f179  e842a3feff           call 0x7894c0
// 0079f17e  56                   push esi
// 0079f17f  e81c96feff           call 0x7887a0
// 0079f184  83c410               add esp, 0x10
// 0079f187  5f                   pop edi
// 0079f188  5e                   pop esi
// 0079f189  2bc3                 sub eax, ebx
// 0079f18b  5b                   pop ebx
// 0079f18c  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_dofile)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
