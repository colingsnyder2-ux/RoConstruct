// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00589210  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00589210
//
// 00589210  55                   push ebp
// 00589211  8bec                 mov ebp, esp
// 00589213  6aff                 push -1
// 00589215  68c8147d00           push 0x7d14c8
// 0058921a  64a100000000         mov eax, dword ptr fs:[0]
// 00589220  50                   push eax
// 00589221  64892500000000       mov dword ptr fs:[0], esp
// 00589228  83ec08               sub esp, 8
// 0058922b  53                   push ebx
// 0058922c  56                   push esi
// 0058922d  57                   push edi
// 0058922e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00589231  8bf1                 mov esi, ecx
// 00589233  6a04                 push 4
// 00589235  8975ec               mov dword ptr [ebp - 0x14], esi
// 00589238  e8e3761100           call 0x6a0920
// 0058923d  83c404               add esp, 4
// 00589240  85c0                 test eax, eax
// 00589242  7404                 je 0x589248
// 00589244  8930                 mov dword ptr [eax], esi
// 00589246  eb02                 jmp 0x58924a
// 00589248  33c0                 xor eax, eax
// 0058924a  8906                 mov dword ptr [esi], eax
// 0058924c  8bce                 mov ecx, esi
// 0058924e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00589255  e8d6860000           call 0x591930
// 0058925a  894618               mov dword ptr [esi + 0x18], eax
// 0058925d  b101                 mov cl, 1
// 0058925f  884819               mov byte ptr [eax + 0x19], cl
// 00589262  8b4618               mov eax, dword ptr [esi + 0x18]
// 00589265  894004               mov dword ptr [eax + 4], eax
// 00589268  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058926b  8900                 mov dword ptr [eax], eax
// 0058926d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00589270  894008               mov dword ptr [eax + 8], eax
// 00589273  8b4508               mov eax, dword ptr [ebp + 8]
// 00589276  884dfc               mov byte ptr [ebp - 4], cl
// 00589279  50                   push eax
// 0058927a  8bce                 mov ecx, esi
// 0058927c  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00589283  e868faffff           call 0x588cf0
// 00589288  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0058928b  5f                   pop edi
// 0058928c  8bc6                 mov eax, esi
// 0058928e  5e                   pop esi
// 0058928f  64890d00000000       mov dword ptr fs:[0], ecx
// 00589296  5b                   pop ebx
// 00589297  8be5                 mov esp, ebp
// 00589299  5d                   pop ebp
// 0058929a  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
