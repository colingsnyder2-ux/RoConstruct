// from server: 100% by auto
// roc 2007-03 005fc570  unit: seg_005f0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc570
//
// 005fc570  83ec10               sub esp, 0x10
// 005fc573  56                   push esi
// 005fc574  8b742420             mov esi, dword ptr [esp + 0x20]
// 005fc578  57                   push edi
// 005fc579  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005fc57d  56                   push esi
// 005fc57e  57                   push edi
// 005fc57f  e8fcf8ffff           call 0x5fbe80
// 005fc584  83c408               add esp, 8
// 005fc587  3da0007c00           cmp eax, 0x7c00a0
// 005fc58c  751f                 jne 0x5fc5ad
// 005fc58e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005fc592  8d442408             lea eax, [esp + 8]
// 005fc596  50                   push eax
// 005fc597  57                   push edi
// 005fc598  51                   push ecx
// 005fc599  89742414             mov dword ptr [esp + 0x14], esi
// 005fc59d  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 005fc5a5  e8d6feffff           call 0x5fc480
// 005fc5aa  83c40c               add esp, 0xc
// 005fc5ad  5f                   pop edi
// 005fc5ae  5e                   pop esi
// 005fc5af  83c410               add esp, 0x10
// 005fc5b2  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
