// from server: 100% by auto
// roc 2009-12 0079b240  unit: seg_00790000  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b240
//
// 0079b240  83ec3c               sub esp, 0x3c
// 0079b243  56                   push esi
// 0079b244  8b7714               mov esi, dword ptr [edi + 0x14]
// 0079b247  8b4604               mov eax, dword ptr [esi + 4]
// 0079b24a  83780806             cmp dword ptr [eax + 8], 6
// 0079b24e  7559                 jne 0x79b2a9
// 0079b250  8b00                 mov eax, dword ptr [eax]
// 0079b252  80780600             cmp byte ptr [eax + 6], 0
// 0079b256  7551                 jne 0x79b2a9
// 0079b258  53                   push ebx
// 0079b259  8bc6                 mov eax, esi
// 0079b25b  8bd7                 mov edx, edi
// 0079b25d  e88ef4ffff           call 0x79a6f0
// 0079b262  8b7604               mov esi, dword ptr [esi + 4]
// 0079b265  837e0806             cmp dword ptr [esi + 8], 6
// 0079b269  8bd8                 mov ebx, eax
// 0079b26b  750d                 jne 0x79b27a
// 0079b26d  8b36                 mov esi, dword ptr [esi]
// 0079b26f  807e0600             cmp byte ptr [esi + 6], 0
// 0079b273  7505                 jne 0x79b27a
// 0079b275  8b4610               mov eax, dword ptr [esi + 0x10]
// 0079b278  eb02                 jmp 0x79b27c
// 0079b27a  33c0                 xor eax, eax
// 0079b27c  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0079b27f  6a3c                 push 0x3c
// 0079b281  83c110               add ecx, 0x10
// 0079b284  51                   push ecx
// 0079b285  8d542410             lea edx, [esp + 0x10]
// 0079b289  52                   push edx
// 0079b28a  e811f3ffff           call 0x79a5a0
// 0079b28f  8b442454             mov eax, dword ptr [esp + 0x54]
// 0079b293  50                   push eax
// 0079b294  53                   push ebx
// 0079b295  8d4c241c             lea ecx, [esp + 0x1c]
// 0079b299  51                   push ecx
// 0079b29a  68b4ab9e00           push 0x9eabb4
// 0079b29f  57                   push edi
// 0079b2a0  e8dbf2ffff           call 0x79a580
// 0079b2a5  83c420               add esp, 0x20
// 0079b2a8  5b                   pop ebx
// 0079b2a9  5e                   pop esi
// 0079b2aa  83c43c               add esp, 0x3c
// 0079b2ad  c3                   ret 
// library lua-5.1/ldebug.c (function _addinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
