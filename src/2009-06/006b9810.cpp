// from server: 100% by auto
// roc 2009-06 006b9810  unit: RBX::UniversalTool  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9810
//
// 006b9810  8b442408             mov eax, dword ptr [esp + 8]
// 006b9814  83ec10               sub esp, 0x10
// 006b9817  53                   push ebx
// 006b9818  56                   push esi
// 006b9819  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006b981d  57                   push edi
// 006b981e  8bce                 mov ecx, esi
// 006b9820  e8abf3ffff           call 0x6b8bd0
// 006b9825  8b542428             mov edx, dword ptr [esp + 0x28]
// 006b9829  8bf8                 mov edi, eax
// 006b982b  8bc2                 mov eax, edx
// 006b982d  8d5801               lea ebx, [eax + 1]
// 006b9830  8a08                 mov cl, byte ptr [eax]
// 006b9832  40                   inc eax
// 006b9833  84c9                 test cl, cl
// 006b9835  75f9                 jne 0x6b9830
// 006b9837  2bc3                 sub eax, ebx
// 006b9839  50                   push eax
// 006b983a  52                   push edx
// 006b983b  56                   push esi
// 006b983c  e8ff320300           call 0x6ecb40
// 006b9841  89442418             mov dword ptr [esp + 0x18], eax
// 006b9845  8b4608               mov eax, dword ptr [esi + 8]
// 006b9848  83e810               sub eax, 0x10
// 006b984b  50                   push eax
// 006b984c  8d4c241c             lea ecx, [esp + 0x1c]
// 006b9850  51                   push ecx
// 006b9851  57                   push edi
// 006b9852  56                   push esi
// 006b9853  c744243004000000     mov dword ptr [esp + 0x30], 4
// 006b985b  e8a0090300           call 0x6ea200
// 006b9860  83c41c               add esp, 0x1c
// 006b9863  834608f0             add dword ptr [esi + 8], -0x10
// 006b9867  5f                   pop edi
// 006b9868  5e                   pop esi
// 006b9869  5b                   pop ebx
// 006b986a  83c410               add esp, 0x10
// 006b986d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
