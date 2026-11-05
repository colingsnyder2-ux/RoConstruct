// from server: 100% by auto
// roc 2009-12 0078a580  unit: RBX::UniversalTool  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a580
//
// 0078a580  83ec64               sub esp, 0x64
// 0078a583  56                   push esi
// 0078a584  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0078a588  8d442404             lea eax, [esp + 4]
// 0078a58c  50                   push eax
// 0078a58d  6a00                 push 0
// 0078a58f  56                   push esi
// 0078a590  e80b020100           call 0x79a7a0
// 0078a595  83c40c               add esp, 0xc
// 0078a598  85c0                 test eax, eax
// 0078a59a  751d                 jne 0x78a5b9
// 0078a59c  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0078a5a0  8b542470             mov edx, dword ptr [esp + 0x70]
// 0078a5a4  51                   push ecx
// 0078a5a5  52                   push edx
// 0078a5a6  68909d9e00           push 0x9e9d90
// 0078a5ab  56                   push esi
// 0078a5ac  e83ff7ffff           call 0x789cf0
// 0078a5b1  83c410               add esp, 0x10
// 0078a5b4  5e                   pop esi
// 0078a5b5  83c464               add esp, 0x64
// 0078a5b8  c3                   ret 
// 0078a5b9  8d442404             lea eax, [esp + 4]
// 0078a5bd  50                   push eax
// 0078a5be  6810249a00           push 0x9a2410
// 0078a5c3  56                   push esi
// 0078a5c4  e8f70e0100           call 0x79b4c0
// 0078a5c9  8b442418             mov eax, dword ptr [esp + 0x18]
// 0078a5cd  83c40c               add esp, 0xc
// 0078a5d0  b9889d9e00           mov ecx, 0x9e9d88
// 0078a5d5  8a10                 mov dl, byte ptr [eax]
// 0078a5d7  3a11                 cmp dl, byte ptr [ecx]
// 0078a5d9  751a                 jne 0x78a5f5
// 0078a5db  84d2                 test dl, dl
// 0078a5dd  7412                 je 0x78a5f1
// 0078a5df  8a5001               mov dl, byte ptr [eax + 1]
// 0078a5e2  3a5101               cmp dl, byte ptr [ecx + 1]
// 0078a5e5  750e                 jne 0x78a5f5
// 0078a5e7  83c002               add eax, 2
// 0078a5ea  83c102               add ecx, 2
// 0078a5ed  84d2                 test dl, dl
// 0078a5ef  75e4                 jne 0x78a5d5
// 0078a5f1  33c0                 xor eax, eax
// 0078a5f3  eb05                 jmp 0x78a5fa
// 0078a5f5  1bc0                 sbb eax, eax
// 0078a5f7  83d8ff               sbb eax, -1
// 0078a5fa  85c0                 test eax, eax
// 0078a5fc  7524                 jne 0x78a622
// 0078a5fe  836c247001           sub dword ptr [esp + 0x70], 1
// 0078a603  751d                 jne 0x78a622
// 0078a605  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0078a609  8b542408             mov edx, dword ptr [esp + 8]
// 0078a60d  51                   push ecx
// 0078a60e  52                   push edx
// 0078a60f  68689d9e00           push 0x9e9d68
// 0078a614  56                   push esi
// 0078a615  e8d6f6ffff           call 0x789cf0
// 0078a61a  83c410               add esp, 0x10
// 0078a61d  5e                   pop esi
// 0078a61e  83c464               add esp, 0x64
// 0078a621  c3                   ret 
// 0078a622  8b442408             mov eax, dword ptr [esp + 8]
// 0078a626  85c0                 test eax, eax
// 0078a628  7509                 jne 0x78a633
// 0078a62a  b8d0d99b00           mov eax, 0x9bd9d0
// 0078a62f  89442408             mov dword ptr [esp + 8], eax
// 0078a633  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0078a637  8b542470             mov edx, dword ptr [esp + 0x70]
// 0078a63b  51                   push ecx
// 0078a63c  50                   push eax
// 0078a63d  52                   push edx
// 0078a63e  68489d9e00           push 0x9e9d48
// 0078a643  56                   push esi
// 0078a644  e8a7f6ffff           call 0x789cf0
// 0078a649  83c414               add esp, 0x14
// 0078a64c  5e                   pop esi
// 0078a64d  83c464               add esp, 0x64
// 0078a650  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_argerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
