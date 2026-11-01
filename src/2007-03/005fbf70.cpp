// from server: 100% by auto
// roc 2007-03 005fbf70  unit: seg_005f0000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbf70
//
// 005fbf70  56                   push esi
// 005fbf71  8b742410             mov esi, dword ptr [esp + 0x10]
// 005fbf75  57                   push edi
// 005fbf76  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005fbf7a  56                   push esi
// 005fbf7b  57                   push edi
// 005fbf7c  e83fffffff           call 0x5fbec0
// 005fbf81  83c408               add esp, 8
// 005fbf84  3da0007c00           cmp eax, 0x7c00a0
// 005fbf89  c6470600             mov byte ptr [edi + 6], 0
// 005fbf8d  753f                 jne 0x5fbfce
// 005fbf8f  8b4608               mov eax, dword ptr [esi + 8]
// 005fbf92  85c0                 test eax, eax
// 005fbf94  53                   push ebx
// 005fbf95  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005fbf99  7507                 jne 0x5fbfa2
// 005fbf9b  68cc037c00           push 0x7c03cc
// 005fbfa0  eb17                 jmp 0x5fbfb9
// 005fbfa2  83f803               cmp eax, 3
// 005fbfa5  751b                 jne 0x5fbfc2
// 005fbfa7  dd06                 fld qword ptr [esi]
// 005fbfa9  d9c0                 fld st(0)
// 005fbfab  dae9                 fucompp 
// 005fbfad  dfe0                 fnstsw ax
// 005fbfaf  f6c444               test ah, 0x44
// 005fbfb2  7b0e                 jnp 0x5fbfc2
// 005fbfb4  68b8037c00           push 0x7c03b8
// 005fbfb9  53                   push ebx
// 005fbfba  e8f170fcff           call 0x5c30b0
// 005fbfbf  83c408               add esp, 8
// 005fbfc2  56                   push esi
// 005fbfc3  57                   push edi
// 005fbfc4  53                   push ebx
// 005fbfc5  e8b6040000           call 0x5fc480
// 005fbfca  83c40c               add esp, 0xc
// 005fbfcd  5b                   pop ebx
// 005fbfce  5f                   pop edi
// 005fbfcf  5e                   pop esi
// 005fbfd0  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_set)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
