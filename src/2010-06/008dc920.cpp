// from server: 100% by auto
// roc 2010-06 008dc920  unit: Ogre::RbxMaterialAdapter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dc920
//
// 008dc920  55                   push ebp
// 008dc921  8bec                 mov ebp, esp
// 008dc923  6aff                 push -1
// 008dc925  6811ee9b00           push 0x9bee11
// 008dc92a  64a100000000         mov eax, dword ptr fs:[0]
// 008dc930  50                   push eax
// 008dc931  64892500000000       mov dword ptr fs:[0], esp
// 008dc938  83ec0c               sub esp, 0xc
// 008dc93b  53                   push ebx
// 008dc93c  56                   push esi
// 008dc93d  8b7508               mov esi, dword ptr [ebp + 8]
// 008dc940  57                   push edi
// 008dc941  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 008dc944  33db                 xor ebx, ebx
// 008dc946  8965f0               mov dword ptr [ebp - 0x10], esp
// 008dc949  8975ec               mov dword ptr [ebp - 0x14], esi
// 008dc94c  895dfc               mov dword ptr [ebp - 4], ebx
// 008dc94f  90                   nop 
// 008dc950  3bfb                 cmp edi, ebx
// 008dc952  7646                 jbe 0x8dc99a
// 008dc954  89750c               mov dword ptr [ebp + 0xc], esi
// 008dc957  8975e8               mov dword ptr [ebp - 0x18], esi
// 008dc95a  c645fc01             mov byte ptr [ebp - 4], 1
// 008dc95e  3bf3                 cmp esi, ebx
// 008dc960  740b                 je 0x8dc96d
// 008dc962  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008dc965  50                   push eax
// 008dc966  8bce                 mov ecx, esi
// 008dc968  e8c38affff           call 0x8d5430
// 008dc96d  4f                   dec edi
// 008dc96e  83c654               add esi, 0x54
// 008dc971  885dfc               mov byte ptr [ebp - 4], bl
// 008dc974  897508               mov dword ptr [ebp + 8], esi
// 008dc977  ebd7                 jmp 0x8dc950
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Uninit_fill_n@PAUMeshLodUsage@Ogre@@IU12@V?$allocator@UMeshLodUsage@Ogre@@@std@@@std@@YAXPAUMeshLodUsage@Ogre@@IABU12@AAV?$allocator@UMeshLodUsage@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
