// from server: 100% by auto
// roc 2011-06 00762df0  unit: seg_00760000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762df0
//
// 00762df0  8b442408             mov eax, dword ptr [esp + 8]
// 00762df4  83ec10               sub esp, 0x10
// 00762df7  53                   push ebx
// 00762df8  56                   push esi
// 00762df9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00762dfd  57                   push edi
// 00762dfe  8bce                 mov ecx, esi
// 00762e00  e8abf3ffff           call 0x7621b0
// 00762e05  8b542428             mov edx, dword ptr [esp + 0x28]
// 00762e09  8bf8                 mov edi, eax
// 00762e0b  8bc2                 mov eax, edx
// 00762e0d  8d5801               lea ebx, [eax + 1]
// 00762e10  8a08                 mov cl, byte ptr [eax]
// 00762e12  40                   inc eax
// 00762e13  84c9                 test cl, cl
// 00762e15  75f9                 jne 0x762e10
// 00762e17  2bc3                 sub eax, ebx
// 00762e19  50                   push eax
// 00762e1a  52                   push edx
// 00762e1b  56                   push esi
// 00762e1c  e8ff730700           call 0x7da220
// 00762e21  89442418             mov dword ptr [esp + 0x18], eax
// 00762e25  8b4608               mov eax, dword ptr [esi + 8]
// 00762e28  83e810               sub eax, 0x10
// 00762e2b  50                   push eax
// 00762e2c  8d4c241c             lea ecx, [esp + 0x1c]
// 00762e30  51                   push ecx
// 00762e31  57                   push edi
// 00762e32  56                   push esi
// 00762e33  c744243004000000     mov dword ptr [esp + 0x30], 4
// 00762e3b  e8c0490700           call 0x7d7800
// 00762e40  83c41c               add esp, 0x1c
// 00762e43  834608f0             add dword ptr [esi + 8], -0x10
// 00762e47  5f                   pop edi
// 00762e48  5e                   pop esi
// 00762e49  5b                   pop ebx
// 00762e4a  83c410               add esp, 0x10
// 00762e4d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
