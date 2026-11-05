// from server: 100% by auto
// roc 2009-06 006ec450  unit: RBX::PartDropTool  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ec450
//
// 006ec450  53                   push ebx
// 006ec451  55                   push ebp
// 006ec452  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006ec456  56                   push esi
// 006ec457  8bf0                 mov esi, eax
// 006ec459  8bde                 mov ebx, esi
// 006ec45b  46                   inc esi
// 006ec45c  56                   push esi
// 006ec45d  55                   push ebp
// 006ec45e  e8adfdffff           call 0x6ec210
// 006ec463  83c408               add esp, 8
// 006ec466  83780800             cmp dword ptr [eax + 8], 0
// 006ec46a  7420                 je 0x6ec48c
// 006ec46c  8d642400             lea esp, [esp]
// 006ec470  8bde                 mov ebx, esi
// 006ec472  03f6                 add esi, esi
// 006ec474  81fefdffff7f         cmp esi, 0x7ffffffd
// 006ec47a  7733                 ja 0x6ec4af
// 006ec47c  56                   push esi
// 006ec47d  55                   push ebp
// 006ec47e  e88dfdffff           call 0x6ec210
// 006ec483  83c408               add esp, 8
// 006ec486  83780800             cmp dword ptr [eax + 8], 0
// 006ec48a  75e4                 jne 0x6ec470
// 006ec48c  8bc6                 mov eax, esi
// 006ec48e  2bc3                 sub eax, ebx
// 006ec490  83f801               cmp eax, 1
// 006ec493  7653                 jbe 0x6ec4e8
// 006ec495  57                   push edi
// 006ec496  8d3c33               lea edi, [ebx + esi]
// 006ec499  d1ef                 shr edi, 1
// 006ec49b  57                   push edi
// 006ec49c  55                   push ebp
// 006ec49d  e86efdffff           call 0x6ec210
// 006ec4a2  83c408               add esp, 8
// 006ec4a5  83780800             cmp dword ptr [eax + 8], 0
// 006ec4a9  7531                 jne 0x6ec4dc
// 006ec4ab  8bf7                 mov esi, edi
// 006ec4ad  eb2f                 jmp 0x6ec4de
// 006ec4af  be01000000           mov esi, 1
// 006ec4b4  56                   push esi
// 006ec4b5  55                   push ebp
// 006ec4b6  e855fdffff           call 0x6ec210
// 006ec4bb  83c408               add esp, 8
// 006ec4be  83780800             cmp dword ptr [eax + 8], 0
// 006ec4c2  7411                 je 0x6ec4d5
// 006ec4c4  46                   inc esi
// 006ec4c5  56                   push esi
// 006ec4c6  55                   push ebp
// 006ec4c7  e844fdffff           call 0x6ec210
// 006ec4cc  83c408               add esp, 8
// 006ec4cf  83780800             cmp dword ptr [eax + 8], 0
// 006ec4d3  75ef                 jne 0x6ec4c4
// 006ec4d5  8d46ff               lea eax, [esi - 1]
// 006ec4d8  5e                   pop esi
// 006ec4d9  5d                   pop ebp
// 006ec4da  5b                   pop ebx
// 006ec4db  c3                   ret 
// 006ec4dc  8bdf                 mov ebx, edi
// 006ec4de  8bce                 mov ecx, esi
// 006ec4e0  2bcb                 sub ecx, ebx
// 006ec4e2  83f901               cmp ecx, 1
// 006ec4e5  77af                 ja 0x6ec496
// 006ec4e7  5f                   pop edi
// 006ec4e8  5e                   pop esi
// 006ec4e9  5d                   pop ebp
// 006ec4ea  8bc3                 mov eax, ebx
// 006ec4ec  5b                   pop ebx
// 006ec4ed  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
