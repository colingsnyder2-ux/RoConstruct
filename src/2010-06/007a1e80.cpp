// from server: 100% by auto
// roc 2010-06 007a1e80  unit: W4_D3DFORMAT::?$EnumDesc  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007a1e80
//
// 007a1e80  6aff                 push -1
// 007a1e82  6898e39a00           push 0x9ae398
// 007a1e87  64a100000000         mov eax, dword ptr fs:[0]
// 007a1e8d  50                   push eax
// 007a1e8e  51                   push ecx
// 007a1e8f  56                   push esi
// 007a1e90  a1b05fbe00           mov eax, dword ptr [0xbe5fb0]
// 007a1e95  33c4                 xor eax, esp
// 007a1e97  50                   push eax
// 007a1e98  8d44240c             lea eax, [esp + 0xc]
// 007a1e9c  64a300000000         mov dword ptr fs:[0], eax
// 007a1ea2  8bf1                 mov esi, ecx
// 007a1ea4  89742408             mov dword ptr [esp + 8], esi
// 007a1ea8  6a04                 push 4
// 007a1eaa  e8f15a0000           call 0x7a79a0
// 007a1eaf  83c404               add esp, 4
// 007a1eb2  85c0                 test eax, eax
// 007a1eb4  7404                 je 0x7a1eba
// 007a1eb6  8930                 mov dword ptr [eax], esi
// 007a1eb8  eb02                 jmp 0x7a1ebc
// 007a1eba  33c0                 xor eax, eax
// 007a1ebc  8906                 mov dword ptr [esi], eax
// 007a1ebe  8bce                 mov ecx, esi
// 007a1ec0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007a1ec8  e8e349d3ff           call 0x4d68b0
// 007a1ecd  894618               mov dword ptr [esi + 0x18], eax
// 007a1ed0  c6401501             mov byte ptr [eax + 0x15], 1
// 007a1ed4  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a1ed7  894004               mov dword ptr [eax + 4], eax
// 007a1eda  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a1edd  8900                 mov dword ptr [eax], eax
// 007a1edf  8b4618               mov eax, dword ptr [esi + 0x18]
// 007a1ee2  894008               mov dword ptr [eax + 8], eax
// 007a1ee5  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007a1eec  8bc6                 mov eax, esi
// 007a1eee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007a1ef2  64890d00000000       mov dword ptr fs:[0], ecx
// 007a1ef9  59                   pop ecx
// 007a1efa  5e                   pop esi
// 007a1efb  83c410               add esp, 0x10
// 007a1efe  c20800               ret 8
// library ogre-1.7.0/OgreInstancedGeometry.cpp (function ??0?$_Tree@V?$_Tmap_traits@GPAVInstancedObject@InstancedGeometry@Ogre@@U?$less@G@std@@V?$allocator@U?$pair@$$CBGPAVInstancedObject@InstancedGeometry@Ogre@@@std@@@5@$0A@@std@@@std@@QAE@ABU?$less@G@1@ABV?$allocator@U?$pair@$$CBGPAVInstancedObject@InstancedGeometry@Ogre@@@std@@@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreInstancedGeometry.cpp
