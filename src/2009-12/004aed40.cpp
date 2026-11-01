// from server: 100% by auto
// roc 2009-12 004aed40  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aed40
//
// 004aed40  55                   push ebp
// 004aed41  8bec                 mov ebp, esp
// 004aed43  6aff                 push -1
// 004aed45  6801109300           push 0x931001
// 004aed4a  64a100000000         mov eax, dword ptr fs:[0]
// 004aed50  50                   push eax
// 004aed51  64892500000000       mov dword ptr fs:[0], esp
// 004aed58  83ec0c               sub esp, 0xc
// 004aed5b  53                   push ebx
// 004aed5c  56                   push esi
// 004aed5d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004aed60  57                   push edi
// 004aed61  8b7d08               mov edi, dword ptr [ebp + 8]
// 004aed64  33db                 xor ebx, ebx
// 004aed66  8965f0               mov dword ptr [ebp - 0x10], esp
// 004aed69  8975ec               mov dword ptr [ebp - 0x14], esi
// 004aed6c  895dfc               mov dword ptr [ebp - 4], ebx
// 004aed6f  90                   nop 
// 004aed70  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004aed73  7445                 je 0x4aedba
// 004aed75  897508               mov dword ptr [ebp + 8], esi
// 004aed78  8975e8               mov dword ptr [ebp - 0x18], esi
// 004aed7b  c645fc01             mov byte ptr [ebp - 4], 1
// 004aed7f  3bf3                 cmp esi, ebx
// 004aed81  7408                 je 0x4aed8b
// 004aed83  57                   push edi
// 004aed84  8bce                 mov ecx, esi
// 004aed86  e885f5ffff           call 0x4ae310
// 004aed8b  83c654               add esi, 0x54
// 004aed8e  885dfc               mov byte ptr [ebp - 4], bl
// 004aed91  897510               mov dword ptr [ebp + 0x10], esi
// 004aed94  83c754               add edi, 0x54
// 004aed97  ebd7                 jmp 0x4aed70
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Uninit_copy@PAUMeshLodUsage@Ogre@@PAU12@V?$allocator@UMeshLodUsage@Ogre@@@std@@@std@@YAPAUMeshLodUsage@Ogre@@PAU12@00AAV?$allocator@UMeshLodUsage@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
