// from server: 100% by auto
// roc 2009-12 00788ff0  unit: RBX::UniversalTool  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788ff0
//
// 00788ff0  8b442408             mov eax, dword ptr [esp + 8]
// 00788ff4  83ec10               sub esp, 0x10
// 00788ff7  53                   push ebx
// 00788ff8  56                   push esi
// 00788ff9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00788ffd  57                   push edi
// 00788ffe  8bce                 mov ecx, esi
// 00789000  e8ebf5ffff           call 0x7885f0
// 00789005  8b542428             mov edx, dword ptr [esp + 0x28]
// 00789009  8bf8                 mov edi, eax
// 0078900b  8bc2                 mov eax, edx
// 0078900d  8d5801               lea ebx, [eax + 1]
// 00789010  8a08                 mov cl, byte ptr [eax]
// 00789012  40                   inc eax
// 00789013  84c9                 test cl, cl
// 00789015  75f9                 jne 0x789010
// 00789017  2bc3                 sub eax, ebx
// 00789019  50                   push eax
// 0078901a  52                   push edx
// 0078901b  56                   push esi
// 0078901c  e86f7b0400           call 0x7d0b90
// 00789021  89442418             mov dword ptr [esp + 0x18], eax
// 00789025  8b4608               mov eax, dword ptr [esi + 8]
// 00789028  50                   push eax
// 00789029  8d4c241c             lea ecx, [esp + 0x1c]
// 0078902d  51                   push ecx
// 0078902e  57                   push edi
// 0078902f  56                   push esi
// 00789030  c744243004000000     mov dword ptr [esp + 0x30], 4
// 00789038  e823510400           call 0x7ce160
// 0078903d  83c41c               add esp, 0x1c
// 00789040  83460810             add dword ptr [esi + 8], 0x10
// 00789044  5f                   pop edi
// 00789045  5e                   pop esi
// 00789046  5b                   pop ebx
// 00789047  83c410               add esp, 0x10
// 0078904a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
