// from server: 100% by auto
// roc 2009-12 0079f280  unit: seg_00790000  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f280
//
// 0079f280  53                   push ebx
// 0079f281  57                   push edi
// 0079f282  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0079f286  57                   push edi
// 0079f287  e81495feff           call 0x7887a0
// 0079f28c  6a01                 push 1
// 0079f28e  57                   push edi
// 0079f28f  8bd8                 mov ebx, eax
// 0079f291  e8fa96feff           call 0x788990
// 0079f296  83c40c               add esp, 0xc
// 0079f299  83f804               cmp eax, 4
// 0079f29c  7525                 jne 0x79f2c3
// 0079f29e  6a00                 push 0
// 0079f2a0  6a01                 push 1
// 0079f2a2  57                   push edi
// 0079f2a3  e8f898feff           call 0x788ba0
// 0079f2a8  83c40c               add esp, 0xc
// 0079f2ab  803823               cmp byte ptr [eax], 0x23
// 0079f2ae  7513                 jne 0x79f2c3
// 0079f2b0  4b                   dec ebx
// 0079f2b1  53                   push ebx
// 0079f2b2  57                   push edi
// 0079f2b3  e8c89afeff           call 0x788d80
// 0079f2b8  83c408               add esp, 8
// 0079f2bb  5f                   pop edi
// 0079f2bc  b801000000           mov eax, 1
// 0079f2c1  5b                   pop ebx
// 0079f2c2  c3                   ret 
// 0079f2c3  56                   push esi
// 0079f2c4  6a01                 push 1
// 0079f2c6  57                   push edi
// 0079f2c7  e8e4b5feff           call 0x78a8b0
// 0079f2cc  8bf0                 mov esi, eax
// 0079f2ce  83c408               add esp, 8
// 0079f2d1  85f6                 test esi, esi
// 0079f2d3  7d04                 jge 0x79f2d9
// 0079f2d5  03f3                 add esi, ebx
// 0079f2d7  eb06                 jmp 0x79f2df
// 0079f2d9  3bf3                 cmp esi, ebx
// 0079f2db  7e02                 jle 0x79f2df
// 0079f2dd  8bf3                 mov esi, ebx
// 0079f2df  83fe01               cmp esi, 1
// 0079f2e2  7d10                 jge 0x79f2f4
// 0079f2e4  6880b69e00           push 0x9eb680
// 0079f2e9  6a01                 push 1
// 0079f2eb  57                   push edi
// 0079f2ec  e88fb2feff           call 0x78a580
// 0079f2f1  83c40c               add esp, 0xc
// 0079f2f4  8bc3                 mov eax, ebx
// 0079f2f6  2bc6                 sub eax, esi
// 0079f2f8  5e                   pop esi
// 0079f2f9  5f                   pop edi
// 0079f2fa  5b                   pop ebx
// 0079f2fb  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_select)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
