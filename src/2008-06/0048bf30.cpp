// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0048bf30  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048bf30
//
// 0048bf30  55                   push ebp
// 0048bf31  8bec                 mov ebp, esp
// 0048bf33  6aff                 push -1
// 0048bf35  68c0617c00           push 0x7c61c0
// 0048bf3a  64a100000000         mov eax, dword ptr fs:[0]
// 0048bf40  50                   push eax
// 0048bf41  64892500000000       mov dword ptr fs:[0], esp
// 0048bf48  83ec0c               sub esp, 0xc
// 0048bf4b  53                   push ebx
// 0048bf4c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0048bf4f  807b0e00             cmp byte ptr [ebx + 0xe], 0
// 0048bf53  56                   push esi
// 0048bf54  8bf1                 mov esi, ecx
// 0048bf56  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048bf59  57                   push edi
// 0048bf5a  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048bf5d  8975e8               mov dword ptr [ebp - 0x18], esi
// 0048bf60  8945ec               mov dword ptr [ebp - 0x14], eax
// 0048bf63  7547                 jne 0x48bfac
// 0048bf65  0fb64b0d             movzx ecx, byte ptr [ebx + 0xd]
// 0048bf69  51                   push ecx
// 0048bf6a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0048bf6d  8d530c               lea edx, [ebx + 0xc]
// 0048bf70  52                   push edx
// 0048bf71  50                   push eax
// 0048bf72  51                   push ecx
// 0048bf73  50                   push eax
// 0048bf74  8bce                 mov ecx, esi
// 0048bf76  e8e5f3ffff           call 0x48b360
// 0048bf7b  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0048bf7e  807a0e00             cmp byte ptr [edx + 0xe], 0
// 0048bf82  8bf8                 mov edi, eax
// 0048bf84  7403                 je 0x48bf89
// 0048bf86  897dec               mov dword ptr [ebp - 0x14], edi
// 0048bf89  8b03                 mov eax, dword ptr [ebx]
// 0048bf8b  57                   push edi
// 0048bf8c  50                   push eax
// 0048bf8d  8bce                 mov ecx, esi
// 0048bf8f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048bf96  e895ffffff           call 0x48bf30
// 0048bf9b  8907                 mov dword ptr [edi], eax
// 0048bf9d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0048bfa0  57                   push edi
// 0048bfa1  51                   push ecx
// 0048bfa2  8bce                 mov ecx, esi
// 0048bfa4  e887ffffff           call 0x48bf30
// 0048bfa9  894708               mov dword ptr [edi + 8], eax
// 0048bfac  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048bfaf  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0048bfb2  5f                   pop edi
// 0048bfb3  5e                   pop esi
// 0048bfb4  64890d00000000       mov dword ptr fs:[0], ecx
// 0048bfbb  5b                   pop ebx
// 0048bfbc  8be5                 mov esp, ebp
// 0048bfbe  5d                   pop ebp
// 0048bfbf  c20800               ret 8
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?_Copy@?$_Tree@V?$_Tset_traits@EU?$less@E@std@@V?$allocator@E@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@EU?$less@E@std@@V?$allocator@E@2@$0A@@std@@@2@PAU342@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
