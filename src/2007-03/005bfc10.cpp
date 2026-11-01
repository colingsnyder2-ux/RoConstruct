// from server: 100% by auto
// roc 2007-03 005bfc10  unit: seg_005b0000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfc10
//
// 005bfc10  53                   push ebx
// 005bfc11  55                   push ebp
// 005bfc12  56                   push esi
// 005bfc13  8b742410             mov esi, dword ptr [esp + 0x10]
// 005bfc17  8b6e20               mov ebp, dword ptr [esi + 0x20]
// 005bfc1a  57                   push edi
// 005bfc1b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005bfc1f  8d5f06               lea ebx, [edi + 6]
// 005bfc22  8d4301               lea eax, [ebx + 1]
// 005bfc25  3dffffff0f           cmp eax, 0xfffffff
// 005bfc2a  7719                 ja 0x5bfc45
// 005bfc2c  8b562c               mov edx, dword ptr [esi + 0x2c]
// 005bfc2f  8bcb                 mov ecx, ebx
// 005bfc31  c1e104               shl ecx, 4
// 005bfc34  51                   push ecx
// 005bfc35  c1e204               shl edx, 4
// 005bfc38  52                   push edx
// 005bfc39  55                   push ebp
// 005bfc3a  56                   push esi
// 005bfc3b  e860d70300           call 0x5fd3a0
// 005bfc40  83c410               add esp, 0x10
// 005bfc43  eb09                 jmp 0x5bfc4e
// 005bfc45  56                   push esi
// 005bfc46  e835d70300           call 0x5fd380
// 005bfc4b  83c404               add esp, 4
// 005bfc4e  c1e704               shl edi, 4
// 005bfc51  03f8                 add edi, eax
// 005bfc53  897e1c               mov dword ptr [esi + 0x1c], edi
// 005bfc56  5f                   pop edi
// 005bfc57  895e2c               mov dword ptr [esi + 0x2c], ebx
// 005bfc5a  894620               mov dword ptr [esi + 0x20], eax
// 005bfc5d  8bce                 mov ecx, esi
// 005bfc5f  5e                   pop esi
// 005bfc60  8bd5                 mov edx, ebp
// 005bfc62  5d                   pop ebp
// 005bfc63  5b                   pop ebx
// 005bfc64  e917ffffff           jmp 0x5bfb80
// library lua-5.1.1/ldo.c (function _luaD_reallocstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
