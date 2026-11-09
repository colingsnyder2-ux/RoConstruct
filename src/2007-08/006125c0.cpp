// from server: 100% by auto
// roc 2007-08 006125c0  unit: seg_00610000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006125c0
//
// 006125c0  56                   push esi
// 006125c1  8b742410             mov esi, dword ptr [esp + 0x10]
// 006125c5  57                   push edi
// 006125c6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006125ca  56                   push esi
// 006125cb  57                   push edi
// 006125cc  e83fffffff           call 0x612510
// 006125d1  83c408               add esp, 8
// 006125d4  3de82f7c00           cmp eax, 0x7c2fe8
// 006125d9  c6470600             mov byte ptr [edi + 6], 0
// 006125dd  753f                 jne 0x61261e
// 006125df  8b4608               mov eax, dword ptr [esi + 8]
// 006125e2  85c0                 test eax, eax
// 006125e4  53                   push ebx
// 006125e5  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006125e9  7507                 jne 0x6125f2
// 006125eb  6814337c00           push 0x7c3314
// 006125f0  eb17                 jmp 0x612609
// 006125f2  83f803               cmp eax, 3
// 006125f5  751b                 jne 0x612612
// 006125f7  dd06                 fld qword ptr [esi]
// 006125f9  d9c0                 fld st(0)
// 006125fb  dae9                 fucompp 
// 006125fd  dfe0                 fnstsw ax
// 006125ff  f6c444               test ah, 0x44
// 00612602  7b0e                 jnp 0x612612
// 00612604  6800337c00           push 0x7c3300
// 00612609  53                   push ebx
// 0061260a  e8f149fbff           call 0x5c7000
// 0061260f  83c408               add esp, 8
// 00612612  56                   push esi
// 00612613  57                   push edi
// 00612614  53                   push ebx
// 00612615  e8b6040000           call 0x612ad0
// 0061261a  83c40c               add esp, 0xc
// 0061261d  5b                   pop ebx
// 0061261e  5f                   pop edi
// 0061261f  5e                   pop esi
// 00612620  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_set)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
