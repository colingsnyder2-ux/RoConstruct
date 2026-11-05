// from server: 100% by auto
// roc 2007-08 0060f960  unit: RBX::Ball  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060f960
//
// 0060f960  51                   push ecx
// 0060f961  55                   push ebp
// 0060f962  57                   push edi
// 0060f963  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0060f966  8b4730               mov eax, dword ptr [edi + 0x30]
// 0060f969  8b28                 mov ebp, dword ptr [eax]
// 0060f96b  3be8                 cmp ebp, eax
// 0060f96d  7509                 jne 0x60f978
// 0060f96f  c7473000000000       mov dword ptr [edi + 0x30], 0
// 0060f976  eb05                 jmp 0x60f97d
// 0060f978  8b4d00               mov ecx, dword ptr [ebp]
// 0060f97b  8908                 mov dword ptr [eax], ecx
// 0060f97d  8b5770               mov edx, dword ptr [edi + 0x70]
// 0060f980  8b02                 mov eax, dword ptr [edx]
// 0060f982  894500               mov dword ptr [ebp], eax
// 0060f985  8b4f70               mov ecx, dword ptr [edi + 0x70]
// 0060f988  8929                 mov dword ptr [ecx], ebp
// 0060f98a  8a4505               mov al, byte ptr [ebp + 5]
// 0060f98d  8a5714               mov dl, byte ptr [edi + 0x14]
// 0060f990  24f8                 and al, 0xf8
// 0060f992  80e203               and dl, 3
// 0060f995  0ad0                 or dl, al
// 0060f997  8b4508               mov eax, dword ptr [ebp + 8]
// 0060f99a  85c0                 test eax, eax
// 0060f99c  885505               mov byte ptr [ebp + 5], dl
// 0060f99f  7479                 je 0x60fa1a
// 0060f9a1  f6400604             test byte ptr [eax + 6], 4
// 0060f9a5  7573                 jne 0x60fa1a
// 0060f9a7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0060f9aa  8b91c4000000         mov edx, dword ptr [ecx + 0xc4]
// 0060f9b0  52                   push edx
// 0060f9b1  6a02                 push 2
// 0060f9b3  50                   push eax
// 0060f9b4  e887060000           call 0x610040
// 0060f9b9  83c40c               add esp, 0xc
// 0060f9bc  85c0                 test eax, eax
// 0060f9be  745a                 je 0x60fa1a
// 0060f9c0  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 0060f9c3  53                   push ebx
// 0060f9c4  8a5e37               mov bl, byte ptr [esi + 0x37]
// 0060f9c7  c6463700             mov byte ptr [esi + 0x37], 0
// 0060f9cb  8b5744               mov edx, dword ptr [edi + 0x44]
// 0060f9ce  03d2                 add edx, edx
// 0060f9d0  895740               mov dword ptr [edi + 0x40], edx
// 0060f9d3  8b10                 mov edx, dword ptr [eax]
// 0060f9d5  894c240c             mov dword ptr [esp + 0xc], ecx
// 0060f9d9  8b4e08               mov ecx, dword ptr [esi + 8]
// 0060f9dc  8911                 mov dword ptr [ecx], edx
// 0060f9de  8b5004               mov edx, dword ptr [eax + 4]
// 0060f9e1  895104               mov dword ptr [ecx + 4], edx
// 0060f9e4  8b4008               mov eax, dword ptr [eax + 8]
// 0060f9e7  894108               mov dword ptr [ecx + 8], eax
// 0060f9ea  8b4608               mov eax, dword ptr [esi + 8]
// 0060f9ed  83c010               add eax, 0x10
// 0060f9f0  8928                 mov dword ptr [eax], ebp
// 0060f9f2  c7400807000000       mov dword ptr [eax + 8], 7
// 0060f9f9  83460820             add dword ptr [esi + 8], 0x20
// 0060f9fd  8b4608               mov eax, dword ptr [esi + 8]
// 0060fa00  6a00                 push 0
// 0060fa02  83c0e0               add eax, -0x20
// 0060fa05  50                   push eax
// 0060fa06  56                   push esi
// 0060fa07  e8c468fbff           call 0x5c62d0
// 0060fa0c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060fa10  83c40c               add esp, 0xc
// 0060fa13  885e37               mov byte ptr [esi + 0x37], bl
// 0060fa16  894f40               mov dword ptr [edi + 0x40], ecx
// 0060fa19  5b                   pop ebx
// 0060fa1a  5f                   pop edi
// 0060fa1b  5d                   pop ebp
// 0060fa1c  59                   pop ecx
// 0060fa1d  c3                   ret 
// library lua-5.1.2/lgc.c (function _GCTM)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lgc.c
