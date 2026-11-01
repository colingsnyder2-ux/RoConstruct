// from server: 100% by auto
// roc 2010-06 00902570  unit: Ogre::RbxArchiveFactory  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00902570
//
// 00902570  55                   push ebp
// 00902571  8bec                 mov ebp, esp
// 00902573  6aff                 push -1
// 00902575  68b1089c00           push 0x9c08b1
// 0090257a  64a100000000         mov eax, dword ptr fs:[0]
// 00902580  50                   push eax
// 00902581  64892500000000       mov dword ptr fs:[0], esp
// 00902588  83ec0c               sub esp, 0xc
// 0090258b  53                   push ebx
// 0090258c  56                   push esi
// 0090258d  8b7508               mov esi, dword ptr [ebp + 8]
// 00902590  57                   push edi
// 00902591  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00902594  33db                 xor ebx, ebx
// 00902596  8965f0               mov dword ptr [ebp - 0x10], esp
// 00902599  8975ec               mov dword ptr [ebp - 0x14], esi
// 0090259c  895dfc               mov dword ptr [ebp - 4], ebx
// 0090259f  90                   nop 
// 009025a0  3bfb                 cmp edi, ebx
// 009025a2  7646                 jbe 0x9025ea
// 009025a4  89750c               mov dword ptr [ebp + 0xc], esi
// 009025a7  8975e8               mov dword ptr [ebp - 0x18], esi
// 009025aa  c645fc01             mov byte ptr [ebp - 4], 1
// 009025ae  3bf3                 cmp esi, ebx
// 009025b0  740b                 je 0x9025bd
// 009025b2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 009025b5  50                   push eax
// 009025b6  8bce                 mov ecx, esi
// 009025b8  e833f6ffff           call 0x901bf0
// 009025bd  4f                   dec edi
// 009025be  83c660               add esi, 0x60
// 009025c1  885dfc               mov byte ptr [ebp - 4], bl
// 009025c4  897508               mov dword ptr [ebp + 8], esi
// 009025c7  ebd7                 jmp 0x9025a0
// library ogre-1.6.4/OgreFileSystem.cpp (function ??$_Uninit_fill_n@PAUFileInfo@Ogre@@IU12@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAXPAUFileInfo@Ogre@@IABU12@AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreFileSystem.cpp
