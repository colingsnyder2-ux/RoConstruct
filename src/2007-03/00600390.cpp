// from server: 100% by auto
// roc 2007-03 00600390  unit: seg_00600000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600390
//
// 00600390  51                   push ecx
// 00600391  8b4e04               mov ecx, dword ptr [esi + 4]
// 00600394  6a04                 push 4
// 00600396  8d442404             lea eax, [esp + 4]
// 0060039a  50                   push eax
// 0060039b  51                   push ecx
// 0060039c  e8cfc9ffff           call 0x5fcd70
// 006003a1  83c40c               add esp, 0xc
// 006003a4  85c0                 test eax, eax
// 006003a6  7423                 je 0x6003cb
// 006003a8  8b560c               mov edx, dword ptr [esi + 0xc]
// 006003ab  8b06                 mov eax, dword ptr [esi]
// 006003ad  6898067c00           push 0x7c0698
// 006003b2  52                   push edx
// 006003b3  687c067c00           push 0x7c067c
// 006003b8  50                   push eax
// 006003b9  e88284ffff           call 0x5f8840
// 006003be  8b0e                 mov ecx, dword ptr [esi]
// 006003c0  6a03                 push 3
// 006003c2  51                   push ecx
// 006003c3  e838fefbff           call 0x5c0200
// 006003c8  83c418               add esp, 0x18
// 006003cb  8b0424               mov eax, dword ptr [esp]
// 006003ce  85c0                 test eax, eax
// 006003d0  7502                 jne 0x6003d4
// 006003d2  59                   pop ecx
// 006003d3  c3                   ret 
// 006003d4  8b5608               mov edx, dword ptr [esi + 8]
// 006003d7  57                   push edi
// 006003d8  50                   push eax
// 006003d9  8b06                 mov eax, dword ptr [esi]
// 006003db  52                   push edx
// 006003dc  50                   push eax
// 006003dd  e82ecaffff           call 0x5fce10
// 006003e2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006003e6  8b5604               mov edx, dword ptr [esi + 4]
// 006003e9  51                   push ecx
// 006003ea  8bf8                 mov edi, eax
// 006003ec  57                   push edi
// 006003ed  52                   push edx
// 006003ee  e87dc9ffff           call 0x5fcd70
// 006003f3  83c418               add esp, 0x18
// 006003f6  85c0                 test eax, eax
// 006003f8  7423                 je 0x60041d
// 006003fa  8b460c               mov eax, dword ptr [esi + 0xc]
// 006003fd  8b0e                 mov ecx, dword ptr [esi]
// 006003ff  6898067c00           push 0x7c0698
// 00600404  50                   push eax
// 00600405  687c067c00           push 0x7c067c
// 0060040a  51                   push ecx
// 0060040b  e83084ffff           call 0x5f8840
// 00600410  8b16                 mov edx, dword ptr [esi]
// 00600412  6a03                 push 3
// 00600414  52                   push edx
// 00600415  e8e6fdfbff           call 0x5c0200
// 0060041a  83c418               add esp, 0x18
// 0060041d  8b442404             mov eax, dword ptr [esp + 4]
// 00600421  8b0e                 mov ecx, dword ptr [esi]
// 00600423  83c0ff               add eax, -1
// 00600426  50                   push eax
// 00600427  57                   push edi
// 00600428  51                   push ecx
// 00600429  e8f2c2ffff           call 0x5fc720
// 0060042e  83c40c               add esp, 0xc
// 00600431  5f                   pop edi
// 00600432  59                   pop ecx
// 00600433  c3                   ret 
// library lua-5.1.1/lundump.c (function _LoadString)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lundump.c
