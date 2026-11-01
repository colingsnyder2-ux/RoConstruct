// from server: 100% by auto
// roc 2009-12 00684400  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00684400
//
// 00684400  55                   push ebp
// 00684401  8bec                 mov ebp, esp
// 00684403  6aff                 push -1
// 00684405  68c85c9400           push 0x945cc8
// 0068440a  64a100000000         mov eax, dword ptr fs:[0]
// 00684410  50                   push eax
// 00684411  64892500000000       mov dword ptr fs:[0], esp
// 00684418  83ec08               sub esp, 8
// 0068441b  53                   push ebx
// 0068441c  56                   push esi
// 0068441d  57                   push edi
// 0068441e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00684421  8bf1                 mov esi, ecx
// 00684423  6a04                 push 4
// 00684425  8975ec               mov dword ptr [ebp - 0x14], esi
// 00684428  e833f41600           call 0x7f3860
// 0068442d  83c404               add esp, 4
// 00684430  85c0                 test eax, eax
// 00684432  7404                 je 0x684438
// 00684434  8930                 mov dword ptr [eax], esi
// 00684436  eb02                 jmp 0x68443a
// 00684438  33c0                 xor eax, eax
// 0068443a  8906                 mov dword ptr [esi], eax
// 0068443c  8bce                 mov ecx, esi
// 0068443e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00684445  e886f6daff           call 0x433ad0
// 0068444a  894618               mov dword ptr [esi + 0x18], eax
// 0068444d  b101                 mov cl, 1
// 0068444f  884819               mov byte ptr [eax + 0x19], cl
// 00684452  8b4618               mov eax, dword ptr [esi + 0x18]
// 00684455  894004               mov dword ptr [eax + 4], eax
// 00684458  8b4618               mov eax, dword ptr [esi + 0x18]
// 0068445b  8900                 mov dword ptr [eax], eax
// 0068445d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00684460  894008               mov dword ptr [eax + 8], eax
// 00684463  8b4508               mov eax, dword ptr [ebp + 8]
// 00684466  884dfc               mov byte ptr [ebp - 4], cl
// 00684469  50                   push eax
// 0068446a  8bce                 mov ecx, esi
// 0068446c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00684473  e8e8fcffff           call 0x684160
// 00684478  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0068447b  5f                   pop edi
// 0068447c  8bc6                 mov eax, esi
// 0068447e  5e                   pop esi
// 0068447f  64890d00000000       mov dword ptr fs:[0], ecx
// 00684486  5b                   pop ebx
// 00684487  8be5                 mov esp, ebp
// 00684489  5d                   pop ebp
// 0068448a  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
