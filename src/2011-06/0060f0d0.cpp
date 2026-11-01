// from server: 100% by auto
// roc 2011-06 0060f0d0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0060f0d0
//
// 0060f0d0  55                   push ebp
// 0060f0d1  8bec                 mov ebp, esp
// 0060f0d3  6aff                 push -1
// 0060f0d5  68d0839e00           push 0x9e83d0
// 0060f0da  64a100000000         mov eax, dword ptr fs:[0]
// 0060f0e0  50                   push eax
// 0060f0e1  64892500000000       mov dword ptr fs:[0], esp
// 0060f0e8  83ec08               sub esp, 8
// 0060f0eb  53                   push ebx
// 0060f0ec  56                   push esi
// 0060f0ed  57                   push edi
// 0060f0ee  8bf1                 mov esi, ecx
// 0060f0f0  8965f0               mov dword ptr [ebp - 0x10], esp
// 0060f0f3  8975ec               mov dword ptr [ebp - 0x14], esi
// 0060f0f6  e8a575eeff           call 0x4f66a0
// 0060f0fb  894604               mov dword ptr [esi + 4], eax
// 0060f0fe  c6401901             mov byte ptr [eax + 0x19], 1
// 0060f102  8b4604               mov eax, dword ptr [esi + 4]
// 0060f105  894004               mov dword ptr [eax + 4], eax
// 0060f108  8b4604               mov eax, dword ptr [esi + 4]
// 0060f10b  8900                 mov dword ptr [eax], eax
// 0060f10d  8b4604               mov eax, dword ptr [esi + 4]
// 0060f110  894008               mov dword ptr [eax + 8], eax
// 0060f113  8b4508               mov eax, dword ptr [ebp + 8]
// 0060f116  50                   push eax
// 0060f117  8bce                 mov ecx, esi
// 0060f119  c7460800000000       mov dword ptr [esi + 8], 0
// 0060f120  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0060f127  e8b4fdffff           call 0x60eee0
// 0060f12c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0060f12f  5f                   pop edi
// 0060f130  8bc6                 mov eax, esi
// 0060f132  5e                   pop esi
// 0060f133  64890d00000000       mov dword ptr fs:[0], ecx
// 0060f13a  5b                   pop ebx
// 0060f13b  8be5                 mov esp, ebp
// 0060f13d  5d                   pop ebp
// 0060f13e  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
