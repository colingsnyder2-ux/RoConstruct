// roc 2012-06 00567880  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 234 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567880
//
// 00567880  53                   push ebx
// 00567881  55                   push ebp
// 00567882  56                   push esi
// 00567883  57                   push edi
// 00567884  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00567888  c1ef03               shr edi, 3
// 0056788b  4f                   dec edi
// 0056788c  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 00567891  8bf1                 mov esi, ecx
// 00567893  740c                 je 0x5678a1
// 00567895  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0056789a  c644241800           mov byte ptr [esp + 0x18], 0
// 0056789f  eb0a                 jmp 0x5678ab
// 005678a1  c644241cff           mov byte ptr [esp + 0x1c], 0xff
// 005678a6  c6442418f0           mov byte ptr [esp + 0x18], 0xf0
// 005678ab  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005678af  85ff                 test edi, edi
// 005678b1  7636                 jbe 0x5678e9
// 005678b3  8b4608               mov eax, dword ptr [esi + 8]
// 005678b6  8d6801               lea ebp, [eax + 1]
// 005678b9  3b2e                 cmp ebp, dword ptr [esi]
// 005678bb  7771                 ja 0x56792e
// 005678bd  8bc8                 mov ecx, eax
// 005678bf  83e107               and ecx, 7
// 005678c2  ba80000000           mov edx, 0x80
// 005678c7  d3fa                 sar edx, cl
// 005678c9  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005678cc  c1e803               shr eax, 3
// 005678cf  841408               test byte ptr [eax + ecx], dl
// 005678d2  896e08               mov dword ptr [esi + 8], ebp
// 005678d5  0f95c0               setne al
// 005678d8  84c0                 test al, al
// 005678da  745b                 je 0x567937
// 005678dc  83ef01               sub edi, 1
// 005678df  8a54241c             mov dl, byte ptr [esp + 0x1c]
// 005678e3  88541f01             mov byte ptr [edi + ebx + 1], dl
// 005678e7  75ca                 jne 0x5678b3
// 005678e9  8b4e08               mov ecx, dword ptr [esi + 8]
// 005678ec  41                   inc ecx
// 005678ed  3b0e                 cmp ecx, dword ptr [esi]
// 005678ef  773d                 ja 0x56792e
// 005678f1  8d54241c             lea edx, [esp + 0x1c]
// 005678f5  52                   push edx
// 005678f6  8bce                 mov ecx, esi
// 005678f8  c644242000           mov byte ptr [esp + 0x20], 0
// 005678fd  e85efcffff           call 0x567560
// 00567902  84c0                 test al, al
// 00567904  7428                 je 0x56792e
// 00567906  03fb                 add edi, ebx
// 00567908  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 0056790d  6a01                 push 1
// 0056790f  8bce                 mov ecx, esi
// 00567911  7442                 je 0x567955
// 00567913  6a04                 push 4
// 00567915  57                   push edi
// 00567916  e865feffff           call 0x567780
// 0056791b  84c0                 test al, al
// 0056791d  740f                 je 0x56792e
// 0056791f  8a442418             mov al, byte ptr [esp + 0x18]
// 00567923  0807                 or byte ptr [edi], al
// 00567925  5f                   pop edi
// 00567926  5e                   pop esi
// 00567927  5d                   pop ebp
// 00567928  b001                 mov al, 1
// 0056792a  5b                   pop ebx
// 0056792b  c20c00               ret 0xc
// 0056792e  5f                   pop edi
// 0056792f  5e                   pop esi
// 00567930  5d                   pop ebp
// 00567931  32c0                 xor al, al
// 00567933  5b                   pop ebx
// 00567934  c20c00               ret 0xc
// 00567937  6a01                 push 1
// 00567939  8d04fd08000000       lea eax, [edi*8 + 8]
// 00567940  50                   push eax
// 00567941  53                   push ebx
// 00567942  8bce                 mov ecx, esi
// 00567944  e837feffff           call 0x567780
// 00567949  5f                   pop edi
// 0056794a  5e                   pop esi
// 0056794b  84c0                 test al, al
// 0056794d  5d                   pop ebp
// 0056794e  0f95c0               setne al
// 00567951  5b                   pop ebx
// 00567952  c20c00               ret 0xc
// 00567955  6a08                 push 8
// 00567957  57                   push edi
// 00567958  e823feffff           call 0x567780
// 0056795d  84c0                 test al, al
// 0056795f  74cd                 je 0x56792e
// 00567961  5f                   pop edi
// 00567962  5e                   pop esi
// 00567963  5d                   pop ebp
// 00567964  b001                 mov al, 1
// 00567966  5b                   pop ebx
// 00567967  c20c00               ret 0xc
// copied from an identical function in another client (function ?ReadCompressed@BitStream@RakNet@@AAE_NPAEI_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp