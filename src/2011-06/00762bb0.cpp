// from server: 100% by auto
// roc 2011-06 00762bb0  unit: seg_00760000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762bb0
//
// 00762bb0  8b442408             mov eax, dword ptr [esp + 8]
// 00762bb4  83ec10               sub esp, 0x10
// 00762bb7  53                   push ebx
// 00762bb8  56                   push esi
// 00762bb9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00762bbd  57                   push edi
// 00762bbe  8bce                 mov ecx, esi
// 00762bc0  e8ebf5ffff           call 0x7621b0
// 00762bc5  8b542428             mov edx, dword ptr [esp + 0x28]
// 00762bc9  8bf8                 mov edi, eax
// 00762bcb  8bc2                 mov eax, edx
// 00762bcd  8d5801               lea ebx, [eax + 1]
// 00762bd0  8a08                 mov cl, byte ptr [eax]
// 00762bd2  40                   inc eax
// 00762bd3  84c9                 test cl, cl
// 00762bd5  75f9                 jne 0x762bd0
// 00762bd7  2bc3                 sub eax, ebx
// 00762bd9  50                   push eax
// 00762bda  52                   push edx
// 00762bdb  56                   push esi
// 00762bdc  e83f760700           call 0x7da220
// 00762be1  89442418             mov dword ptr [esp + 0x18], eax
// 00762be5  8b4608               mov eax, dword ptr [esi + 8]
// 00762be8  50                   push eax
// 00762be9  8d4c241c             lea ecx, [esp + 0x1c]
// 00762bed  51                   push ecx
// 00762bee  57                   push edi
// 00762bef  56                   push esi
// 00762bf0  c744243004000000     mov dword ptr [esp + 0x30], 4
// 00762bf8  e8134b0700           call 0x7d7710
// 00762bfd  83c41c               add esp, 0x1c
// 00762c00  83460810             add dword ptr [esi + 8], 0x10
// 00762c04  5f                   pop edi
// 00762c05  5e                   pop esi
// 00762c06  5b                   pop ebx
// 00762c07  83c410               add esp, 0x10
// 00762c0a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
