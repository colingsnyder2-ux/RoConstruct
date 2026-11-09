// from server: 100% by auto
// roc 2009-06 006ec390  unit: RBX::PartDropTool  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ec390
//
// 006ec390  56                   push esi
// 006ec391  8b742410             mov esi, dword ptr [esp + 0x10]
// 006ec395  57                   push edi
// 006ec396  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ec39a  56                   push esi
// 006ec39b  57                   push edi
// 006ec39c  e83fffffff           call 0x6ec2e0
// 006ec3a1  83c408               add esp, 8
// 006ec3a4  c6470600             mov byte ptr [edi + 6], 0
// 006ec3a8  3d78c38e00           cmp eax, 0x8ec378
// 006ec3ad  753f                 jne 0x6ec3ee
// 006ec3af  8b4608               mov eax, dword ptr [esi + 8]
// 006ec3b2  53                   push ebx
// 006ec3b3  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006ec3b7  85c0                 test eax, eax
// 006ec3b9  7507                 jne 0x6ec3c2
// 006ec3bb  685cdd8e00           push 0x8edd5c
// 006ec3c0  eb17                 jmp 0x6ec3d9
// 006ec3c2  83f803               cmp eax, 3
// 006ec3c5  751b                 jne 0x6ec3e2
// 006ec3c7  dd06                 fld qword ptr [esi]
// 006ec3c9  d9c0                 fld st(0)
// 006ec3cb  dae9                 fucompp 
// 006ec3cd  dfe0                 fnstsw ax
// 006ec3cf  f6c444               test ah, 0x44
// 006ec3d2  7b0e                 jnp 0x6ec3e2
// 006ec3d4  6848dd8e00           push 0x8edd48
// 006ec3d9  53                   push ebx
// 006ec3da  e861c4fdff           call 0x6c8840
// 006ec3df  83c408               add esp, 8
// 006ec3e2  56                   push esi
// 006ec3e3  57                   push edi
// 006ec3e4  53                   push ebx
// 006ec3e5  e8b6040000           call 0x6ec8a0
// 006ec3ea  83c40c               add esp, 0xc
// 006ec3ed  5b                   pop ebx
// 006ec3ee  5f                   pop edi
// 006ec3ef  5e                   pop esi
// 006ec3f0  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_set)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
