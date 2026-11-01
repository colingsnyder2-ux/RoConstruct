// from server: 100% by auto
// roc 2009-06 0061a100  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061a100
//
// 0061a100  55                   push ebp
// 0061a101  8bec                 mov ebp, esp
// 0061a103  6aff                 push -1
// 0061a105  68a8828600           push 0x8682a8
// 0061a10a  64a100000000         mov eax, dword ptr fs:[0]
// 0061a110  50                   push eax
// 0061a111  64892500000000       mov dword ptr fs:[0], esp
// 0061a118  83ec08               sub esp, 8
// 0061a11b  53                   push ebx
// 0061a11c  56                   push esi
// 0061a11d  57                   push edi
// 0061a11e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0061a121  8bf1                 mov esi, ecx
// 0061a123  6a04                 push 4
// 0061a125  8975ec               mov dword ptr [ebp - 0x14], esi
// 0061a128  e80be90f00           call 0x718a38
// 0061a12d  83c404               add esp, 4
// 0061a130  85c0                 test eax, eax
// 0061a132  7404                 je 0x61a138
// 0061a134  8930                 mov dword ptr [eax], esi
// 0061a136  eb02                 jmp 0x61a13a
// 0061a138  33c0                 xor eax, eax
// 0061a13a  8906                 mov dword ptr [esi], eax
// 0061a13c  8bce                 mov ecx, esi
// 0061a13e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0061a145  e8e61efeff           call 0x5fc030
// 0061a14a  894618               mov dword ptr [esi + 0x18], eax
// 0061a14d  b101                 mov cl, 1
// 0061a14f  884819               mov byte ptr [eax + 0x19], cl
// 0061a152  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061a155  894004               mov dword ptr [eax + 4], eax
// 0061a158  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061a15b  8900                 mov dword ptr [eax], eax
// 0061a15d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061a160  894008               mov dword ptr [eax + 8], eax
// 0061a163  8b4508               mov eax, dword ptr [ebp + 8]
// 0061a166  884dfc               mov byte ptr [ebp - 4], cl
// 0061a169  50                   push eax
// 0061a16a  8bce                 mov ecx, esi
// 0061a16c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0061a173  e8e8fcffff           call 0x619e60
// 0061a178  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0061a17b  5f                   pop edi
// 0061a17c  8bc6                 mov eax, esi
// 0061a17e  5e                   pop esi
// 0061a17f  64890d00000000       mov dword ptr fs:[0], ecx
// 0061a186  5b                   pop ebx
// 0061a187  8be5                 mov esp, ebp
// 0061a189  5d                   pop ebp
// 0061a18a  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
