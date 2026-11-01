// from server: 100% by auto
// roc 2011-06 004e5080  unit: std::D::DU?$char_traits::V?$basic_string::$$CBV?$map::V?$shared_ptr::?$holder  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004e5080
//
// 004e5080  55                   push ebp
// 004e5081  8bec                 mov ebp, esp
// 004e5083  6aff                 push -1
// 004e5085  68f0b39d00           push 0x9db3f0
// 004e508a  64a100000000         mov eax, dword ptr fs:[0]
// 004e5090  50                   push eax
// 004e5091  64892500000000       mov dword ptr fs:[0], esp
// 004e5098  83ec0c               sub esp, 0xc
// 004e509b  53                   push ebx
// 004e509c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004e509f  807b3100             cmp byte ptr [ebx + 0x31], 0
// 004e50a3  56                   push esi
// 004e50a4  8bf1                 mov esi, ecx
// 004e50a6  8b4604               mov eax, dword ptr [esi + 4]
// 004e50a9  57                   push edi
// 004e50aa  8965f0               mov dword ptr [ebp - 0x10], esp
// 004e50ad  8975e8               mov dword ptr [ebp - 0x18], esi
// 004e50b0  8945ec               mov dword ptr [ebp - 0x14], eax
// 004e50b3  7547                 jne 0x4e50fc
// 004e50b5  0fb64b30             movzx ecx, byte ptr [ebx + 0x30]
// 004e50b9  51                   push ecx
// 004e50ba  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004e50bd  8d530c               lea edx, [ebx + 0xc]
// 004e50c0  52                   push edx
// 004e50c1  50                   push eax
// 004e50c2  51                   push ecx
// 004e50c3  50                   push eax
// 004e50c4  8bce                 mov ecx, esi
// 004e50c6  e865f8ffff           call 0x4e4930
// 004e50cb  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004e50ce  807a3100             cmp byte ptr [edx + 0x31], 0
// 004e50d2  8bf8                 mov edi, eax
// 004e50d4  7403                 je 0x4e50d9
// 004e50d6  897dec               mov dword ptr [ebp - 0x14], edi
// 004e50d9  8b03                 mov eax, dword ptr [ebx]
// 004e50db  57                   push edi
// 004e50dc  50                   push eax
// 004e50dd  8bce                 mov ecx, esi
// 004e50df  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004e50e6  e895ffffff           call 0x4e5080
// 004e50eb  8907                 mov dword ptr [edi], eax
// 004e50ed  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004e50f0  57                   push edi
// 004e50f1  51                   push ecx
// 004e50f2  8bce                 mov ecx, esi
// 004e50f4  e887ffffff           call 0x4e5080
// 004e50f9  894708               mov dword ptr [edi + 8], eax
// 004e50fc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004e50ff  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004e5102  5f                   pop edi
// 004e5103  5e                   pop esi
// 004e5104  64890d00000000       mov dword ptr fs:[0], ecx
// 004e510b  5b                   pop ebx
// 004e510c  8be5                 mov esp, ebp
// 004e510e  5d                   pop ebp
// 004e510f  c20800               ret 8
// library ogre-1.6.4/OgreAnimation.cpp (function ?_Copy@?$_Tree@V?$_Tmap_traits@PAVHardwareVertexBuffer@Ogre@@VVertexBufferLicense@HardwareBufferManager@2@U?$less@PAVHardwareVertexBuffer@Ogre@@@std@@V?$allocator@U?$pair@QAVHardwareVertexBuffer@Ogre@@VVertexBufferLicense@HardwareBufferManager@2@@std@@@6@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@PAVHardwareVertexBuffer@Ogre@@VVertexBufferLicense@HardwareBufferManager@2@U?$less@PAVHardwareVertexBuffer@Ogre@@@std@@V?$allocator@U?$pair@QAVHardwareVertexBuffer@Ogre@@VVertexBufferLicense@HardwareBufferManager@2@@std@@@6@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAnimation.cpp
