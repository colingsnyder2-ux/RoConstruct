// from server: 100% by auto
// roc 2009-12 004b4850  unit: Ogre::RbxMaterialAdapter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b4850
//
// 004b4850  55                   push ebp
// 004b4851  8bec                 mov ebp, esp
// 004b4853  6aff                 push -1
// 004b4855  68d1179300           push 0x9317d1
// 004b485a  64a100000000         mov eax, dword ptr fs:[0]
// 004b4860  50                   push eax
// 004b4861  64892500000000       mov dword ptr fs:[0], esp
// 004b4868  83ec0c               sub esp, 0xc
// 004b486b  53                   push ebx
// 004b486c  56                   push esi
// 004b486d  8b7508               mov esi, dword ptr [ebp + 8]
// 004b4870  57                   push edi
// 004b4871  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004b4874  33db                 xor ebx, ebx
// 004b4876  8965f0               mov dword ptr [ebp - 0x10], esp
// 004b4879  8975ec               mov dword ptr [ebp - 0x14], esi
// 004b487c  895dfc               mov dword ptr [ebp - 4], ebx
// 004b487f  90                   nop 
// 004b4880  3bfb                 cmp edi, ebx
// 004b4882  7646                 jbe 0x4b48ca
// 004b4884  89750c               mov dword ptr [ebp + 0xc], esi
// 004b4887  8975e8               mov dword ptr [ebp - 0x18], esi
// 004b488a  c645fc01             mov byte ptr [ebp - 4], 1
// 004b488e  3bf3                 cmp esi, ebx
// 004b4890  740b                 je 0x4b489d
// 004b4892  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004b4895  50                   push eax
// 004b4896  8bce                 mov ecx, esi
// 004b4898  e8739affff           call 0x4ae310
// 004b489d  4f                   dec edi
// 004b489e  83c654               add esi, 0x54
// 004b48a1  885dfc               mov byte ptr [ebp - 4], bl
// 004b48a4  897508               mov dword ptr [ebp + 8], esi
// 004b48a7  ebd7                 jmp 0x4b4880
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Uninit_fill_n@PAUMeshLodUsage@Ogre@@IU12@V?$allocator@UMeshLodUsage@Ogre@@@std@@@std@@YAXPAUMeshLodUsage@Ogre@@IABU12@AAV?$allocator@UMeshLodUsage@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
