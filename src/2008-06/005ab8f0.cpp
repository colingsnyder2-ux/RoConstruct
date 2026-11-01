// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005ab8f0  unit: RBX::Lua::ThreadRef::VNode::V?$shared_ptr::?$TItem  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ab8f0
//
// 005ab8f0  55                   push ebp
// 005ab8f1  8bec                 mov ebp, esp
// 005ab8f3  6aff                 push -1
// 005ab8f5  6880317d00           push 0x7d3180
// 005ab8fa  64a100000000         mov eax, dword ptr fs:[0]
// 005ab900  50                   push eax
// 005ab901  64892500000000       mov dword ptr fs:[0], esp
// 005ab908  83ec0c               sub esp, 0xc
// 005ab90b  53                   push ebx
// 005ab90c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005ab90f  807b1100             cmp byte ptr [ebx + 0x11], 0
// 005ab913  56                   push esi
// 005ab914  8bf1                 mov esi, ecx
// 005ab916  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ab919  57                   push edi
// 005ab91a  8965f0               mov dword ptr [ebp - 0x10], esp
// 005ab91d  8975e8               mov dword ptr [ebp - 0x18], esi
// 005ab920  8945ec               mov dword ptr [ebp - 0x14], eax
// 005ab923  7547                 jne 0x5ab96c
// 005ab925  0fb64b10             movzx ecx, byte ptr [ebx + 0x10]
// 005ab929  51                   push ecx
// 005ab92a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005ab92d  8d530c               lea edx, [ebx + 0xc]
// 005ab930  52                   push edx
// 005ab931  50                   push eax
// 005ab932  51                   push ecx
// 005ab933  50                   push eax
// 005ab934  8bce                 mov ecx, esi
// 005ab936  e80580e7ff           call 0x423940
// 005ab93b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005ab93e  807a1100             cmp byte ptr [edx + 0x11], 0
// 005ab942  8bf8                 mov edi, eax
// 005ab944  7403                 je 0x5ab949
// 005ab946  897dec               mov dword ptr [ebp - 0x14], edi
// 005ab949  8b03                 mov eax, dword ptr [ebx]
// 005ab94b  57                   push edi
// 005ab94c  50                   push eax
// 005ab94d  8bce                 mov ecx, esi
// 005ab94f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005ab956  e895ffffff           call 0x5ab8f0
// 005ab95b  8907                 mov dword ptr [edi], eax
// 005ab95d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005ab960  57                   push edi
// 005ab961  51                   push ecx
// 005ab962  8bce                 mov ecx, esi
// 005ab964  e887ffffff           call 0x5ab8f0
// 005ab969  894708               mov dword ptr [edi + 8], eax
// 005ab96c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005ab96f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005ab972  5f                   pop edi
// 005ab973  5e                   pop esi
// 005ab974  64890d00000000       mov dword ptr fs:[0], ecx
// 005ab97b  5b                   pop ebx
// 005ab97c  8be5                 mov esp, ebp
// 005ab97e  5d                   pop ebp
// 005ab97f  c20800               ret 8
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
