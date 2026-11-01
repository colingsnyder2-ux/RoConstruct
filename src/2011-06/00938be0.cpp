// from server: 100% by auto
// roc 2011-06 00938be0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00938be0
//
// 00938be0  55                   push ebp
// 00938be1  8bec                 mov ebp, esp
// 00938be3  6aff                 push -1
// 00938be5  68f117a100           push 0xa117f1
// 00938bea  64a100000000         mov eax, dword ptr fs:[0]
// 00938bf0  50                   push eax
// 00938bf1  64892500000000       mov dword ptr fs:[0], esp
// 00938bf8  83ec0c               sub esp, 0xc
// 00938bfb  53                   push ebx
// 00938bfc  56                   push esi
// 00938bfd  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00938c00  57                   push edi
// 00938c01  8b7d08               mov edi, dword ptr [ebp + 8]
// 00938c04  33db                 xor ebx, ebx
// 00938c06  8965f0               mov dword ptr [ebp - 0x10], esp
// 00938c09  8975ec               mov dword ptr [ebp - 0x14], esi
// 00938c0c  895dfc               mov dword ptr [ebp - 4], ebx
// 00938c0f  90                   nop 
// 00938c10  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 00938c13  7445                 je 0x938c5a
// 00938c15  897508               mov dword ptr [ebp + 8], esi
// 00938c18  8975e8               mov dword ptr [ebp - 0x18], esi
// 00938c1b  c645fc01             mov byte ptr [ebp - 4], 1
// 00938c1f  3bf3                 cmp esi, ebx
// 00938c21  7408                 je 0x938c2b
// 00938c23  57                   push edi
// 00938c24  8bce                 mov ecx, esi
// 00938c26  e885f0ffff           call 0x937cb0
// 00938c2b  83c654               add esi, 0x54
// 00938c2e  885dfc               mov byte ptr [ebp - 4], bl
// 00938c31  897510               mov dword ptr [ebp + 0x10], esi
// 00938c34  83c754               add edi, 0x54
// 00938c37  ebd7                 jmp 0x938c10
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Uninit_copy@PAUMeshLodUsage@Ogre@@PAU12@V?$allocator@UMeshLodUsage@Ogre@@@std@@@std@@YAPAUMeshLodUsage@Ogre@@PAU12@00AAV?$allocator@UMeshLodUsage@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
