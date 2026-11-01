// from server: 100% by auto
// roc 2009-06 007996f0  unit: CXTPRibbonTheme  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007996f0
//
// 007996f0  83ec20               sub esp, 0x20
// 007996f3  53                   push ebx
// 007996f4  55                   push ebp
// 007996f5  33ed                 xor ebp, ebp
// 007996f7  56                   push esi
// 007996f8  57                   push edi
// 007996f9  396c244c             cmp dword ptr [esp + 0x4c], ebp
// 007996fd  0f848b000000         je 0x79978e
// 00799703  68f80b9000           push 0x900bf8
// 00799708  e8b3a60000           call 0x7a3dc0
// 0079970d  8bf0                 mov esi, eax
// 0079970f  3bf5                 cmp esi, ebp
// 00799711  747b                 je 0x79978e
// 00799713  33c0                 xor eax, eax
// 00799715  396c245c             cmp dword ptr [esp + 0x5c], ebp
// 00799719  7505                 jne 0x799720
// 0079971b  8d4503               lea eax, [ebp + 3]
// 0079971e  eb10                 jmp 0x799730
// 00799720  396c2450             cmp dword ptr [esp + 0x50], ebp
// 00799724  740a                 je 0x799730
// 00799726  33c0                 xor eax, eax
// 00799728  396c2454             cmp dword ptr [esp + 0x54], ebp
// 0079972c  0f95c0               setne al
// 0079972f  40                   inc eax
// 00799730  396c2458             cmp dword ptr [esp + 0x58], ebp
// 00799734  7403                 je 0x799739
// 00799736  83c004               add eax, 4
// 00799739  6a08                 push 8
// 0079973b  50                   push eax
// 0079973c  8d442428             lea eax, [esp + 0x28]
// 00799740  50                   push eax
// 00799741  8bce                 mov ecx, esi
// 00799743  33ff                 xor edi, edi
// 00799745  33db                 xor ebx, ebx
// 00799747  896c2428             mov dword ptr [esp + 0x28], ebp
// 0079974b  e870c60600           call 0x805dc0
// 00799750  83ec10               sub esp, 0x10
// 00799753  8bcc                 mov ecx, esp
// 00799755  8939                 mov dword ptr [ecx], edi
// 00799757  895904               mov dword ptr [ecx + 4], ebx
// 0079975a  896908               mov dword ptr [ecx + 8], ebp
// 0079975d  83ec10               sub esp, 0x10
// 00799760  8bd5                 mov edx, ebp
// 00799762  89510c               mov dword ptr [ecx + 0xc], edx
// 00799765  8b10                 mov edx, dword ptr [eax]
// 00799767  8bcc                 mov ecx, esp
// 00799769  8911                 mov dword ptr [ecx], edx
// 0079976b  8b5004               mov edx, dword ptr [eax + 4]
// 0079976e  895104               mov dword ptr [ecx + 4], edx
// 00799771  8b5008               mov edx, dword ptr [eax + 8]
// 00799774  8b400c               mov eax, dword ptr [eax + 0xc]
// 00799777  895108               mov dword ptr [ecx + 8], edx
// 0079977a  8b542458             mov edx, dword ptr [esp + 0x58]
// 0079977e  89410c               mov dword ptr [ecx + 0xc], eax
// 00799781  8d4c245c             lea ecx, [esp + 0x5c]
// 00799785  51                   push ecx
// 00799786  52                   push edx
// 00799787  8bce                 mov ecx, esi
// 00799789  e802bf0600           call 0x805690
// 0079978e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00799792  5f                   pop edi
// 00799793  5e                   pop esi
// 00799794  5d                   pop ebp
// 00799795  c7000d000000         mov dword ptr [eax], 0xd
// 0079979b  c740040d000000       mov dword ptr [eax + 4], 0xd
// 007997a2  5b                   pop ebx
// 007997a3  83c420               add esp, 0x20
// 007997a6  c22c00               ret 0x2c
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawControlRadioButtonMark@CXTPRibbonTheme@@MAE?AVCSize@@PAVCDC@@VCRect@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
