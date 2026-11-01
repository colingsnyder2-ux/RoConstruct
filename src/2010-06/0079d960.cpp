// from server: 100% by auto
// roc 2010-06 0079d960  unit: RBX::Limits::VCounter::V?$shared_ptr::?$thread_specific_ptr::delete_data  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0079d960
//
// 0079d960  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0079d963  8b4204               mov eax, dword ptr [edx + 4]
// 0079d966  80781500             cmp byte ptr [eax + 0x15], 0
// 0079d96a  53                   push ebx
// 0079d96b  55                   push ebp
// 0079d96c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0079d970  56                   push esi
// 0079d971  8bda                 mov ebx, edx
// 0079d973  752e                 jne 0x79d9a3
// 0079d975  57                   push edi
// 0079d976  8b7d00               mov edi, dword ptr [ebp]
// 0079d979  8da42400000000       lea esp, [esp]
// 0079d980  8b700c               mov esi, dword ptr [eax + 0xc]
// 0079d983  3bf7                 cmp esi, edi
// 0079d985  7305                 jae 0x79d98c
// 0079d987  8b4008               mov eax, dword ptr [eax + 8]
// 0079d98a  eb10                 jmp 0x79d99c
// 0079d98c  807a1500             cmp byte ptr [edx + 0x15], 0
// 0079d990  7406                 je 0x79d998
// 0079d992  3bfe                 cmp edi, esi
// 0079d994  7302                 jae 0x79d998
// 0079d996  8bd0                 mov edx, eax
// 0079d998  8bd8                 mov ebx, eax
// 0079d99a  8b00                 mov eax, dword ptr [eax]
// 0079d99c  80781500             cmp byte ptr [eax + 0x15], 0
// 0079d9a0  74de                 je 0x79d980
// 0079d9a2  5f                   pop edi
// 0079d9a3  807a1500             cmp byte ptr [edx + 0x15], 0
// 0079d9a7  7408                 je 0x79d9b1
// 0079d9a9  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0079d9ac  8b4004               mov eax, dword ptr [eax + 4]
// 0079d9af  eb02                 jmp 0x79d9b3
// 0079d9b1  8b02                 mov eax, dword ptr [edx]
// 0079d9b3  80781500             cmp byte ptr [eax + 0x15], 0
// 0079d9b7  751b                 jne 0x79d9d4
// 0079d9b9  8b7500               mov esi, dword ptr [ebp]
// 0079d9bc  8d642400             lea esp, [esp]
// 0079d9c0  3b700c               cmp esi, dword ptr [eax + 0xc]
// 0079d9c3  7306                 jae 0x79d9cb
// 0079d9c5  8bd0                 mov edx, eax
// 0079d9c7  8b00                 mov eax, dword ptr [eax]
// 0079d9c9  eb03                 jmp 0x79d9ce
// 0079d9cb  8b4008               mov eax, dword ptr [eax + 8]
// 0079d9ce  80781500             cmp byte ptr [eax + 0x15], 0
// 0079d9d2  74ec                 je 0x79d9c0
// 0079d9d4  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079d9d8  8b09                 mov ecx, dword ptr [ecx]
// 0079d9da  5e                   pop esi
// 0079d9db  5d                   pop ebp
// 0079d9dc  895804               mov dword ptr [eax + 4], ebx
// 0079d9df  8908                 mov dword ptr [eax], ecx
// 0079d9e1  894808               mov dword ptr [eax + 8], ecx
// 0079d9e4  89500c               mov dword ptr [eax + 0xc], edx
// 0079d9e7  5b                   pop ebx
// 0079d9e8  c20800               ret 8
// library ogre-1.6.4/OgreResourceBackgroundQueue.cpp (function ?_Eqrange@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@IAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@V123@@2@ABK@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceBackgroundQueue.cpp
