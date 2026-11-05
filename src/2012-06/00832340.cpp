// from server: 100% by auto
// roc 2012-06 00832340  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832340
//
// 00832340  8b442408             mov eax, dword ptr [esp + 8]
// 00832344  83ec10               sub esp, 0x10
// 00832347  53                   push ebx
// 00832348  56                   push esi
// 00832349  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0083234d  57                   push edi
// 0083234e  8bce                 mov ecx, esi
// 00832350  e8ebf5ffff           call 0x831940
// 00832355  8b542428             mov edx, dword ptr [esp + 0x28]
// 00832359  8bf8                 mov edi, eax
// 0083235b  8bc2                 mov eax, edx
// 0083235d  8d5801               lea ebx, [eax + 1]
// 00832360  8a08                 mov cl, byte ptr [eax]
// 00832362  40                   inc eax
// 00832363  84c9                 test cl, cl
// 00832365  75f9                 jne 0x832360
// 00832367  2bc3                 sub eax, ebx
// 00832369  50                   push eax
// 0083236a  52                   push edx
// 0083236b  56                   push esi
// 0083236c  e8bf3f1000           call 0x936330
// 00832371  89442418             mov dword ptr [esp + 0x18], eax
// 00832375  8b4608               mov eax, dword ptr [esi + 8]
// 00832378  50                   push eax
// 00832379  8d4c241c             lea ecx, [esp + 0x1c]
// 0083237d  51                   push ecx
// 0083237e  57                   push edi
// 0083237f  56                   push esi
// 00832380  c744243004000000     mov dword ptr [esp + 0x30], 4
// 00832388  e893141000           call 0x933820
// 0083238d  83c41c               add esp, 0x1c
// 00832390  83460810             add dword ptr [esi + 8], 0x10
// 00832394  5f                   pop edi
// 00832395  5e                   pop esi
// 00832396  5b                   pop ebx
// 00832397  83c410               add esp, 0x10
// 0083239a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
