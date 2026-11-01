// from server: 100% by auto
// roc 2010-06 00970260  unit: seg_00970000  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00970260
//
// 00970260  55                   push ebp
// 00970261  8bec                 mov ebp, esp
// 00970263  6aff                 push -1
// 00970265  6821289c00           push 0x9c2821
// 0097026a  64a100000000         mov eax, dword ptr fs:[0]
// 00970270  50                   push eax
// 00970271  64892500000000       mov dword ptr fs:[0], esp
// 00970278  83ec08               sub esp, 8
// 0097027b  53                   push ebx
// 0097027c  56                   push esi
// 0097027d  57                   push edi
// 0097027e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00970281  6a64                 push 0x64
// 00970283  e81877e3ff           call 0x7a79a0
// 00970288  8bf0                 mov esi, eax
// 0097028a  83c404               add esp, 4
// 0097028d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00970290  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00970297  85f6                 test esi, esi
// 00970299  7405                 je 0x9702a0
// 0097029b  8b4508               mov eax, dword ptr [ebp + 8]
// 0097029e  8906                 mov dword ptr [esi], eax
// 009702a0  8d4604               lea eax, [esi + 4]
// 009702a3  85c0                 test eax, eax
// 009702a5  7405                 je 0x9702ac
// 009702a7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 009702aa  8908                 mov dword ptr [eax], ecx
// 009702ac  8d4e08               lea ecx, [esi + 8]
// 009702af  894d08               mov dword ptr [ebp + 8], ecx
// 009702b2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 009702b5  c645fc01             mov byte ptr [ebp - 4], 1
// 009702b9  85c9                 test ecx, ecx
// 009702bb  7409                 je 0x9702c6
// 009702bd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 009702c0  52                   push edx
// 009702c1  e8eaf8ffff           call 0x96fbb0
// 009702c6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 009702c9  5f                   pop edi
// 009702ca  8bc6                 mov eax, esi
// 009702cc  5e                   pop esi
// 009702cd  64890d00000000       mov dword ptr fs:[0], ecx
// 009702d4  5b                   pop ebx
// 009702d5  8be5                 mov esp, ebp
// 009702d7  5d                   pop ebp
// 009702d8  c20c00               ret 0xc
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@PAU342@0ABUResourceDeclaration@ResourceGroupManager@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
