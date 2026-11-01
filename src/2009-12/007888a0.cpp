// from server: 100% by auto
// roc 2009-12 007888a0  unit: RBX::UniversalTool  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007888a0
//
// 007888a0  56                   push esi
// 007888a1  8b742408             mov esi, dword ptr [esp + 8]
// 007888a5  57                   push edi
// 007888a6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007888aa  81ffefd8ffff         cmp edi, 0xffffd8ef
// 007888b0  7516                 jne 0x7888c8
// 007888b2  8b4614               mov eax, dword ptr [esi + 0x14]
// 007888b5  3b4628               cmp eax, dword ptr [esi + 0x28]
// 007888b8  750e                 jne 0x7888c8
// 007888ba  68989c9e00           push 0x9e9c98
// 007888bf  56                   push esi
// 007888c0  e87b2a0100           call 0x79b340
// 007888c5  83c408               add esp, 8
// 007888c8  8bc7                 mov eax, edi
// 007888ca  8bce                 mov ecx, esi
// 007888cc  e81ffdffff           call 0x7885f0
// 007888d1  81ffefd8ffff         cmp edi, 0xffffd8ef
// 007888d7  7529                 jne 0x788902
// 007888d9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007888dc  8b5104               mov edx, dword ptr [ecx + 4]
// 007888df  8b4e08               mov ecx, dword ptr [esi + 8]
// 007888e2  8b02                 mov eax, dword ptr [edx]
// 007888e4  8b51f0               mov edx, dword ptr [ecx - 0x10]
// 007888e7  89500c               mov dword ptr [eax + 0xc], edx
// 007888ea  8b4e08               mov ecx, dword ptr [esi + 8]
// 007888ed  ba04000000           mov edx, 4
// 007888f2  3951f8               cmp dword ptr [ecx - 8], edx
// 007888f5  7c58                 jl 0x78894f
// 007888f7  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 007888fa  f6410503             test byte ptr [ecx + 5], 3
// 007888fe  744f                 je 0x78894f
// 00788900  eb3d                 jmp 0x78893f
// 00788902  8b4e08               mov ecx, dword ptr [esi + 8]
// 00788905  8b51f0               mov edx, dword ptr [ecx - 0x10]
// 00788908  83e910               sub ecx, 0x10
// 0078890b  81ffeed8ffff         cmp edi, 0xffffd8ee
// 00788911  8910                 mov dword ptr [eax], edx
// 00788913  8b5104               mov edx, dword ptr [ecx + 4]
// 00788916  895004               mov dword ptr [eax + 4], edx
// 00788919  8b4908               mov ecx, dword ptr [ecx + 8]
// 0078891c  894808               mov dword ptr [eax + 8], ecx
// 0078891f  7d2e                 jge 0x78894f
// 00788921  8b4608               mov eax, dword ptr [esi + 8]
// 00788924  ba04000000           mov edx, 4
// 00788929  3950f8               cmp dword ptr [eax - 8], edx
// 0078892c  7c21                 jl 0x78894f
// 0078892e  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 00788931  f6410503             test byte ptr [ecx + 5], 3
// 00788935  7418                 je 0x78894f
// 00788937  8b4614               mov eax, dword ptr [esi + 0x14]
// 0078893a  8b4004               mov eax, dword ptr [eax + 4]
// 0078893d  8b00                 mov eax, dword ptr [eax]
// 0078893f  845005               test byte ptr [eax + 5], dl
// 00788942  740b                 je 0x78894f
// 00788944  51                   push ecx
// 00788945  50                   push eax
// 00788946  56                   push esi
// 00788947  e8b4530400           call 0x7cdd00
// 0078894c  83c40c               add esp, 0xc
// 0078894f  834608f0             add dword ptr [esi + 8], -0x10
// 00788953  5f                   pop edi
// 00788954  5e                   pop esi
// 00788955  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_replace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
