// from server: 100% by auto
// roc 2010-06 0060f5b0  unit: RBX::Lua::VLiveThreadRef::?$sp_counted_impl_p  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060f5b0
//
// 0060f5b0  55                   push ebp
// 0060f5b1  8bec                 mov ebp, esp
// 0060f5b3  6aff                 push -1
// 0060f5b5  6890a19900           push 0x99a190
// 0060f5ba  64a100000000         mov eax, dword ptr fs:[0]
// 0060f5c0  50                   push eax
// 0060f5c1  64892500000000       mov dword ptr fs:[0], esp
// 0060f5c8  83ec0c               sub esp, 0xc
// 0060f5cb  53                   push ebx
// 0060f5cc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0060f5cf  807b1100             cmp byte ptr [ebx + 0x11], 0
// 0060f5d3  56                   push esi
// 0060f5d4  8bf1                 mov esi, ecx
// 0060f5d6  8b4618               mov eax, dword ptr [esi + 0x18]
// 0060f5d9  57                   push edi
// 0060f5da  8965f0               mov dword ptr [ebp - 0x10], esp
// 0060f5dd  8975e8               mov dword ptr [ebp - 0x18], esi
// 0060f5e0  8945ec               mov dword ptr [ebp - 0x14], eax
// 0060f5e3  7547                 jne 0x60f62c
// 0060f5e5  0fb64b10             movzx ecx, byte ptr [ebx + 0x10]
// 0060f5e9  51                   push ecx
// 0060f5ea  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0060f5ed  8d530c               lea edx, [ebx + 0xc]
// 0060f5f0  52                   push edx
// 0060f5f1  50                   push eax
// 0060f5f2  51                   push ecx
// 0060f5f3  50                   push eax
// 0060f5f4  8bce                 mov ecx, esi
// 0060f5f6  e885f1e0ff           call 0x41e780
// 0060f5fb  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0060f5fe  807a1100             cmp byte ptr [edx + 0x11], 0
// 0060f602  8bf8                 mov edi, eax
// 0060f604  7403                 je 0x60f609
// 0060f606  897dec               mov dword ptr [ebp - 0x14], edi
// 0060f609  8b03                 mov eax, dword ptr [ebx]
// 0060f60b  57                   push edi
// 0060f60c  50                   push eax
// 0060f60d  8bce                 mov ecx, esi
// 0060f60f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0060f616  e895ffffff           call 0x60f5b0
// 0060f61b  8907                 mov dword ptr [edi], eax
// 0060f61d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0060f620  57                   push edi
// 0060f621  51                   push ecx
// 0060f622  8bce                 mov ecx, esi
// 0060f624  e887ffffff           call 0x60f5b0
// 0060f629  894708               mov dword ptr [edi + 8], eax
// 0060f62c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0060f62f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0060f632  5f                   pop edi
// 0060f633  5e                   pop esi
// 0060f634  64890d00000000       mov dword ptr fs:[0], ecx
// 0060f63b  5b                   pop ebx
// 0060f63c  8be5                 mov esp, ebp
// 0060f63e  5d                   pop ebp
// 0060f63f  c20800               ret 8
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
