// roc 2012-06 0059b4e0  unit: VAuthoringSettings::?$FactoryProduct  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059b4e0
//
// 0059b4e0  57                   push edi
// 0059b4e1  8bf9                 mov edi, ecx
// 0059b4e3  837f0400             cmp dword ptr [edi + 4], 0
// 0059b4e7  750d                 jne 0x59b4f6
// 0059b4e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0059b4ed  c60000               mov byte ptr [eax], 0
// 0059b4f0  33c0                 xor eax, eax
// 0059b4f2  5f                   pop edi
// 0059b4f3  c20c00               ret 0xc
// 0059b4f6  8b4704               mov eax, dword ptr [edi + 4]
// 0059b4f9  8b0f                 mov ecx, dword ptr [edi]
// 0059b4fb  53                   push ebx
// 0059b4fc  55                   push ebp
// 0059b4fd  8d68ff               lea ebp, [eax - 1]
// 0059b500  99                   cdq 
// 0059b501  2bc2                 sub eax, edx
// 0059b503  8b542410             mov edx, dword ptr [esp + 0x10]
// 0059b507  56                   push esi
// 0059b508  8bf0                 mov esi, eax
// 0059b50a  d1fe                 sar esi, 1
// 0059b50c  8d04b1               lea eax, [ecx + esi*4]
// 0059b50f  50                   push eax
// 0059b510  52                   push edx
// 0059b511  33db                 xor ebx, ebx
// 0059b513  ff542424             call dword ptr [esp + 0x24]
// 0059b517  83c408               add esp, 8
// 0059b51a  85c0                 test eax, eax
// 0059b51c  7431                 je 0x59b54f
// 0059b51e  7d05                 jge 0x59b525
// 0059b520  8d6eff               lea ebp, [esi - 1]
// 0059b523  eb03                 jmp 0x59b528
// 0059b525  8d5e01               lea ebx, [esi + 1]
// 0059b528  8bc5                 mov eax, ebp
// 0059b52a  2bc3                 sub eax, ebx
// 0059b52c  99                   cdq 
// 0059b52d  2bc2                 sub eax, edx
// 0059b52f  8bf0                 mov esi, eax
// 0059b531  d1fe                 sar esi, 1
// 0059b533  03f3                 add esi, ebx
// 0059b535  3bdd                 cmp ebx, ebp
// 0059b537  7f26                 jg 0x59b55f
// 0059b539  8b07                 mov eax, dword ptr [edi]
// 0059b53b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059b53f  8d04b0               lea eax, [eax + esi*4]
// 0059b542  50                   push eax
// 0059b543  51                   push ecx
// 0059b544  ff542424             call dword ptr [esp + 0x24]
// 0059b548  83c408               add esp, 8
// 0059b54b  85c0                 test eax, eax
// 0059b54d  75cf                 jne 0x59b51e
// 0059b54f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0059b553  8bc6                 mov eax, esi
// 0059b555  5e                   pop esi
// 0059b556  5d                   pop ebp
// 0059b557  5b                   pop ebx
// 0059b558  c60201               mov byte ptr [edx], 1
// 0059b55b  5f                   pop edi
// 0059b55c  c20c00               ret 0xc
// 0059b55f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0059b563  5e                   pop esi
// 0059b564  5d                   pop ebp
// 0059b565  c60000               mov byte ptr [eax], 0
// 0059b568  8bc3                 mov eax, ebx
// 0059b56a  5b                   pop ebx
// 0059b56b  5f                   pop edi
// 0059b56c  c20c00               ret 0xc
// library openrbx-raknet/ReliabilityLayer.cpp (function ?GetIndexFromKey@?$OrderedList@IPAUInternalPacket@@$1?SplitPacketIndexComp@@YAHABIABQAU1@@Z@DataStructures@@QBEIABIPA_NP6AH0ABQAUInternalPacket@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
