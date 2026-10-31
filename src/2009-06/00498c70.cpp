// from server: 100% by EspClaude
// roc 2009-06 00498c70  unit: Ogre::RbxArchiveFactory  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498c70
//
// 00498c70  64a100000000         mov eax, dword ptr fs:[0]
// 00498c76  6aff                 push -1
// 00498c78  6868698500           push 0x856968
// 00498c7d  50                   push eax
// 00498c7e  64892500000000       mov dword ptr fs:[0], esp
// 00498c85  56                   push esi
// 00498c86  8b742414             mov esi, dword ptr [esp + 0x14]
// 00498c8a  57                   push edi
// 00498c8b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00498c8f  3bf7                 cmp esi, edi
// 00498c91  743b                 je 0x498cce
// 00498c93  8d4e3c               lea ecx, [esi + 0x3c]
// 00498c96  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00498c9e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00498ca4  8d4e20               lea ecx, [esi + 0x20]
// 00498ca7  c644241000           mov byte ptr [esp + 0x10], 0
// 00498cac  ff15c4e48900         call dword ptr [0x89e4c4]
// 00498cb2  8d4e04               lea ecx, [esi + 4]
// 00498cb5  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00498cbd  ff15c4e48900         call dword ptr [0x89e4c4]
// 00498cc3  83c660               add esi, 0x60
// 00498cc6  89742418             mov dword ptr [esp + 0x18], esi
// 00498cca  3bf7                 cmp esi, edi
// 00498ccc  75c5                 jne 0x498c93
// 00498cce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00498cd2  5f                   pop edi
// 00498cd3  64890d00000000       mov dword ptr fs:[0], ecx
// 00498cda  5e                   pop esi
// 00498cdb  83c40c               add esp, 0xc
// 00498cde  c3                   ret 
// copied from an identical function in another client (function ??$_Destroy_range@V?$allocator@UFileInfo@Ogre@@@std@@@std@@YAXPAUFileInfo@Ogre@@0AAV?$allocator@UFileInfo@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp