// from server: 100% by auto
// roc 2007-03 005c2fb0  unit: seg_005c0000  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2fb0
//
// 005c2fb0  83ec3c               sub esp, 0x3c
// 005c2fb3  56                   push esi
// 005c2fb4  8b7714               mov esi, dword ptr [edi + 0x14]
// 005c2fb7  8b4604               mov eax, dword ptr [esi + 4]
// 005c2fba  83780806             cmp dword ptr [eax + 8], 6
// 005c2fbe  7559                 jne 0x5c3019
// 005c2fc0  8b00                 mov eax, dword ptr [eax]
// 005c2fc2  80780600             cmp byte ptr [eax + 6], 0
// 005c2fc6  7551                 jne 0x5c3019
// 005c2fc8  53                   push ebx
// 005c2fc9  8bc6                 mov eax, esi
// 005c2fcb  8bd7                 mov edx, edi
// 005c2fcd  e89ef6ffff           call 0x5c2670
// 005c2fd2  8b7604               mov esi, dword ptr [esi + 4]
// 005c2fd5  837e0806             cmp dword ptr [esi + 8], 6
// 005c2fd9  8bd8                 mov ebx, eax
// 005c2fdb  750d                 jne 0x5c2fea
// 005c2fdd  8b36                 mov esi, dword ptr [esi]
// 005c2fdf  807e0600             cmp byte ptr [esi + 6], 0
// 005c2fe3  7505                 jne 0x5c2fea
// 005c2fe5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005c2fe8  eb02                 jmp 0x5c2fec
// 005c2fea  33c0                 xor eax, eax
// 005c2fec  8b4820               mov ecx, dword ptr [eax + 0x20]
// 005c2fef  6a3c                 push 0x3c
// 005c2ff1  83c110               add ecx, 0x10
// 005c2ff4  51                   push ecx
// 005c2ff5  8d542410             lea edx, [esp + 0x10]
// 005c2ff9  52                   push edx
// 005c2ffa  e861580300           call 0x5f8860
// 005c2fff  8b442454             mov eax, dword ptr [esp + 0x54]
// 005c3003  50                   push eax
// 005c3004  53                   push ebx
// 005c3005  8d4c241c             lea ecx, [esp + 0x1c]
// 005c3009  51                   push ecx
// 005c300a  686c9a7b00           push 0x7b9a6c
// 005c300f  57                   push edi
// 005c3010  e82b580300           call 0x5f8840
// 005c3015  83c420               add esp, 0x20
// 005c3018  5b                   pop ebx
// 005c3019  5e                   pop esi
// 005c301a  83c43c               add esp, 0x3c
// 005c301d  c3                   ret 
// library lua-5.1.1/ldebug.c (function _addinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
