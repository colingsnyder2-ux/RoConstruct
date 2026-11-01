// from server: 100% by auto
// roc 2011-06 004e5200  unit: std::D::DU?$char_traits::V?$basic_string::$$CBV?$map::V?$shared_ptr::?$holder  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004e5200
//
// 004e5200  53                   push ebx
// 004e5201  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004e5205  8b4304               mov eax, dword ptr [ebx + 4]
// 004e5208  56                   push esi
// 004e5209  57                   push edi
// 004e520a  8bf1                 mov esi, ecx
// 004e520c  8b7e04               mov edi, dword ptr [esi + 4]
// 004e520f  83c004               add eax, 4
// 004e5212  8b00                 mov eax, dword ptr [eax]
// 004e5214  57                   push edi
// 004e5215  50                   push eax
// 004e5216  e865feffff           call 0x4e5080
// 004e521b  894704               mov dword ptr [edi + 4], eax
// 004e521e  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004e5221  8b5604               mov edx, dword ptr [esi + 4]
// 004e5224  894e08               mov dword ptr [esi + 8], ecx
// 004e5227  8b4204               mov eax, dword ptr [edx + 4]
// 004e522a  80783100             cmp byte ptr [eax + 0x31], 0
// 004e522e  7537                 jne 0x4e5267
// 004e5230  8b08                 mov ecx, dword ptr [eax]
// 004e5232  80793100             cmp byte ptr [ecx + 0x31], 0
// 004e5236  750a                 jne 0x4e5242
// 004e5238  8bc1                 mov eax, ecx
// 004e523a  8b08                 mov ecx, dword ptr [eax]
// 004e523c  80793100             cmp byte ptr [ecx + 0x31], 0
// 004e5240  74f6                 je 0x4e5238
// 004e5242  8902                 mov dword ptr [edx], eax
// 004e5244  8b7604               mov esi, dword ptr [esi + 4]
// 004e5247  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e524a  8b4108               mov eax, dword ptr [ecx + 8]
// 004e524d  80783100             cmp byte ptr [eax + 0x31], 0
// 004e5251  750b                 jne 0x4e525e
// 004e5253  8bc8                 mov ecx, eax
// 004e5255  8b4108               mov eax, dword ptr [ecx + 8]
// 004e5258  80783100             cmp byte ptr [eax + 0x31], 0
// 004e525c  74f5                 je 0x4e5253
// 004e525e  5f                   pop edi
// 004e525f  894e08               mov dword ptr [esi + 8], ecx
// 004e5262  5e                   pop esi
// 004e5263  5b                   pop ebx
// 004e5264  c20400               ret 4
// 004e5267  8912                 mov dword ptr [edx], edx
// 004e5269  8b7604               mov esi, dword ptr [esi + 4]
// 004e526c  5f                   pop edi
// 004e526d  897608               mov dword ptr [esi + 8], esi
// 004e5270  5e                   pop esi
// 004e5271  5b                   pop ebx
// 004e5272  c20400               ret 4
// library ogre-1.6.4/OgreAnimation.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@PAVHardwareVertexBuffer@Ogre@@VVertexBufferLicense@HardwareBufferManager@2@U?$less@PAVHardwareVertexBuffer@Ogre@@@std@@V?$allocator@U?$pair@QAVHardwareVertexBuffer@Ogre@@VVertexBufferLicense@HardwareBufferManager@2@@std@@@6@$0A@@std@@@std@@IAEXABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAnimation.cpp
