// from server: 100% by auto
// roc 2009-06 00498be0  unit: Ogre::RbxArchiveFactory  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498be0
//
// 00498be0  55                   push ebp
// 00498be1  8bec                 mov ebp, esp
// 00498be3  6aff                 push -1
// 00498be5  6841698500           push 0x856941
// 00498bea  64a100000000         mov eax, dword ptr fs:[0]
// 00498bf0  50                   push eax
// 00498bf1  64892500000000       mov dword ptr fs:[0], esp
// 00498bf8  83ec0c               sub esp, 0xc
// 00498bfb  53                   push ebx
// 00498bfc  56                   push esi
// 00498bfd  8b7508               mov esi, dword ptr [ebp + 8]
// 00498c00  57                   push edi
// 00498c01  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00498c04  33db                 xor ebx, ebx
// 00498c06  8965f0               mov dword ptr [ebp - 0x10], esp
// 00498c09  8975ec               mov dword ptr [ebp - 0x14], esi
// 00498c0c  895dfc               mov dword ptr [ebp - 4], ebx
// 00498c0f  90                   nop 
// 00498c10  3bfb                 cmp edi, ebx
// 00498c12  7646                 jbe 0x498c5a
// 00498c14  89750c               mov dword ptr [ebp + 0xc], esi
// 00498c17  8975e8               mov dword ptr [ebp - 0x18], esi
// 00498c1a  c645fc01             mov byte ptr [ebp - 4], 1
// 00498c1e  3bf3                 cmp esi, ebx
// 00498c20  740b                 je 0x498c2d
// 00498c22  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00498c25  50                   push eax
// 00498c26  8bce                 mov ecx, esi
// 00498c28  e843f6ffff           call 0x498270
// 00498c2d  4f                   dec edi
// 00498c2e  83c660               add esi, 0x60
// 00498c31  885dfc               mov byte ptr [ebp - 4], bl
// 00498c34  897508               mov dword ptr [ebp + 8], esi
// 00498c37  ebd7                 jmp 0x498c10
// library ogre-1.6.4/OgreFileSystem.cpp (function ??$_Uninit_fill_n@PAUFileInfo@Ogre@@IU12@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAXPAUFileInfo@Ogre@@IABU12@AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreFileSystem.cpp
