// from server: 100% by auto
// roc 2010-06 008d6210  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6210
//
// 008d6210  55                   push ebp
// 008d6211  8bec                 mov ebp, esp
// 008d6213  6aff                 push -1
// 008d6215  6881e59b00           push 0x9be581
// 008d621a  64a100000000         mov eax, dword ptr fs:[0]
// 008d6220  50                   push eax
// 008d6221  64892500000000       mov dword ptr fs:[0], esp
// 008d6228  83ec0c               sub esp, 0xc
// 008d622b  53                   push ebx
// 008d622c  56                   push esi
// 008d622d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 008d6230  57                   push edi
// 008d6231  8b7d08               mov edi, dword ptr [ebp + 8]
// 008d6234  33db                 xor ebx, ebx
// 008d6236  8965f0               mov dword ptr [ebp - 0x10], esp
// 008d6239  8975ec               mov dword ptr [ebp - 0x14], esi
// 008d623c  895dfc               mov dword ptr [ebp - 4], ebx
// 008d623f  90                   nop 
// 008d6240  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 008d6243  7445                 je 0x8d628a
// 008d6245  897508               mov dword ptr [ebp + 8], esi
// 008d6248  8975e8               mov dword ptr [ebp - 0x18], esi
// 008d624b  c645fc01             mov byte ptr [ebp - 4], 1
// 008d624f  3bf3                 cmp esi, ebx
// 008d6251  7408                 je 0x8d625b
// 008d6253  57                   push edi
// 008d6254  8bce                 mov ecx, esi
// 008d6256  e8d5f1ffff           call 0x8d5430
// 008d625b  83c654               add esi, 0x54
// 008d625e  885dfc               mov byte ptr [ebp - 4], bl
// 008d6261  897510               mov dword ptr [ebp + 0x10], esi
// 008d6264  83c754               add edi, 0x54
// 008d6267  ebd7                 jmp 0x8d6240
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Uninit_copy@PAUMeshLodUsage@Ogre@@PAU12@V?$allocator@UMeshLodUsage@Ogre@@@std@@@std@@YAPAUMeshLodUsage@Ogre@@PAU12@00AAV?$allocator@UMeshLodUsage@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
