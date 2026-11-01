// from server: 100% by auto
// roc 2009-12 007863f0  unit: RBX::BoxSelectCommand  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007863f0
//
// 007863f0  55                   push ebp
// 007863f1  8bec                 mov ebp, esp
// 007863f3  6aff                 push -1
// 007863f5  68603b9500           push 0x953b60
// 007863fa  64a100000000         mov eax, dword ptr fs:[0]
// 00786400  50                   push eax
// 00786401  64892500000000       mov dword ptr fs:[0], esp
// 00786408  83ec0c               sub esp, 0xc
// 0078640b  53                   push ebx
// 0078640c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0078640f  807b1100             cmp byte ptr [ebx + 0x11], 0
// 00786413  56                   push esi
// 00786414  8bf1                 mov esi, ecx
// 00786416  8b4618               mov eax, dword ptr [esi + 0x18]
// 00786419  57                   push edi
// 0078641a  8965f0               mov dword ptr [ebp - 0x10], esp
// 0078641d  8975e8               mov dword ptr [ebp - 0x18], esi
// 00786420  8945ec               mov dword ptr [ebp - 0x14], eax
// 00786423  7547                 jne 0x78646c
// 00786425  0fb64b10             movzx ecx, byte ptr [ebx + 0x10]
// 00786429  51                   push ecx
// 0078642a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0078642d  8d530c               lea edx, [ebx + 0xc]
// 00786430  52                   push edx
// 00786431  50                   push eax
// 00786432  51                   push ecx
// 00786433  50                   push eax
// 00786434  8bce                 mov ecx, esi
// 00786436  e815410500           call 0x7da550
// 0078643b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0078643e  807a1100             cmp byte ptr [edx + 0x11], 0
// 00786442  8bf8                 mov edi, eax
// 00786444  7403                 je 0x786449
// 00786446  897dec               mov dword ptr [ebp - 0x14], edi
// 00786449  8b03                 mov eax, dword ptr [ebx]
// 0078644b  57                   push edi
// 0078644c  50                   push eax
// 0078644d  8bce                 mov ecx, esi
// 0078644f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00786456  e895ffffff           call 0x7863f0
// 0078645b  8907                 mov dword ptr [edi], eax
// 0078645d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00786460  57                   push edi
// 00786461  51                   push ecx
// 00786462  8bce                 mov ecx, esi
// 00786464  e887ffffff           call 0x7863f0
// 00786469  894708               mov dword ptr [edi + 8], eax
// 0078646c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0078646f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00786472  5f                   pop edi
// 00786473  5e                   pop esi
// 00786474  64890d00000000       mov dword ptr fs:[0], ecx
// 0078647b  5b                   pop ebx
// 0078647c  8be5                 mov esp, ebp
// 0078647e  5d                   pop ebp
// 0078647f  c20800               ret 8
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
