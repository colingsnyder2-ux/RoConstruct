// from server: 100% by auto
// roc 2010-06 005eb5c0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eb5c0
//
// 005eb5c0  55                   push ebp
// 005eb5c1  8bec                 mov ebp, esp
// 005eb5c3  6aff                 push -1
// 005eb5c5  68c8809900           push 0x9980c8
// 005eb5ca  64a100000000         mov eax, dword ptr fs:[0]
// 005eb5d0  50                   push eax
// 005eb5d1  64892500000000       mov dword ptr fs:[0], esp
// 005eb5d8  83ec08               sub esp, 8
// 005eb5db  53                   push ebx
// 005eb5dc  56                   push esi
// 005eb5dd  57                   push edi
// 005eb5de  8965f0               mov dword ptr [ebp - 0x10], esp
// 005eb5e1  8bf1                 mov esi, ecx
// 005eb5e3  6a04                 push 4
// 005eb5e5  8975ec               mov dword ptr [ebp - 0x14], esi
// 005eb5e8  e8b3c31b00           call 0x7a79a0
// 005eb5ed  83c404               add esp, 4
// 005eb5f0  85c0                 test eax, eax
// 005eb5f2  7404                 je 0x5eb5f8
// 005eb5f4  8930                 mov dword ptr [eax], esi
// 005eb5f6  eb02                 jmp 0x5eb5fa
// 005eb5f8  33c0                 xor eax, eax
// 005eb5fa  8906                 mov dword ptr [esi], eax
// 005eb5fc  8bce                 mov ecx, esi
// 005eb5fe  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005eb605  e8d6c5efff           call 0x4e7be0
// 005eb60a  894618               mov dword ptr [esi + 0x18], eax
// 005eb60d  b101                 mov cl, 1
// 005eb60f  884819               mov byte ptr [eax + 0x19], cl
// 005eb612  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb615  894004               mov dword ptr [eax + 4], eax
// 005eb618  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb61b  8900                 mov dword ptr [eax], eax
// 005eb61d  8b4618               mov eax, dword ptr [esi + 0x18]
// 005eb620  894008               mov dword ptr [eax + 8], eax
// 005eb623  8b4508               mov eax, dword ptr [ebp + 8]
// 005eb626  884dfc               mov byte ptr [ebp - 4], cl
// 005eb629  50                   push eax
// 005eb62a  8bce                 mov ecx, esi
// 005eb62c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005eb633  e8e8fcffff           call 0x5eb320
// 005eb638  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005eb63b  5f                   pop edi
// 005eb63c  8bc6                 mov eax, esi
// 005eb63e  5e                   pop esi
// 005eb63f  64890d00000000       mov dword ptr fs:[0], ecx
// 005eb646  5b                   pop ebx
// 005eb647  8be5                 mov esp, ebp
// 005eb649  5d                   pop ebp
// 005eb64a  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
