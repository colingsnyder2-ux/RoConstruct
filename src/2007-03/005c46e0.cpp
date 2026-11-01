// from server: 100% by auto
// roc 2007-03 005c46e0  unit: seg_005c0000  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c46e0
//
// 005c46e0  55                   push ebp
// 005c46e1  8bec                 mov ebp, esp
// 005c46e3  83e4c0               and esp, 0xffffffc0
// 005c46e6  83ec34               sub esp, 0x34
// 005c46e9  53                   push ebx
// 005c46ea  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005c46ed  56                   push esi
// 005c46ee  57                   push edi
// 005c46ef  53                   push ebx
// 005c46f0  e85b43ffff           call 0x5b8a50
// 005c46f5  6a01                 push 1
// 005c46f7  53                   push ebx
// 005c46f8  8bf8                 mov edi, eax
// 005c46fa  e8815fffff           call 0x5ba680
// 005c46ff  dd542444             fst qword ptr [esp + 0x44]
// 005c4703  be02000000           mov esi, 2
// 005c4708  83c40c               add esp, 0xc
// 005c470b  3bfe                 cmp edi, esi
// 005c470d  7c2a                 jl 0x5c4739
// 005c470f  56                   push esi
// 005c4710  ddd8                 fstp st(0)
// 005c4712  53                   push ebx
// 005c4713  e8685fffff           call 0x5ba680
// 005c4718  dd442440             fld qword ptr [esp + 0x40]
// 005c471c  d8d1                 fcom st(1)
// 005c471e  83c408               add esp, 8
// 005c4721  dfe0                 fnstsw ax
// 005c4723  f6c405               test ah, 5
// 005c4726  7a08                 jp 0x5c4730
// 005c4728  ddd8                 fstp st(0)
// 005c472a  dd542438             fst qword ptr [esp + 0x38]
// 005c472e  eb02                 jmp 0x5c4732
// 005c4730  ddd9                 fstp st(1)
// 005c4732  83c601               add esi, 1
// 005c4735  3bf7                 cmp esi, edi
// 005c4737  7ed6                 jle 0x5c470f
// 005c4739  83ec08               sub esp, 8
// 005c473c  dd1c24               fstp qword ptr [esp]
// 005c473f  53                   push ebx
// 005c4740  e8fb48ffff           call 0x5b9040
// 005c4745  83c40c               add esp, 0xc
// 005c4748  5f                   pop edi
// 005c4749  5e                   pop esi
// 005c474a  b801000000           mov eax, 1
// 005c474f  5b                   pop ebx
// 005c4750  8be5                 mov esp, ebp
// 005c4752  5d                   pop ebp
// 005c4753  c3                   ret 
// library lua-5.1.1/lmathlib.c (function _math_max)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmathlib.c
