// from server: 100% by auto
// roc 2007-03 005b94f0  unit: seg_005b0000  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b94f0
//
// 005b94f0  8b442408             mov eax, dword ptr [esp + 8]
// 005b94f4  83ec10               sub esp, 0x10
// 005b94f7  53                   push ebx
// 005b94f8  56                   push esi
// 005b94f9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005b94fd  57                   push edi
// 005b94fe  8bce                 mov ecx, esi
// 005b9500  e8abf3ffff           call 0x5b88b0
// 005b9505  8b542428             mov edx, dword ptr [esp + 0x28]
// 005b9509  8bf8                 mov edi, eax
// 005b950b  8bc2                 mov eax, edx
// 005b950d  8d5801               lea ebx, [eax + 1]
// 005b9510  8a08                 mov cl, byte ptr [eax]
// 005b9512  83c001               add eax, 1
// 005b9515  84c9                 test cl, cl
// 005b9517  75f7                 jne 0x5b9510
// 005b9519  2bc3                 sub eax, ebx
// 005b951b  50                   push eax
// 005b951c  52                   push edx
// 005b951d  56                   push esi
// 005b951e  e8fd310400           call 0x5fc720
// 005b9523  89442418             mov dword ptr [esp + 0x18], eax
// 005b9527  8b4608               mov eax, dword ptr [esi + 8]
// 005b952a  83e810               sub eax, 0x10
// 005b952d  50                   push eax
// 005b952e  8d4c241c             lea ecx, [esp + 0x1c]
// 005b9532  51                   push ecx
// 005b9533  57                   push edi
// 005b9534  56                   push esi
// 005b9535  c744243004000000     mov dword ptr [esp + 0x30], 4
// 005b953d  e8ae080400           call 0x5f9df0
// 005b9542  83c41c               add esp, 0x1c
// 005b9545  834608f0             add dword ptr [esi + 8], -0x10
// 005b9549  5f                   pop edi
// 005b954a  5e                   pop esi
// 005b954b  5b                   pop ebx
// 005b954c  83c410               add esp, 0x10
// 005b954f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
