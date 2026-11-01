// from server: 100% by auto
// roc 2010-06 0060fea0  unit: RBX::VScriptContext::?$FactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060fea0
//
// 0060fea0  53                   push ebx
// 0060fea1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0060fea5  8b4318               mov eax, dword ptr [ebx + 0x18]
// 0060fea8  56                   push esi
// 0060fea9  57                   push edi
// 0060feaa  8bf1                 mov esi, ecx
// 0060feac  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0060feaf  83c004               add eax, 4
// 0060feb2  8b00                 mov eax, dword ptr [eax]
// 0060feb4  57                   push edi
// 0060feb5  50                   push eax
// 0060feb6  e8f5f6ffff           call 0x60f5b0
// 0060febb  894704               mov dword ptr [edi + 4], eax
// 0060febe  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 0060fec1  8b5618               mov edx, dword ptr [esi + 0x18]
// 0060fec4  894e1c               mov dword ptr [esi + 0x1c], ecx
// 0060fec7  8b4204               mov eax, dword ptr [edx + 4]
// 0060feca  80781100             cmp byte ptr [eax + 0x11], 0
// 0060fece  7537                 jne 0x60ff07
// 0060fed0  8b08                 mov ecx, dword ptr [eax]
// 0060fed2  80791100             cmp byte ptr [ecx + 0x11], 0
// 0060fed6  750a                 jne 0x60fee2
// 0060fed8  8bc1                 mov eax, ecx
// 0060feda  8b08                 mov ecx, dword ptr [eax]
// 0060fedc  80791100             cmp byte ptr [ecx + 0x11], 0
// 0060fee0  74f6                 je 0x60fed8
// 0060fee2  8902                 mov dword ptr [edx], eax
// 0060fee4  8b7618               mov esi, dword ptr [esi + 0x18]
// 0060fee7  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060feea  8b4108               mov eax, dword ptr [ecx + 8]
// 0060feed  80781100             cmp byte ptr [eax + 0x11], 0
// 0060fef1  750b                 jne 0x60fefe
// 0060fef3  8bc8                 mov ecx, eax
// 0060fef5  8b4108               mov eax, dword ptr [ecx + 8]
// 0060fef8  80781100             cmp byte ptr [eax + 0x11], 0
// 0060fefc  74f5                 je 0x60fef3
// 0060fefe  5f                   pop edi
// 0060feff  894e08               mov dword ptr [esi + 8], ecx
// 0060ff02  5e                   pop esi
// 0060ff03  5b                   pop ebx
// 0060ff04  c20400               ret 4
// 0060ff07  8912                 mov dword ptr [edx], edx
// 0060ff09  8b7618               mov esi, dword ptr [esi + 0x18]
// 0060ff0c  5f                   pop edi
// 0060ff0d  897608               mov dword ptr [esi + 8], esi
// 0060ff10  5e                   pop esi
// 0060ff11  5b                   pop ebx
// 0060ff12  c20400               ret 4
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
