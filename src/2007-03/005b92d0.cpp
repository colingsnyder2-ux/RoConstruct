// from server: 100% by auto
// roc 2007-03 005b92d0  unit: seg_005b0000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b92d0
//
// 005b92d0  8b442408             mov eax, dword ptr [esp + 8]
// 005b92d4  83ec10               sub esp, 0x10
// 005b92d7  53                   push ebx
// 005b92d8  56                   push esi
// 005b92d9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005b92dd  57                   push edi
// 005b92de  8bce                 mov ecx, esi
// 005b92e0  e8cbf5ffff           call 0x5b88b0
// 005b92e5  8b542428             mov edx, dword ptr [esp + 0x28]
// 005b92e9  8bf8                 mov edi, eax
// 005b92eb  8bc2                 mov eax, edx
// 005b92ed  8d5801               lea ebx, [eax + 1]
// 005b92f0  8a08                 mov cl, byte ptr [eax]
// 005b92f2  83c001               add eax, 1
// 005b92f5  84c9                 test cl, cl
// 005b92f7  75f7                 jne 0x5b92f0
// 005b92f9  2bc3                 sub eax, ebx
// 005b92fb  50                   push eax
// 005b92fc  52                   push edx
// 005b92fd  56                   push esi
// 005b92fe  e81d340400           call 0x5fc720
// 005b9303  89442418             mov dword ptr [esp + 0x18], eax
// 005b9307  8b4608               mov eax, dword ptr [esi + 8]
// 005b930a  50                   push eax
// 005b930b  8d4c241c             lea ecx, [esp + 0x1c]
// 005b930f  51                   push ecx
// 005b9310  57                   push edi
// 005b9311  56                   push esi
// 005b9312  c744243004000000     mov dword ptr [esp + 0x30], 4
// 005b931a  e8e1090400           call 0x5f9d00
// 005b931f  83c41c               add esp, 0x1c
// 005b9322  83460810             add dword ptr [esi + 8], 0x10
// 005b9326  5f                   pop edi
// 005b9327  5e                   pop esi
// 005b9328  5b                   pop ebx
// 005b9329  83c410               add esp, 0x10
// 005b932c  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
