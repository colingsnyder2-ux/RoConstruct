// from server: 100% by auto
// roc 2007-03 005f9530  unit: seg_005f0000  size: 378 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9530
//
// 005f9530  51                   push ecx
// 005f9531  53                   push ebx
// 005f9532  55                   push ebp
// 005f9533  56                   push esi
// 005f9534  8b742414             mov esi, dword ptr [esp + 0x14]
// 005f9538  57                   push edi
// 005f9539  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005f953c  e8afffffff           call 0x5f94f0
// 005f9541  33ed                 xor ebp, ebp
// 005f9543  396f24               cmp dword ptr [edi + 0x24], ebp
// 005f9546  740c                 je 0x5f9554
// 005f9548  8bc7                 mov eax, edi
// 005f954a  e821faffff           call 0x5f8f70
// 005f954f  396f24               cmp dword ptr [edi + 0x24], ebp
// 005f9552  75f4                 jne 0x5f9548
// 005f9554  8b472c               mov eax, dword ptr [edi + 0x2c]
// 005f9557  894724               mov dword ptr [edi + 0x24], eax
// 005f955a  896f2c               mov dword ptr [edi + 0x2c], ebp
// 005f955d  f6460503             test byte ptr [esi + 5], 3
// 005f9561  740a                 je 0x5f956d
// 005f9563  56                   push esi
// 005f9564  57                   push edi
// 005f9565  e856f4ffff           call 0x5f89c0
// 005f956a  83c408               add esp, 8
// 005f956d  57                   push edi
// 005f956e  e8cdfeffff           call 0x5f9440
// 005f9573  83c404               add esp, 4
// 005f9576  396f24               cmp dword ptr [edi + 0x24], ebp
// 005f9579  7411                 je 0x5f958c
// 005f957b  eb03                 jmp 0x5f9580
// 005f957d  8d4900               lea ecx, [ecx]
// 005f9580  8bc7                 mov eax, edi
// 005f9582  e8e9f9ffff           call 0x5f8f70
// 005f9587  396f24               cmp dword ptr [edi + 0x24], ebp
// 005f958a  75f4                 jne 0x5f9580
// 005f958c  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 005f958f  3bcd                 cmp ecx, ebp
// 005f9591  894f24               mov dword ptr [edi + 0x24], ecx
// 005f9594  896f28               mov dword ptr [edi + 0x28], ebp
// 005f9597  7413                 je 0x5f95ac
// 005f9599  8da42400000000       lea esp, [esp]
// 005f95a0  8bc7                 mov eax, edi
// 005f95a2  e8c9f9ffff           call 0x5f8f70
// 005f95a7  396f24               cmp dword ptr [edi + 0x24], ebp
// 005f95aa  75f4                 jne 0x5f95a0
// 005f95ac  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005f95af  896c2410             mov dword ptr [esp + 0x10], ebp
// 005f95b3  8b6b70               mov ebp, dword ptr [ebx + 0x70]
// 005f95b6  8b7500               mov esi, dword ptr [ebp]
// 005f95b9  85f6                 test esi, esi
// 005f95bb  747a                 je 0x5f9637
// 005f95bd  8d4900               lea ecx, [ecx]
// 005f95c0  8a4605               mov al, byte ptr [esi + 5]
// 005f95c3  a803                 test al, 3
// 005f95c5  7404                 je 0x5f95cb
// 005f95c7  a808                 test al, 8
// 005f95c9  7404                 je 0x5f95cf
// 005f95cb  8bee                 mov ebp, esi
// 005f95cd  eb61                 jmp 0x5f9630
// 005f95cf  8b4608               mov eax, dword ptr [esi + 8]
// 005f95d2  85c0                 test eax, eax
// 005f95d4  7423                 je 0x5f95f9
// 005f95d6  f6400604             test byte ptr [eax + 6], 4
// 005f95da  751d                 jne 0x5f95f9
// 005f95dc  8b542418             mov edx, dword ptr [esp + 0x18]
// 005f95e0  8b4a10               mov ecx, dword ptr [edx + 0x10]
// 005f95e3  8b91c4000000         mov edx, dword ptr [ecx + 0xc4]
// 005f95e9  52                   push edx
// 005f95ea  6a02                 push 2
// 005f95ec  50                   push eax
// 005f95ed  e8fe030000           call 0x5f99f0
// 005f95f2  83c40c               add esp, 0xc
// 005f95f5  85c0                 test eax, eax
// 005f95f7  7508                 jne 0x5f9601
// 005f95f9  804e0508             or byte ptr [esi + 5], 8
// 005f95fd  8bee                 mov ebp, esi
// 005f95ff  eb2f                 jmp 0x5f9630
// 005f9601  8b4610               mov eax, dword ptr [esi + 0x10]
// 005f9604  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f9608  804e0508             or byte ptr [esi + 5], 8
// 005f960c  8d540118             lea edx, [ecx + eax + 0x18]
// 005f9610  8b06                 mov eax, dword ptr [esi]
// 005f9612  894500               mov dword ptr [ebp], eax
// 005f9615  8b4330               mov eax, dword ptr [ebx + 0x30]
// 005f9618  85c0                 test eax, eax
// 005f961a  89542410             mov dword ptr [esp + 0x10], edx
// 005f961e  7504                 jne 0x5f9624
// 005f9620  8936                 mov dword ptr [esi], esi
// 005f9622  eb09                 jmp 0x5f962d
// 005f9624  8b08                 mov ecx, dword ptr [eax]
// 005f9626  890e                 mov dword ptr [esi], ecx
// 005f9628  8b5330               mov edx, dword ptr [ebx + 0x30]
// 005f962b  8932                 mov dword ptr [edx], esi
// 005f962d  897330               mov dword ptr [ebx + 0x30], esi
// 005f9630  8b7500               mov esi, dword ptr [ebp]
// 005f9633  85f6                 test esi, esi
// 005f9635  7589                 jne 0x5f95c0
// 005f9637  8b7730               mov esi, dword ptr [edi + 0x30]
// 005f963a  85f6                 test esi, esi
// 005f963c  7423                 je 0x5f9661
// 005f963e  8bff                 mov edi, edi
// 005f9640  8b36                 mov esi, dword ptr [esi]
// 005f9642  8a4605               mov al, byte ptr [esi + 5]
// 005f9645  8a4f14               mov cl, byte ptr [edi + 0x14]
// 005f9648  24f8                 and al, 0xf8
// 005f964a  80e103               and cl, 3
// 005f964d  0ac1                 or al, cl
// 005f964f  56                   push esi
// 005f9650  57                   push edi
// 005f9651  884605               mov byte ptr [esi + 5], al
// 005f9654  e867f3ffff           call 0x5f89c0
// 005f9659  83c408               add esp, 8
// 005f965c  3b7730               cmp esi, dword ptr [edi + 0x30]
// 005f965f  75df                 jne 0x5f9640
// 005f9661  33f6                 xor esi, esi
// 005f9663  397724               cmp dword ptr [edi + 0x24], esi
// 005f9666  740f                 je 0x5f9677
// 005f9668  8bc7                 mov eax, edi
// 005f966a  e801f9ffff           call 0x5f8f70
// 005f966f  03f0                 add esi, eax
// 005f9671  837f2400             cmp dword ptr [edi + 0x24], 0
// 005f9675  75f1                 jne 0x5f9668
// 005f9677  8b572c               mov edx, dword ptr [edi + 0x2c]
// 005f967a  52                   push edx
// 005f967b  e8f0f9ffff           call 0x5f9070
// 005f9680  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 005f9683  80771403             xor byte ptr [edi + 0x14], 3
// 005f9687  83c404               add esp, 4
// 005f968a  2bce                 sub ecx, esi
// 005f968c  2b4c2410             sub ecx, dword ptr [esp + 0x10]
// 005f9690  8d471c               lea eax, [edi + 0x1c]
// 005f9693  c7471800000000       mov dword ptr [edi + 0x18], 0
// 005f969a  894720               mov dword ptr [edi + 0x20], eax
// 005f969d  c6471502             mov byte ptr [edi + 0x15], 2
// 005f96a1  894f48               mov dword ptr [edi + 0x48], ecx
// 005f96a4  5f                   pop edi
// 005f96a5  5e                   pop esi
// 005f96a6  5d                   pop ebp
// 005f96a7  5b                   pop ebx
// 005f96a8  59                   pop ecx
// 005f96a9  c3                   ret 
// library lua-5.1.1/lgc.c (function _atomic)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
