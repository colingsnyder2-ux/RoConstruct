// from server: 100% by auto
// roc 2007-03 005f9310  unit: seg_005f0000  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9310
//
// 005f9310  51                   push ecx
// 005f9311  55                   push ebp
// 005f9312  57                   push edi
// 005f9313  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005f9316  8b4730               mov eax, dword ptr [edi + 0x30]
// 005f9319  8b28                 mov ebp, dword ptr [eax]
// 005f931b  3be8                 cmp ebp, eax
// 005f931d  7509                 jne 0x5f9328
// 005f931f  c7473000000000       mov dword ptr [edi + 0x30], 0
// 005f9326  eb05                 jmp 0x5f932d
// 005f9328  8b4d00               mov ecx, dword ptr [ebp]
// 005f932b  8908                 mov dword ptr [eax], ecx
// 005f932d  8b5770               mov edx, dword ptr [edi + 0x70]
// 005f9330  8b02                 mov eax, dword ptr [edx]
// 005f9332  894500               mov dword ptr [ebp], eax
// 005f9335  8b4f70               mov ecx, dword ptr [edi + 0x70]
// 005f9338  8929                 mov dword ptr [ecx], ebp
// 005f933a  8a4505               mov al, byte ptr [ebp + 5]
// 005f933d  8a5714               mov dl, byte ptr [edi + 0x14]
// 005f9340  24f8                 and al, 0xf8
// 005f9342  80e203               and dl, 3
// 005f9345  0ad0                 or dl, al
// 005f9347  8b4508               mov eax, dword ptr [ebp + 8]
// 005f934a  85c0                 test eax, eax
// 005f934c  885505               mov byte ptr [ebp + 5], dl
// 005f934f  7479                 je 0x5f93ca
// 005f9351  f6400604             test byte ptr [eax + 6], 4
// 005f9355  7573                 jne 0x5f93ca
// 005f9357  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005f935a  8b91c4000000         mov edx, dword ptr [ecx + 0xc4]
// 005f9360  52                   push edx
// 005f9361  6a02                 push 2
// 005f9363  50                   push eax
// 005f9364  e887060000           call 0x5f99f0
// 005f9369  83c40c               add esp, 0xc
// 005f936c  85c0                 test eax, eax
// 005f936e  745a                 je 0x5f93ca
// 005f9370  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 005f9373  53                   push ebx
// 005f9374  8a5e37               mov bl, byte ptr [esi + 0x37]
// 005f9377  c6463700             mov byte ptr [esi + 0x37], 0
// 005f937b  8b5744               mov edx, dword ptr [edi + 0x44]
// 005f937e  03d2                 add edx, edx
// 005f9380  895740               mov dword ptr [edi + 0x40], edx
// 005f9383  8b10                 mov edx, dword ptr [eax]
// 005f9385  894c240c             mov dword ptr [esp + 0xc], ecx
// 005f9389  8b4e08               mov ecx, dword ptr [esi + 8]
// 005f938c  8911                 mov dword ptr [ecx], edx
// 005f938e  8b5004               mov edx, dword ptr [eax + 4]
// 005f9391  895104               mov dword ptr [ecx + 4], edx
// 005f9394  8b4008               mov eax, dword ptr [eax + 8]
// 005f9397  894108               mov dword ptr [ecx + 8], eax
// 005f939a  8b4608               mov eax, dword ptr [esi + 8]
// 005f939d  83c010               add eax, 0x10
// 005f93a0  8928                 mov dword ptr [eax], ebp
// 005f93a2  c7400807000000       mov dword ptr [eax + 8], 7
// 005f93a9  83460820             add dword ptr [esi + 8], 0x20
// 005f93ad  8b4608               mov eax, dword ptr [esi + 8]
// 005f93b0  6a00                 push 0
// 005f93b2  83c0e0               add eax, -0x20
// 005f93b5  50                   push eax
// 005f93b6  56                   push esi
// 005f93b7  e8f470fcff           call 0x5c04b0
// 005f93bc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005f93c0  83c40c               add esp, 0xc
// 005f93c3  885e37               mov byte ptr [esi + 0x37], bl
// 005f93c6  894f40               mov dword ptr [edi + 0x40], ecx
// 005f93c9  5b                   pop ebx
// 005f93ca  5f                   pop edi
// 005f93cb  5d                   pop ebp
// 005f93cc  59                   pop ecx
// 005f93cd  c3                   ret 
// library lua-5.1.1/lgc.c (function _GCTM)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
