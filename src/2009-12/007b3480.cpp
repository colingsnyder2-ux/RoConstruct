// from server: 100% by auto
// roc 2009-12 007b3480  unit: RBX::Assembly  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3480
//
// 007b3480  8b542408             mov edx, dword ptr [esp + 8]
// 007b3484  85d2                 test edx, edx
// 007b3486  763e                 jbe 0x7b34c6
// 007b3488  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007b348c  8b442404             mov eax, dword ptr [esp + 4]
// 007b3490  56                   push esi
// 007b3491  85c0                 test eax, eax
// 007b3493  7428                 je 0x7b34bd
// 007b3495  d901                 fld dword ptr [ecx]
// 007b3497  d918                 fstp dword ptr [eax]
// 007b3499  d94104               fld dword ptr [ecx + 4]
// 007b349c  d95804               fstp dword ptr [eax + 4]
// 007b349f  d94108               fld dword ptr [ecx + 8]
// 007b34a2  d95808               fstp dword ptr [eax + 8]
// 007b34a5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007b34a8  89700c               mov dword ptr [eax + 0xc], esi
// 007b34ab  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007b34ae  897010               mov dword ptr [eax + 0x10], esi
// 007b34b1  8b7114               mov esi, dword ptr [ecx + 0x14]
// 007b34b4  897014               mov dword ptr [eax + 0x14], esi
// 007b34b7  8b7118               mov esi, dword ptr [ecx + 0x18]
// 007b34ba  897018               mov dword ptr [eax + 0x18], esi
// 007b34bd  4a                   dec edx
// 007b34be  83c01c               add eax, 0x1c
// 007b34c1  85d2                 test edx, edx
// 007b34c3  77cc                 ja 0x7b3491
// 007b34c5  5e                   pop esi
// 007b34c6  c3                   ret 
// library ogre-1.4.9/OgreEdgeListBuilder.cpp (function ??$_Uninit_fill_n@PAUCommonVertex@EdgeListBuilder@Ogre@@IU123@V?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@std@@@std@@YAXPAUCommonVertex@EdgeListBuilder@Ogre@@IABU123@AAV?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreEdgeListBuilder.cpp
