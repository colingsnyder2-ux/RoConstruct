// from server: 100% by auto
// roc 2010-06 008d86d0  unit: Ogre::RbxTextureCompositorSceneManager  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d86d0
//
// 008d86d0  55                   push ebp
// 008d86d1  8bec                 mov ebp, esp
// 008d86d3  6aff                 push -1
// 008d86d5  6891e89b00           push 0x9be891
// 008d86da  64a100000000         mov eax, dword ptr fs:[0]
// 008d86e0  50                   push eax
// 008d86e1  64892500000000       mov dword ptr fs:[0], esp
// 008d86e8  83ec0c               sub esp, 0xc
// 008d86eb  53                   push ebx
// 008d86ec  56                   push esi
// 008d86ed  8b7508               mov esi, dword ptr [ebp + 8]
// 008d86f0  57                   push edi
// 008d86f1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 008d86f4  33db                 xor ebx, ebx
// 008d86f6  8965f0               mov dword ptr [ebp - 0x10], esp
// 008d86f9  8975ec               mov dword ptr [ebp - 0x14], esi
// 008d86fc  895dfc               mov dword ptr [ebp - 4], ebx
// 008d86ff  90                   nop 
// 008d8700  3bfb                 cmp edi, ebx
// 008d8702  7646                 jbe 0x8d874a
// 008d8704  89750c               mov dword ptr [ebp + 0xc], esi
// 008d8707  8975e8               mov dword ptr [ebp - 0x18], esi
// 008d870a  c645fc01             mov byte ptr [ebp - 4], 1
// 008d870e  3bf3                 cmp esi, ebx
// 008d8710  740b                 je 0x8d871d
// 008d8712  8b4510               mov eax, dword ptr [ebp + 0x10]
// 008d8715  50                   push eax
// 008d8716  8bce                 mov ecx, esi
// 008d8718  e8f3e9ffff           call 0x8d7110
// 008d871d  4f                   dec edi
// 008d871e  83c648               add esi, 0x48
// 008d8721  885dfc               mov byte ptr [ebp - 4], bl
// 008d8724  897508               mov dword ptr [ebp + 8], esi
// 008d8727  ebd7                 jmp 0x8d8700
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??$_Uninit_fill_n@PAUPMWorkingData@ProgressiveMesh@Ogre@@IU123@V?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@std@@@std@@YAXPAUPMWorkingData@ProgressiveMesh@Ogre@@IABU123@AAV?$allocator@UPMWorkingData@ProgressiveMesh@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
