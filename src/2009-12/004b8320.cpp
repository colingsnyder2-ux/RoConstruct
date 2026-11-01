// from server: 100% by auto
// roc 2009-12 004b8320  unit: Ogre::RbxArchiveFactory  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b8320
//
// 004b8320  55                   push ebp
// 004b8321  8bec                 mov ebp, esp
// 004b8323  6aff                 push -1
// 004b8325  68311d9300           push 0x931d31
// 004b832a  64a100000000         mov eax, dword ptr fs:[0]
// 004b8330  50                   push eax
// 004b8331  64892500000000       mov dword ptr fs:[0], esp
// 004b8338  83ec0c               sub esp, 0xc
// 004b833b  53                   push ebx
// 004b833c  56                   push esi
// 004b833d  8b7508               mov esi, dword ptr [ebp + 8]
// 004b8340  57                   push edi
// 004b8341  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004b8344  33db                 xor ebx, ebx
// 004b8346  8965f0               mov dword ptr [ebp - 0x10], esp
// 004b8349  8975ec               mov dword ptr [ebp - 0x14], esi
// 004b834c  895dfc               mov dword ptr [ebp - 4], ebx
// 004b834f  90                   nop 
// 004b8350  3bfb                 cmp edi, ebx
// 004b8352  7646                 jbe 0x4b839a
// 004b8354  89750c               mov dword ptr [ebp + 0xc], esi
// 004b8357  8975e8               mov dword ptr [ebp - 0x18], esi
// 004b835a  c645fc01             mov byte ptr [ebp - 4], 1
// 004b835e  3bf3                 cmp esi, ebx
// 004b8360  740b                 je 0x4b836d
// 004b8362  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004b8365  50                   push eax
// 004b8366  8bce                 mov ecx, esi
// 004b8368  e853f6ffff           call 0x4b79c0
// 004b836d  4f                   dec edi
// 004b836e  83c660               add esi, 0x60
// 004b8371  885dfc               mov byte ptr [ebp - 4], bl
// 004b8374  897508               mov dword ptr [ebp + 8], esi
// 004b8377  ebd7                 jmp 0x4b8350
// library ogre-1.6.4/OgreFileSystem.cpp (function ??$_Uninit_fill_n@PAUFileInfo@Ogre@@IU12@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAXPAUFileInfo@Ogre@@IABU12@AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreFileSystem.cpp
