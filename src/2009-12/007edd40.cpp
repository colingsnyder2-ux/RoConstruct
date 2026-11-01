// from server: 100% by auto
// roc 2009-12 007edd40  unit: W4_D3DFORMAT::?$EnumDesc  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007edd40
//
// 007edd40  6aff                 push -1
// 007edd42  6868849500           push 0x958468
// 007edd47  64a100000000         mov eax, dword ptr fs:[0]
// 007edd4d  50                   push eax
// 007edd4e  51                   push ecx
// 007edd4f  56                   push esi
// 007edd50  a10052b600           mov eax, dword ptr [0xb65200]
// 007edd55  33c4                 xor eax, esp
// 007edd57  50                   push eax
// 007edd58  8d44240c             lea eax, [esp + 0xc]
// 007edd5c  64a300000000         mov dword ptr fs:[0], eax
// 007edd62  8bf1                 mov esi, ecx
// 007edd64  89742408             mov dword ptr [esp + 8], esi
// 007edd68  6a04                 push 4
// 007edd6a  e8f15a0000           call 0x7f3860
// 007edd6f  83c404               add esp, 4
// 007edd72  85c0                 test eax, eax
// 007edd74  7404                 je 0x7edd7a
// 007edd76  8930                 mov dword ptr [eax], esi
// 007edd78  eb02                 jmp 0x7edd7c
// 007edd7a  33c0                 xor eax, eax
// 007edd7c  8906                 mov dword ptr [esi], eax
// 007edd7e  8bce                 mov ecx, esi
// 007edd80  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007edd88  e86369c5ff           call 0x4446f0
// 007edd8d  894618               mov dword ptr [esi + 0x18], eax
// 007edd90  c6401501             mov byte ptr [eax + 0x15], 1
// 007edd94  8b4618               mov eax, dword ptr [esi + 0x18]
// 007edd97  894004               mov dword ptr [eax + 4], eax
// 007edd9a  8b4618               mov eax, dword ptr [esi + 0x18]
// 007edd9d  8900                 mov dword ptr [eax], eax
// 007edd9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007edda2  894008               mov dword ptr [eax + 8], eax
// 007edda5  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007eddac  8bc6                 mov eax, esi
// 007eddae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007eddb2  64890d00000000       mov dword ptr fs:[0], ecx
// 007eddb9  59                   pop ecx
// 007eddba  5e                   pop esi
// 007eddbb  83c410               add esp, 0x10
// 007eddbe  c20800               ret 8
// library ogre-1.7.0/OgreInstancedGeometry.cpp (function ??0?$_Tree@V?$_Tmap_traits@GPAVInstancedObject@InstancedGeometry@Ogre@@U?$less@G@std@@V?$allocator@U?$pair@$$CBGPAVInstancedObject@InstancedGeometry@Ogre@@@std@@@5@$0A@@std@@@std@@QAE@ABU?$less@G@1@ABV?$allocator@U?$pair@$$CBGPAVInstancedObject@InstancedGeometry@Ogre@@@std@@@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreInstancedGeometry.cpp
