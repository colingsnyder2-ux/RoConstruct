// from server: 100% by auto
// roc 2008-06 0065bf00  unit: RBX::BallBallContact  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065bf00
//
// 0065bf00  51                   push ecx
// 0065bf01  55                   push ebp
// 0065bf02  57                   push edi
// 0065bf03  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0065bf06  8b4730               mov eax, dword ptr [edi + 0x30]
// 0065bf09  8b28                 mov ebp, dword ptr [eax]
// 0065bf0b  3be8                 cmp ebp, eax
// 0065bf0d  7509                 jne 0x65bf18
// 0065bf0f  c7473000000000       mov dword ptr [edi + 0x30], 0
// 0065bf16  eb05                 jmp 0x65bf1d
// 0065bf18  8b4d00               mov ecx, dword ptr [ebp]
// 0065bf1b  8908                 mov dword ptr [eax], ecx
// 0065bf1d  8b5770               mov edx, dword ptr [edi + 0x70]
// 0065bf20  8b02                 mov eax, dword ptr [edx]
// 0065bf22  894500               mov dword ptr [ebp], eax
// 0065bf25  8b4f70               mov ecx, dword ptr [edi + 0x70]
// 0065bf28  8929                 mov dword ptr [ecx], ebp
// 0065bf2a  8a4505               mov al, byte ptr [ebp + 5]
// 0065bf2d  8a5714               mov dl, byte ptr [edi + 0x14]
// 0065bf30  24f8                 and al, 0xf8
// 0065bf32  80e203               and dl, 3
// 0065bf35  0ad0                 or dl, al
// 0065bf37  8b4508               mov eax, dword ptr [ebp + 8]
// 0065bf3a  885505               mov byte ptr [ebp + 5], dl
// 0065bf3d  85c0                 test eax, eax
// 0065bf3f  7479                 je 0x65bfba
// 0065bf41  f6400604             test byte ptr [eax + 6], 4
// 0065bf45  7573                 jne 0x65bfba
// 0065bf47  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0065bf4a  8b91c4000000         mov edx, dword ptr [ecx + 0xc4]
// 0065bf50  52                   push edx
// 0065bf51  6a02                 push 2
// 0065bf53  50                   push eax
// 0065bf54  e877060000           call 0x65c5d0
// 0065bf59  83c40c               add esp, 0xc
// 0065bf5c  85c0                 test eax, eax
// 0065bf5e  745a                 je 0x65bfba
// 0065bf60  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 0065bf63  53                   push ebx
// 0065bf64  8a5e37               mov bl, byte ptr [esi + 0x37]
// 0065bf67  c6463700             mov byte ptr [esi + 0x37], 0
// 0065bf6b  8b5744               mov edx, dword ptr [edi + 0x44]
// 0065bf6e  03d2                 add edx, edx
// 0065bf70  895740               mov dword ptr [edi + 0x40], edx
// 0065bf73  8b10                 mov edx, dword ptr [eax]
// 0065bf75  894c240c             mov dword ptr [esp + 0xc], ecx
// 0065bf79  8b4e08               mov ecx, dword ptr [esi + 8]
// 0065bf7c  8911                 mov dword ptr [ecx], edx
// 0065bf7e  8b5004               mov edx, dword ptr [eax + 4]
// 0065bf81  895104               mov dword ptr [ecx + 4], edx
// 0065bf84  8b4008               mov eax, dword ptr [eax + 8]
// 0065bf87  894108               mov dword ptr [ecx + 8], eax
// 0065bf8a  8b4608               mov eax, dword ptr [esi + 8]
// 0065bf8d  83c010               add eax, 0x10
// 0065bf90  8928                 mov dword ptr [eax], ebp
// 0065bf92  c7400807000000       mov dword ptr [eax + 8], 7
// 0065bf99  83460820             add dword ptr [esi + 8], 0x20
// 0065bf9d  8b4608               mov eax, dword ptr [esi + 8]
// 0065bfa0  6a00                 push 0
// 0065bfa2  83c0e0               add eax, -0x20
// 0065bfa5  50                   push eax
// 0065bfa6  56                   push esi
// 0065bfa7  e85463fcff           call 0x622300
// 0065bfac  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065bfb0  83c40c               add esp, 0xc
// 0065bfb3  885e37               mov byte ptr [esi + 0x37], bl
// 0065bfb6  894f40               mov dword ptr [edi + 0x40], ecx
// 0065bfb9  5b                   pop ebx
// 0065bfba  5f                   pop edi
// 0065bfbb  5d                   pop ebp
// 0065bfbc  59                   pop ecx
// 0065bfbd  c3                   ret 
// library lua-5.1.2/lgc.c (function _GCTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lgc.c
