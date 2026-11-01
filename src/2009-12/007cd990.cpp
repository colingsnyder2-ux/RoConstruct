// from server: 100% by auto
// roc 2009-12 007cd990  unit: RBX::PartDropTool  size: 378 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd990
//
// 007cd990  51                   push ecx
// 007cd991  53                   push ebx
// 007cd992  55                   push ebp
// 007cd993  56                   push esi
// 007cd994  8b742414             mov esi, dword ptr [esp + 0x14]
// 007cd998  57                   push edi
// 007cd999  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007cd99c  e8afffffff           call 0x7cd950
// 007cd9a1  33ed                 xor ebp, ebp
// 007cd9a3  396f24               cmp dword ptr [edi + 0x24], ebp
// 007cd9a6  740c                 je 0x7cd9b4
// 007cd9a8  8bc7                 mov eax, edi
// 007cd9aa  e831faffff           call 0x7cd3e0
// 007cd9af  396f24               cmp dword ptr [edi + 0x24], ebp
// 007cd9b2  75f4                 jne 0x7cd9a8
// 007cd9b4  8b472c               mov eax, dword ptr [edi + 0x2c]
// 007cd9b7  894724               mov dword ptr [edi + 0x24], eax
// 007cd9ba  896f2c               mov dword ptr [edi + 0x2c], ebp
// 007cd9bd  f6460503             test byte ptr [esi + 5], 3
// 007cd9c1  740a                 je 0x7cd9cd
// 007cd9c3  56                   push esi
// 007cd9c4  57                   push edi
// 007cd9c5  e886f4ffff           call 0x7cce50
// 007cd9ca  83c408               add esp, 8
// 007cd9cd  57                   push edi
// 007cd9ce  e8cdfeffff           call 0x7cd8a0
// 007cd9d3  83c404               add esp, 4
// 007cd9d6  396f24               cmp dword ptr [edi + 0x24], ebp
// 007cd9d9  7411                 je 0x7cd9ec
// 007cd9db  eb03                 jmp 0x7cd9e0
// 007cd9dd  8d4900               lea ecx, [ecx]
// 007cd9e0  8bc7                 mov eax, edi
// 007cd9e2  e8f9f9ffff           call 0x7cd3e0
// 007cd9e7  396f24               cmp dword ptr [edi + 0x24], ebp
// 007cd9ea  75f4                 jne 0x7cd9e0
// 007cd9ec  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 007cd9ef  894f24               mov dword ptr [edi + 0x24], ecx
// 007cd9f2  896f28               mov dword ptr [edi + 0x28], ebp
// 007cd9f5  3bcd                 cmp ecx, ebp
// 007cd9f7  7413                 je 0x7cda0c
// 007cd9f9  8da42400000000       lea esp, [esp]
// 007cda00  8bc7                 mov eax, edi
// 007cda02  e8d9f9ffff           call 0x7cd3e0
// 007cda07  396f24               cmp dword ptr [edi + 0x24], ebp
// 007cda0a  75f4                 jne 0x7cda00
// 007cda0c  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007cda0f  896c2410             mov dword ptr [esp + 0x10], ebp
// 007cda13  8b6b70               mov ebp, dword ptr [ebx + 0x70]
// 007cda16  8b7500               mov esi, dword ptr [ebp]
// 007cda19  85f6                 test esi, esi
// 007cda1b  747a                 je 0x7cda97
// 007cda1d  8d4900               lea ecx, [ecx]
// 007cda20  8a4605               mov al, byte ptr [esi + 5]
// 007cda23  a803                 test al, 3
// 007cda25  7404                 je 0x7cda2b
// 007cda27  a808                 test al, 8
// 007cda29  7404                 je 0x7cda2f
// 007cda2b  8bee                 mov ebp, esi
// 007cda2d  eb61                 jmp 0x7cda90
// 007cda2f  8b4608               mov eax, dword ptr [esi + 8]
// 007cda32  85c0                 test eax, eax
// 007cda34  7423                 je 0x7cda59
// 007cda36  f6400604             test byte ptr [eax + 6], 4
// 007cda3a  751d                 jne 0x7cda59
// 007cda3c  8b542418             mov edx, dword ptr [esp + 0x18]
// 007cda40  8b4a10               mov ecx, dword ptr [edx + 0x10]
// 007cda43  8b91c4000000         mov edx, dword ptr [ecx + 0xc4]
// 007cda49  52                   push edx
// 007cda4a  6a02                 push 2
// 007cda4c  50                   push eax
// 007cda4d  e8fe030000           call 0x7cde50
// 007cda52  83c40c               add esp, 0xc
// 007cda55  85c0                 test eax, eax
// 007cda57  7508                 jne 0x7cda61
// 007cda59  804e0508             or byte ptr [esi + 5], 8
// 007cda5d  8bee                 mov ebp, esi
// 007cda5f  eb2f                 jmp 0x7cda90
// 007cda61  8b4610               mov eax, dword ptr [esi + 0x10]
// 007cda64  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007cda68  804e0508             or byte ptr [esi + 5], 8
// 007cda6c  8d540118             lea edx, [ecx + eax + 0x18]
// 007cda70  8b06                 mov eax, dword ptr [esi]
// 007cda72  894500               mov dword ptr [ebp], eax
// 007cda75  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007cda78  89542410             mov dword ptr [esp + 0x10], edx
// 007cda7c  85c0                 test eax, eax
// 007cda7e  7504                 jne 0x7cda84
// 007cda80  8936                 mov dword ptr [esi], esi
// 007cda82  eb09                 jmp 0x7cda8d
// 007cda84  8b08                 mov ecx, dword ptr [eax]
// 007cda86  890e                 mov dword ptr [esi], ecx
// 007cda88  8b5330               mov edx, dword ptr [ebx + 0x30]
// 007cda8b  8932                 mov dword ptr [edx], esi
// 007cda8d  897330               mov dword ptr [ebx + 0x30], esi
// 007cda90  8b7500               mov esi, dword ptr [ebp]
// 007cda93  85f6                 test esi, esi
// 007cda95  7589                 jne 0x7cda20
// 007cda97  8b7730               mov esi, dword ptr [edi + 0x30]
// 007cda9a  85f6                 test esi, esi
// 007cda9c  7423                 je 0x7cdac1
// 007cda9e  8bff                 mov edi, edi
// 007cdaa0  8b36                 mov esi, dword ptr [esi]
// 007cdaa2  8a4605               mov al, byte ptr [esi + 5]
// 007cdaa5  8a4f14               mov cl, byte ptr [edi + 0x14]
// 007cdaa8  24f8                 and al, 0xf8
// 007cdaaa  80e103               and cl, 3
// 007cdaad  0ac1                 or al, cl
// 007cdaaf  56                   push esi
// 007cdab0  57                   push edi
// 007cdab1  884605               mov byte ptr [esi + 5], al
// 007cdab4  e897f3ffff           call 0x7cce50
// 007cdab9  83c408               add esp, 8
// 007cdabc  3b7730               cmp esi, dword ptr [edi + 0x30]
// 007cdabf  75df                 jne 0x7cdaa0
// 007cdac1  33f6                 xor esi, esi
// 007cdac3  397724               cmp dword ptr [edi + 0x24], esi
// 007cdac6  740f                 je 0x7cdad7
// 007cdac8  8bc7                 mov eax, edi
// 007cdaca  e811f9ffff           call 0x7cd3e0
// 007cdacf  03f0                 add esi, eax
// 007cdad1  837f2400             cmp dword ptr [edi + 0x24], 0
// 007cdad5  75f1                 jne 0x7cdac8
// 007cdad7  8b572c               mov edx, dword ptr [edi + 0x2c]
// 007cdada  52                   push edx
// 007cdadb  e800faffff           call 0x7cd4e0
// 007cdae0  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 007cdae3  80771403             xor byte ptr [edi + 0x14], 3
// 007cdae7  83c404               add esp, 4
// 007cdaea  2bce                 sub ecx, esi
// 007cdaec  2b4c2410             sub ecx, dword ptr [esp + 0x10]
// 007cdaf0  8d471c               lea eax, [edi + 0x1c]
// 007cdaf3  c7471800000000       mov dword ptr [edi + 0x18], 0
// 007cdafa  894720               mov dword ptr [edi + 0x20], eax
// 007cdafd  c6471502             mov byte ptr [edi + 0x15], 2
// 007cdb01  894f48               mov dword ptr [edi + 0x48], ecx
// 007cdb04  5f                   pop edi
// 007cdb05  5e                   pop esi
// 007cdb06  5d                   pop ebp
// 007cdb07  5b                   pop ebx
// 007cdb08  59                   pop ecx
// 007cdb09  c3                   ret 
// library lua-5.1.1/lgc.c (function _atomic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
