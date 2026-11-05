// from server: 100% by auto
// roc 2010-06 007219e0  unit: RBX::UniversalTool  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007219e0
//
// 007219e0  8b442408             mov eax, dword ptr [esp + 8]
// 007219e4  83ec10               sub esp, 0x10
// 007219e7  53                   push ebx
// 007219e8  56                   push esi
// 007219e9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007219ed  57                   push edi
// 007219ee  8bce                 mov ecx, esi
// 007219f0  e8abf3ffff           call 0x720da0
// 007219f5  8b542428             mov edx, dword ptr [esp + 0x28]
// 007219f9  8bf8                 mov edi, eax
// 007219fb  8bc2                 mov eax, edx
// 007219fd  8d5801               lea ebx, [eax + 1]
// 00721a00  8a08                 mov cl, byte ptr [eax]
// 00721a02  40                   inc eax
// 00721a03  84c9                 test cl, cl
// 00721a05  75f9                 jne 0x721a00
// 00721a07  2bc3                 sub eax, ebx
// 00721a09  50                   push eax
// 00721a0a  52                   push edx
// 00721a0b  56                   push esi
// 00721a0c  e8cfc30500           call 0x77dde0
// 00721a11  89442418             mov dword ptr [esp + 0x18], eax
// 00721a15  8b4608               mov eax, dword ptr [esi + 8]
// 00721a18  83e810               sub eax, 0x10
// 00721a1b  50                   push eax
// 00721a1c  8d4c241c             lea ecx, [esp + 0x1c]
// 00721a20  51                   push ecx
// 00721a21  57                   push edi
// 00721a22  56                   push esi
// 00721a23  c744243004000000     mov dword ptr [esp + 0x30], 4
// 00721a2b  e8709a0500           call 0x77b4a0
// 00721a30  83c41c               add esp, 0x1c
// 00721a33  834608f0             add dword ptr [esi + 8], -0x10
// 00721a37  5f                   pop edi
// 00721a38  5e                   pop esi
// 00721a39  5b                   pop ebx
// 00721a3a  83c410               add esp, 0x10
// 00721a3d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
