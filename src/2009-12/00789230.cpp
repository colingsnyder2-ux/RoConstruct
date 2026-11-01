// from server: 100% by auto
// roc 2009-12 00789230  unit: RBX::UniversalTool  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789230
//
// 00789230  8b442408             mov eax, dword ptr [esp + 8]
// 00789234  83ec10               sub esp, 0x10
// 00789237  53                   push ebx
// 00789238  56                   push esi
// 00789239  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0078923d  57                   push edi
// 0078923e  8bce                 mov ecx, esi
// 00789240  e8abf3ffff           call 0x7885f0
// 00789245  8b542428             mov edx, dword ptr [esp + 0x28]
// 00789249  8bf8                 mov edi, eax
// 0078924b  8bc2                 mov eax, edx
// 0078924d  8d5801               lea ebx, [eax + 1]
// 00789250  8a08                 mov cl, byte ptr [eax]
// 00789252  40                   inc eax
// 00789253  84c9                 test cl, cl
// 00789255  75f9                 jne 0x789250
// 00789257  2bc3                 sub eax, ebx
// 00789259  50                   push eax
// 0078925a  52                   push edx
// 0078925b  56                   push esi
// 0078925c  e82f790400           call 0x7d0b90
// 00789261  89442418             mov dword ptr [esp + 0x18], eax
// 00789265  8b4608               mov eax, dword ptr [esi + 8]
// 00789268  83e810               sub eax, 0x10
// 0078926b  50                   push eax
// 0078926c  8d4c241c             lea ecx, [esp + 0x1c]
// 00789270  51                   push ecx
// 00789271  57                   push edi
// 00789272  56                   push esi
// 00789273  c744243004000000     mov dword ptr [esp + 0x30], 4
// 0078927b  e8d04f0400           call 0x7ce250
// 00789280  83c41c               add esp, 0x1c
// 00789283  834608f0             add dword ptr [esi + 8], -0x10
// 00789287  5f                   pop edi
// 00789288  5e                   pop esi
// 00789289  5b                   pop ebx
// 0078928a  83c410               add esp, 0x10
// 0078928d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
