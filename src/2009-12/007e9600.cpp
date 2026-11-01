// from server: 100% by auto
// roc 2009-12 007e9600  unit: RBX::Limits::VCounter::V?$shared_ptr::?$thread_specific_ptr::delete_data  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e9600
//
// 007e9600  8b5118               mov edx, dword ptr [ecx + 0x18]
// 007e9603  8b4204               mov eax, dword ptr [edx + 4]
// 007e9606  80781500             cmp byte ptr [eax + 0x15], 0
// 007e960a  53                   push ebx
// 007e960b  55                   push ebp
// 007e960c  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007e9610  56                   push esi
// 007e9611  8bda                 mov ebx, edx
// 007e9613  752e                 jne 0x7e9643
// 007e9615  57                   push edi
// 007e9616  8b7d00               mov edi, dword ptr [ebp]
// 007e9619  8da42400000000       lea esp, [esp]
// 007e9620  8b700c               mov esi, dword ptr [eax + 0xc]
// 007e9623  3bf7                 cmp esi, edi
// 007e9625  7305                 jae 0x7e962c
// 007e9627  8b4008               mov eax, dword ptr [eax + 8]
// 007e962a  eb10                 jmp 0x7e963c
// 007e962c  807a1500             cmp byte ptr [edx + 0x15], 0
// 007e9630  7406                 je 0x7e9638
// 007e9632  3bfe                 cmp edi, esi
// 007e9634  7302                 jae 0x7e9638
// 007e9636  8bd0                 mov edx, eax
// 007e9638  8bd8                 mov ebx, eax
// 007e963a  8b00                 mov eax, dword ptr [eax]
// 007e963c  80781500             cmp byte ptr [eax + 0x15], 0
// 007e9640  74de                 je 0x7e9620
// 007e9642  5f                   pop edi
// 007e9643  807a1500             cmp byte ptr [edx + 0x15], 0
// 007e9647  7408                 je 0x7e9651
// 007e9649  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007e964c  8b4004               mov eax, dword ptr [eax + 4]
// 007e964f  eb02                 jmp 0x7e9653
// 007e9651  8b02                 mov eax, dword ptr [edx]
// 007e9653  80781500             cmp byte ptr [eax + 0x15], 0
// 007e9657  751b                 jne 0x7e9674
// 007e9659  8b7500               mov esi, dword ptr [ebp]
// 007e965c  8d642400             lea esp, [esp]
// 007e9660  3b700c               cmp esi, dword ptr [eax + 0xc]
// 007e9663  7306                 jae 0x7e966b
// 007e9665  8bd0                 mov edx, eax
// 007e9667  8b00                 mov eax, dword ptr [eax]
// 007e9669  eb03                 jmp 0x7e966e
// 007e966b  8b4008               mov eax, dword ptr [eax + 8]
// 007e966e  80781500             cmp byte ptr [eax + 0x15], 0
// 007e9672  74ec                 je 0x7e9660
// 007e9674  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e9678  8b09                 mov ecx, dword ptr [ecx]
// 007e967a  5e                   pop esi
// 007e967b  5d                   pop ebp
// 007e967c  895804               mov dword ptr [eax + 4], ebx
// 007e967f  8908                 mov dword ptr [eax], ecx
// 007e9681  894808               mov dword ptr [eax + 8], ecx
// 007e9684  89500c               mov dword ptr [eax + 0xc], edx
// 007e9687  5b                   pop ebx
// 007e9688  c20800               ret 8
// library ogre-1.6.4/OgreResourceBackgroundQueue.cpp (function ?_Eqrange@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@IAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@KPAURequest@ResourceBackgroundQueue@Ogre@@U?$less@K@std@@V?$allocator@U?$pair@$$CBKPAURequest@ResourceBackgroundQueue@Ogre@@@std@@@5@$0A@@std@@@std@@V123@@2@ABK@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceBackgroundQueue.cpp
