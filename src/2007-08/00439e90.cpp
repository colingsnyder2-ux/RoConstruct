// from server: 100% by auto
// roc 2007-08 00439e90  unit: RBX::VSoundId::?$XItem  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439e90
//
// 00439e90  55                   push ebp
// 00439e91  8bec                 mov ebp, esp
// 00439e93  6aff                 push -1
// 00439e95  6810e87300           push 0x73e810
// 00439e9a  64a100000000         mov eax, dword ptr fs:[0]
// 00439ea0  50                   push eax
// 00439ea1  83ec0c               sub esp, 0xc
// 00439ea4  53                   push ebx
// 00439ea5  56                   push esi
// 00439ea6  57                   push edi
// 00439ea7  a188518b00           mov eax, dword ptr [0x8b5188]
// 00439eac  33c5                 xor eax, ebp
// 00439eae  50                   push eax
// 00439eaf  8d45f4               lea eax, [ebp - 0xc]
// 00439eb2  64a300000000         mov dword ptr fs:[0], eax
// 00439eb8  8965f0               mov dword ptr [ebp - 0x10], esp
// 00439ebb  8bf1                 mov esi, ecx
// 00439ebd  8975e8               mov dword ptr [ebp - 0x18], esi
// 00439ec0  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00439ec3  807b1100             cmp byte ptr [ebx + 0x11], 0
// 00439ec7  8b4604               mov eax, dword ptr [esi + 4]
// 00439eca  8945ec               mov dword ptr [ebp - 0x14], eax
// 00439ecd  7547                 jne 0x439f16
// 00439ecf  0fb64b10             movzx ecx, byte ptr [ebx + 0x10]
// 00439ed3  51                   push ecx
// 00439ed4  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00439ed7  8d530c               lea edx, [ebx + 0xc]
// 00439eda  52                   push edx
// 00439edb  50                   push eax
// 00439edc  51                   push ecx
// 00439edd  50                   push eax
// 00439ede  8bce                 mov ecx, esi
// 00439ee0  e8fbae1c00           call 0x604de0
// 00439ee5  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00439ee8  807a1100             cmp byte ptr [edx + 0x11], 0
// 00439eec  8bf8                 mov edi, eax
// 00439eee  7403                 je 0x439ef3
// 00439ef0  897dec               mov dword ptr [ebp - 0x14], edi
// 00439ef3  8b03                 mov eax, dword ptr [ebx]
// 00439ef5  57                   push edi
// 00439ef6  50                   push eax
// 00439ef7  8bce                 mov ecx, esi
// 00439ef9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00439f00  e88bffffff           call 0x439e90
// 00439f05  8907                 mov dword ptr [edi], eax
// 00439f07  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00439f0a  57                   push edi
// 00439f0b  51                   push ecx
// 00439f0c  8bce                 mov ecx, esi
// 00439f0e  e87dffffff           call 0x439e90
// 00439f13  894708               mov dword ptr [edi + 8], eax
// 00439f16  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00439f19  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00439f1c  64890d00000000       mov dword ptr fs:[0], ecx
// 00439f23  59                   pop ecx
// 00439f24  5f                   pop edi
// 00439f25  5e                   pop esi
// 00439f26  5b                   pop ebx
// 00439f27  8be5                 mov esp, ebp
// 00439f29  5d                   pop ebp
// 00439f2a  c20800               ret 8
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
