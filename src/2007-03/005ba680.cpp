// from server: 100% by auto
// roc 2007-03 005ba680  unit: seg_005b0000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba680
//
// 005ba680  83ec08               sub esp, 8
// 005ba683  56                   push esi
// 005ba684  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ba688  57                   push edi
// 005ba689  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005ba68d  57                   push edi
// 005ba68e  56                   push esi
// 005ba68f  e80ce7ffff           call 0x5b8da0
// 005ba694  dd542410             fst qword ptr [esp + 0x10]
// 005ba698  d9ee                 fldz 
// 005ba69a  83c408               add esp, 8
// 005ba69d  dde9                 fucomp st(1)
// 005ba69f  dfe0                 fnstsw ax
// 005ba6a1  f6c444               test ah, 0x44
// 005ba6a4  7a46                 jp 0x5ba6ec
// 005ba6a6  57                   push edi
// 005ba6a7  ddd8                 fstp st(0)
// 005ba6a9  56                   push esi
// 005ba6aa  e801e6ffff           call 0x5b8cb0
// 005ba6af  83c408               add esp, 8
// 005ba6b2  85c0                 test eax, eax
// 005ba6b4  7532                 jne 0x5ba6e8
// 005ba6b6  53                   push ebx
// 005ba6b7  6a03                 push 3
// 005ba6b9  56                   push esi
// 005ba6ba  e8a1e5ffff           call 0x5b8c60
// 005ba6bf  57                   push edi
// 005ba6c0  56                   push esi
// 005ba6c1  8bd8                 mov ebx, eax
// 005ba6c3  e878e5ffff           call 0x5b8c40
// 005ba6c8  50                   push eax
// 005ba6c9  56                   push esi
// 005ba6ca  e891e5ffff           call 0x5b8c60
// 005ba6cf  50                   push eax
// 005ba6d0  53                   push ebx
// 005ba6d1  68dc917b00           push 0x7b91dc
// 005ba6d6  56                   push esi
// 005ba6d7  e884eaffff           call 0x5b9160
// 005ba6dc  50                   push eax
// 005ba6dd  57                   push edi
// 005ba6de  56                   push esi
// 005ba6df  e80cfdffff           call 0x5ba3f0
// 005ba6e4  83c434               add esp, 0x34
// 005ba6e7  5b                   pop ebx
// 005ba6e8  dd442408             fld qword ptr [esp + 8]
// 005ba6ec  5f                   pop edi
// 005ba6ed  5e                   pop esi
// 005ba6ee  83c408               add esp, 8
// 005ba6f1  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checknumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
