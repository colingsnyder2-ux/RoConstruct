// from server: 100% by auto
// roc 2009-12 005b2280  unit: RBX::BrickBuilder  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b2280
//
// 005b2280  55                   push ebp
// 005b2281  8bec                 mov ebp, esp
// 005b2283  6aff                 push -1
// 005b2285  68b1ca9300           push 0x93cab1
// 005b228a  64a100000000         mov eax, dword ptr fs:[0]
// 005b2290  50                   push eax
// 005b2291  64892500000000       mov dword ptr fs:[0], esp
// 005b2298  83ec08               sub esp, 8
// 005b229b  53                   push ebx
// 005b229c  56                   push esi
// 005b229d  57                   push edi
// 005b229e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005b22a1  6a64                 push 0x64
// 005b22a3  e8b8152400           call 0x7f3860
// 005b22a8  8bf0                 mov esi, eax
// 005b22aa  83c404               add esp, 4
// 005b22ad  8975ec               mov dword ptr [ebp - 0x14], esi
// 005b22b0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005b22b7  85f6                 test esi, esi
// 005b22b9  7405                 je 0x5b22c0
// 005b22bb  8b4508               mov eax, dword ptr [ebp + 8]
// 005b22be  8906                 mov dword ptr [esi], eax
// 005b22c0  8d4604               lea eax, [esi + 4]
// 005b22c3  85c0                 test eax, eax
// 005b22c5  7405                 je 0x5b22cc
// 005b22c7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005b22ca  8908                 mov dword ptr [eax], ecx
// 005b22cc  8d4e08               lea ecx, [esi + 8]
// 005b22cf  894d08               mov dword ptr [ebp + 8], ecx
// 005b22d2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 005b22d5  c645fc01             mov byte ptr [ebp - 4], 1
// 005b22d9  85c9                 test ecx, ecx
// 005b22db  7409                 je 0x5b22e6
// 005b22dd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005b22e0  52                   push edx
// 005b22e1  e8eaf8ffff           call 0x5b1bd0
// 005b22e6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b22e9  5f                   pop edi
// 005b22ea  8bc6                 mov eax, esi
// 005b22ec  5e                   pop esi
// 005b22ed  64890d00000000       mov dword ptr fs:[0], ecx
// 005b22f4  5b                   pop ebx
// 005b22f5  8be5                 mov esp, ebp
// 005b22f7  5d                   pop ebp
// 005b22f8  c20c00               ret 0xc
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@PAU342@0ABUResourceDeclaration@ResourceGroupManager@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
