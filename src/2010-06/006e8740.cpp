// from server: 100% by auto
// roc 2010-06 006e8740  unit: RBX::VInstance::?$NonFactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e8740
//
// 006e8740  55                   push ebp
// 006e8741  8bec                 mov ebp, esp
// 006e8743  6aff                 push -1
// 006e8745  68c85c9a00           push 0x9a5cc8
// 006e874a  64a100000000         mov eax, dword ptr fs:[0]
// 006e8750  50                   push eax
// 006e8751  64892500000000       mov dword ptr fs:[0], esp
// 006e8758  83ec08               sub esp, 8
// 006e875b  53                   push ebx
// 006e875c  56                   push esi
// 006e875d  57                   push edi
// 006e875e  8965f0               mov dword ptr [ebp - 0x10], esp
// 006e8761  8bf1                 mov esi, ecx
// 006e8763  6a04                 push 4
// 006e8765  8975ec               mov dword ptr [ebp - 0x14], esi
// 006e8768  e833f20b00           call 0x7a79a0
// 006e876d  83c404               add esp, 4
// 006e8770  85c0                 test eax, eax
// 006e8772  7404                 je 0x6e8778
// 006e8774  8930                 mov dword ptr [eax], esi
// 006e8776  eb02                 jmp 0x6e877a
// 006e8778  33c0                 xor eax, eax
// 006e877a  8906                 mov dword ptr [esi], eax
// 006e877c  8bce                 mov ecx, esi
// 006e877e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006e8785  e8d6f3ffff           call 0x6e7b60
// 006e878a  894618               mov dword ptr [esi + 0x18], eax
// 006e878d  b101                 mov cl, 1
// 006e878f  884811               mov byte ptr [eax + 0x11], cl
// 006e8792  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e8795  894004               mov dword ptr [eax + 4], eax
// 006e8798  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e879b  8900                 mov dword ptr [eax], eax
// 006e879d  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e87a0  894008               mov dword ptr [eax + 8], eax
// 006e87a3  8b4508               mov eax, dword ptr [ebp + 8]
// 006e87a6  884dfc               mov byte ptr [ebp - 4], cl
// 006e87a9  50                   push eax
// 006e87aa  8bce                 mov ecx, esi
// 006e87ac  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e87b3  e8e876f2ff           call 0x60fea0
// 006e87b8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006e87bb  5f                   pop edi
// 006e87bc  8bc6                 mov eax, esi
// 006e87be  5e                   pop esi
// 006e87bf  64890d00000000       mov dword ptr fs:[0], ecx
// 006e87c6  5b                   pop ebx
// 006e87c7  8be5                 mov esp, ebp
// 006e87c9  5d                   pop ebp
// 006e87ca  c20400               ret 4
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??0?$_Tree@V?$_Tset_traits@PAVPMVertex@ProgressiveMesh@Ogre@@U?$less@PAVPMVertex@ProgressiveMesh@Ogre@@@std@@V?$allocator@PAVPMVertex@ProgressiveMesh@Ogre@@@5@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
