// from server: 100% by auto
// roc 2008-06 0065eb50  unit: seg_00650000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065eb50
//
// 0065eb50  56                   push esi
// 0065eb51  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065eb55  57                   push edi
// 0065eb56  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065eb5a  56                   push esi
// 0065eb5b  57                   push edi
// 0065eb5c  e83fffffff           call 0x65eaa0
// 0065eb61  83c408               add esp, 8
// 0065eb64  c6470600             mov byte ptr [edi + 6], 0
// 0065eb68  3d80488400           cmp eax, 0x844880
// 0065eb6d  753f                 jne 0x65ebae
// 0065eb6f  8b4608               mov eax, dword ptr [esi + 8]
// 0065eb72  53                   push ebx
// 0065eb73  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0065eb77  85c0                 test eax, eax
// 0065eb79  7507                 jne 0x65eb82
// 0065eb7b  682cc48400           push 0x84c42c
// 0065eb80  eb17                 jmp 0x65eb99
// 0065eb82  83f803               cmp eax, 3
// 0065eb85  751b                 jne 0x65eba2
// 0065eb87  dd06                 fld qword ptr [esi]
// 0065eb89  d9c0                 fld st(0)
// 0065eb8b  dae9                 fucompp 
// 0065eb8d  dfe0                 fnstsw ax
// 0065eb8f  f6c444               test ah, 0x44
// 0065eb92  7b0e                 jnp 0x65eba2
// 0065eb94  6818c48400           push 0x84c418
// 0065eb99  53                   push ebx
// 0065eb9a  e8314cfcff           call 0x6237d0
// 0065eb9f  83c408               add esp, 8
// 0065eba2  56                   push esi
// 0065eba3  57                   push edi
// 0065eba4  53                   push ebx
// 0065eba5  e8b6040000           call 0x65f060
// 0065ebaa  83c40c               add esp, 0xc
// 0065ebad  5b                   pop ebx
// 0065ebae  5f                   pop edi
// 0065ebaf  5e                   pop esi
// 0065ebb0  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_set)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
