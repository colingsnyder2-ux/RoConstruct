// from server: 100% by auto
// roc 2007-03 005c4660  unit: seg_005c0000  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4660
//
// 005c4660  55                   push ebp
// 005c4661  8bec                 mov ebp, esp
// 005c4663  83e4c0               and esp, 0xffffffc0
// 005c4666  83ec34               sub esp, 0x34
// 005c4669  53                   push ebx
// 005c466a  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005c466d  56                   push esi
// 005c466e  57                   push edi
// 005c466f  53                   push ebx
// 005c4670  e8db43ffff           call 0x5b8a50
// 005c4675  6a01                 push 1
// 005c4677  53                   push ebx
// 005c4678  8bf8                 mov edi, eax
// 005c467a  e80160ffff           call 0x5ba680
// 005c467f  dd542444             fst qword ptr [esp + 0x44]
// 005c4683  be02000000           mov esi, 2
// 005c4688  83c40c               add esp, 0xc
// 005c468b  3bfe                 cmp edi, esi
// 005c468d  7c2a                 jl 0x5c46b9
// 005c468f  56                   push esi
// 005c4690  ddd8                 fstp st(0)
// 005c4692  53                   push ebx
// 005c4693  e8e85fffff           call 0x5ba680
// 005c4698  dd442440             fld qword ptr [esp + 0x40]
// 005c469c  d8d1                 fcom st(1)
// 005c469e  83c408               add esp, 8
// 005c46a1  dfe0                 fnstsw ax
// 005c46a3  f6c441               test ah, 0x41
// 005c46a6  7508                 jne 0x5c46b0
// 005c46a8  ddd8                 fstp st(0)
// 005c46aa  dd542438             fst qword ptr [esp + 0x38]
// 005c46ae  eb02                 jmp 0x5c46b2
// 005c46b0  ddd9                 fstp st(1)
// 005c46b2  83c601               add esi, 1
// 005c46b5  3bf7                 cmp esi, edi
// 005c46b7  7ed6                 jle 0x5c468f
// 005c46b9  83ec08               sub esp, 8
// 005c46bc  dd1c24               fstp qword ptr [esp]
// 005c46bf  53                   push ebx
// 005c46c0  e87b49ffff           call 0x5b9040
// 005c46c5  83c40c               add esp, 0xc
// 005c46c8  5f                   pop edi
// 005c46c9  5e                   pop esi
// 005c46ca  b801000000           mov eax, 1
// 005c46cf  5b                   pop ebx
// 005c46d0  8be5                 mov esp, ebp
// 005c46d2  5d                   pop ebp
// 005c46d3  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_min)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
