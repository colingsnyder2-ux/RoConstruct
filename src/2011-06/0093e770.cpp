// from server: 100% by auto
// roc 2011-06 0093e770  unit: Ogre::RbxMaterialAdapter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093e770
//
// 0093e770  55                   push ebp
// 0093e771  8bec                 mov ebp, esp
// 0093e773  6aff                 push -1
// 0093e775  68a11fa100           push 0xa11fa1
// 0093e77a  64a100000000         mov eax, dword ptr fs:[0]
// 0093e780  50                   push eax
// 0093e781  64892500000000       mov dword ptr fs:[0], esp
// 0093e788  83ec0c               sub esp, 0xc
// 0093e78b  53                   push ebx
// 0093e78c  56                   push esi
// 0093e78d  8b7508               mov esi, dword ptr [ebp + 8]
// 0093e790  57                   push edi
// 0093e791  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 0093e794  33db                 xor ebx, ebx
// 0093e796  8965f0               mov dword ptr [ebp - 0x10], esp
// 0093e799  8975ec               mov dword ptr [ebp - 0x14], esi
// 0093e79c  895dfc               mov dword ptr [ebp - 4], ebx
// 0093e79f  90                   nop 
// 0093e7a0  3bfb                 cmp edi, ebx
// 0093e7a2  7646                 jbe 0x93e7ea
// 0093e7a4  89750c               mov dword ptr [ebp + 0xc], esi
// 0093e7a7  8975e8               mov dword ptr [ebp - 0x18], esi
// 0093e7aa  c645fc01             mov byte ptr [ebp - 4], 1
// 0093e7ae  3bf3                 cmp esi, ebx
// 0093e7b0  740b                 je 0x93e7bd
// 0093e7b2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0093e7b5  50                   push eax
// 0093e7b6  8bce                 mov ecx, esi
// 0093e7b8  e8f394ffff           call 0x937cb0
// 0093e7bd  4f                   dec edi
// 0093e7be  83c654               add esi, 0x54
// 0093e7c1  885dfc               mov byte ptr [ebp - 4], bl
// 0093e7c4  897508               mov dword ptr [ebp + 8], esi
// 0093e7c7  ebd7                 jmp 0x93e7a0
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Uninit_fill_n@PAUMeshLodUsage@Ogre@@IU12@V?$allocator@UMeshLodUsage@Ogre@@@std@@@std@@YAXPAUMeshLodUsage@Ogre@@IABU12@AAV?$allocator@UMeshLodUsage@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
