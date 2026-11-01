// from server: 100% by auto
// roc 2010-06 00902300  unit: Ogre::RbxArchive  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00902300
//
// 00902300  55                   push ebp
// 00902301  8bec                 mov ebp, esp
// 00902303  6aff                 push -1
// 00902305  6811089c00           push 0x9c0811
// 0090230a  64a100000000         mov eax, dword ptr fs:[0]
// 00902310  50                   push eax
// 00902311  64892500000000       mov dword ptr fs:[0], esp
// 00902318  83ec0c               sub esp, 0xc
// 0090231b  53                   push ebx
// 0090231c  56                   push esi
// 0090231d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00902320  57                   push edi
// 00902321  8b7d08               mov edi, dword ptr [ebp + 8]
// 00902324  33db                 xor ebx, ebx
// 00902326  8965f0               mov dword ptr [ebp - 0x10], esp
// 00902329  8975ec               mov dword ptr [ebp - 0x14], esi
// 0090232c  895dfc               mov dword ptr [ebp - 4], ebx
// 0090232f  90                   nop 
// 00902330  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 00902333  7445                 je 0x90237a
// 00902335  897508               mov dword ptr [ebp + 8], esi
// 00902338  8975e8               mov dword ptr [ebp - 0x18], esi
// 0090233b  c645fc01             mov byte ptr [ebp - 4], 1
// 0090233f  3bf3                 cmp esi, ebx
// 00902341  7408                 je 0x90234b
// 00902343  57                   push edi
// 00902344  8bce                 mov ecx, esi
// 00902346  e8a5f8ffff           call 0x901bf0
// 0090234b  83c660               add esi, 0x60
// 0090234e  885dfc               mov byte ptr [ebp - 4], bl
// 00902351  897510               mov dword ptr [ebp + 0x10], esi
// 00902354  83c760               add edi, 0x60
// 00902357  ebd7                 jmp 0x902330
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??$_Uninit_copy@PBUFileInfo@Ogre@@PAU12@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAPAUFileInfo@Ogre@@PBU12@0PAU12@AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
