// from server: 100% by auto
// roc 2009-12 00797250  unit: lua_exception  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797250
//
// 00797250  53                   push ebx
// 00797251  55                   push ebp
// 00797252  56                   push esi
// 00797253  8b742410             mov esi, dword ptr [esp + 0x10]
// 00797257  8b6e20               mov ebp, dword ptr [esi + 0x20]
// 0079725a  57                   push edi
// 0079725b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0079725f  8d5f06               lea ebx, [edi + 6]
// 00797262  8d4301               lea eax, [ebx + 1]
// 00797265  3dffffff0f           cmp eax, 0xfffffff
// 0079726a  7719                 ja 0x797285
// 0079726c  8b562c               mov edx, dword ptr [esi + 0x2c]
// 0079726f  8bcb                 mov ecx, ebx
// 00797271  c1e104               shl ecx, 4
// 00797274  51                   push ecx
// 00797275  c1e204               shl edx, 4
// 00797278  52                   push edx
// 00797279  55                   push ebp
// 0079727a  56                   push esi
// 0079727b  e830a50300           call 0x7d17b0
// 00797280  83c410               add esp, 0x10
// 00797283  eb09                 jmp 0x79728e
// 00797285  56                   push esi
// 00797286  e805a50300           call 0x7d1790
// 0079728b  83c404               add esp, 4
// 0079728e  c1e704               shl edi, 4
// 00797291  03f8                 add edi, eax
// 00797293  897e1c               mov dword ptr [esi + 0x1c], edi
// 00797296  5f                   pop edi
// 00797297  895e2c               mov dword ptr [esi + 0x2c], ebx
// 0079729a  894620               mov dword ptr [esi + 0x20], eax
// 0079729d  8bce                 mov ecx, esi
// 0079729f  5e                   pop esi
// 007972a0  8bd5                 mov edx, ebp
// 007972a2  5d                   pop ebp
// 007972a3  5b                   pop ebx
// 007972a4  e917ffffff           jmp 0x7971c0
// library lua-5.1/ldo.c (function _luaD_reallocstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
