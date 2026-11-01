// from server: 100% by auto
// roc 2009-06 0070dec0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070dec0
//
// 0070dec0  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0070dec3  8b4204               mov eax, dword ptr [edx + 4]
// 0070dec6  80781500             cmp byte ptr [eax + 0x15], 0
// 0070deca  53                   push ebx
// 0070decb  55                   push ebp
// 0070decc  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0070ded0  56                   push esi
// 0070ded1  8bda                 mov ebx, edx
// 0070ded3  752e                 jne 0x70df03
// 0070ded5  57                   push edi
// 0070ded6  8b7d00               mov edi, dword ptr [ebp]
// 0070ded9  8da42400000000       lea esp, [esp]
// 0070dee0  8b700c               mov esi, dword ptr [eax + 0xc]
// 0070dee3  3bf7                 cmp esi, edi
// 0070dee5  7305                 jae 0x70deec
// 0070dee7  8b4008               mov eax, dword ptr [eax + 8]
// 0070deea  eb10                 jmp 0x70defc
// 0070deec  807a1500             cmp byte ptr [edx + 0x15], 0
// 0070def0  7406                 je 0x70def8
// 0070def2  3bfe                 cmp edi, esi
// 0070def4  7302                 jae 0x70def8
// 0070def6  8bd0                 mov edx, eax
// 0070def8  8bd8                 mov ebx, eax
// 0070defa  8b00                 mov eax, dword ptr [eax]
// 0070defc  80781500             cmp byte ptr [eax + 0x15], 0
// 0070df00  74de                 je 0x70dee0
// 0070df02  5f                   pop edi
// 0070df03  807a1500             cmp byte ptr [edx + 0x15], 0
// 0070df07  7408                 je 0x70df11
// 0070df09  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0070df0c  8b4004               mov eax, dword ptr [eax + 4]
// 0070df0f  eb02                 jmp 0x70df13
// 0070df11  8b02                 mov eax, dword ptr [edx]
// 0070df13  80781500             cmp byte ptr [eax + 0x15], 0
// 0070df17  751b                 jne 0x70df34
// 0070df19  8b7500               mov esi, dword ptr [ebp]
// 0070df1c  8d642400             lea esp, [esp]
// 0070df20  3b700c               cmp esi, dword ptr [eax + 0xc]
// 0070df23  7306                 jae 0x70df2b
// 0070df25  8bd0                 mov edx, eax
// 0070df27  8b00                 mov eax, dword ptr [eax]
// 0070df29  eb03                 jmp 0x70df2e
// 0070df2b  8b4008               mov eax, dword ptr [eax + 8]
// 0070df2e  80781500             cmp byte ptr [eax + 0x15], 0
// 0070df32  74ec                 je 0x70df20
// 0070df34  8b442410             mov eax, dword ptr [esp + 0x10]
// 0070df38  8b09                 mov ecx, dword ptr [ecx]
// 0070df3a  5e                   pop esi
// 0070df3b  5d                   pop ebp
// 0070df3c  895804               mov dword ptr [eax + 4], ebx
// 0070df3f  8908                 mov dword ptr [eax], ecx
// 0070df41  894808               mov dword ptr [eax + 8], ecx
// 0070df44  89500c               mov dword ptr [eax + 0xc], edx
// 0070df47  5b                   pop ebx
// 0070df48  c20800               ret 8
// library ogre-1.6.4/OgreResourceBackgroundQueue.cpp (function ?_Eqrange@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@IAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@V123@@2@ABK@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceBackgroundQueue.cpp
