// from server: 100% by auto
// roc 2009-06 006b95d0  unit: RBX::UniversalTool  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b95d0
//
// 006b95d0  8b442408             mov eax, dword ptr [esp + 8]
// 006b95d4  83ec10               sub esp, 0x10
// 006b95d7  53                   push ebx
// 006b95d8  56                   push esi
// 006b95d9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006b95dd  57                   push edi
// 006b95de  8bce                 mov ecx, esi
// 006b95e0  e8ebf5ffff           call 0x6b8bd0
// 006b95e5  8b542428             mov edx, dword ptr [esp + 0x28]
// 006b95e9  8bf8                 mov edi, eax
// 006b95eb  8bc2                 mov eax, edx
// 006b95ed  8d5801               lea ebx, [eax + 1]
// 006b95f0  8a08                 mov cl, byte ptr [eax]
// 006b95f2  40                   inc eax
// 006b95f3  84c9                 test cl, cl
// 006b95f5  75f9                 jne 0x6b95f0
// 006b95f7  2bc3                 sub eax, ebx
// 006b95f9  50                   push eax
// 006b95fa  52                   push edx
// 006b95fb  56                   push esi
// 006b95fc  e83f350300           call 0x6ecb40
// 006b9601  89442418             mov dword ptr [esp + 0x18], eax
// 006b9605  8b4608               mov eax, dword ptr [esi + 8]
// 006b9608  50                   push eax
// 006b9609  8d4c241c             lea ecx, [esp + 0x1c]
// 006b960d  51                   push ecx
// 006b960e  57                   push edi
// 006b960f  56                   push esi
// 006b9610  c744243004000000     mov dword ptr [esp + 0x30], 4
// 006b9618  e8f30a0300           call 0x6ea110
// 006b961d  83c41c               add esp, 0x1c
// 006b9620  83460810             add dword ptr [esi + 8], 0x10
// 006b9624  5f                   pop edi
// 006b9625  5e                   pop esi
// 006b9626  5b                   pop ebx
// 006b9627  83c410               add esp, 0x10
// 006b962a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
