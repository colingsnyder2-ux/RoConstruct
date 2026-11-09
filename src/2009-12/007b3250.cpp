// from server: 100% by auto
// roc 2009-12 007b3250  unit: RBX::Assembly  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3250
//
// 007b3250  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b3254  8b542408             mov edx, dword ptr [esp + 8]
// 007b3258  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b325c  3bca                 cmp ecx, edx
// 007b325e  7438                 je 0x7b3298
// 007b3260  56                   push esi
// 007b3261  85c0                 test eax, eax
// 007b3263  7428                 je 0x7b328d
// 007b3265  d901                 fld dword ptr [ecx]
// 007b3267  d918                 fstp dword ptr [eax]
// 007b3269  d94104               fld dword ptr [ecx + 4]
// 007b326c  d95804               fstp dword ptr [eax + 4]
// 007b326f  d94108               fld dword ptr [ecx + 8]
// 007b3272  d95808               fstp dword ptr [eax + 8]
// 007b3275  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007b3278  89700c               mov dword ptr [eax + 0xc], esi
// 007b327b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007b327e  897010               mov dword ptr [eax + 0x10], esi
// 007b3281  8b7114               mov esi, dword ptr [ecx + 0x14]
// 007b3284  897014               mov dword ptr [eax + 0x14], esi
// 007b3287  8b7118               mov esi, dword ptr [ecx + 0x18]
// 007b328a  897018               mov dword ptr [eax + 0x18], esi
// 007b328d  83c11c               add ecx, 0x1c
// 007b3290  83c01c               add eax, 0x1c
// 007b3293  3bca                 cmp ecx, edx
// 007b3295  75ca                 jne 0x7b3261
// 007b3297  5e                   pop esi
// 007b3298  c3                   ret 
// library ogre-1.4.9/OgreEdgeListBuilder.cpp (function ??$_Uninit_copy@PBUCommonVertex@EdgeListBuilder@Ogre@@PAU123@V?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@std@@@std@@YAPAUCommonVertex@EdgeListBuilder@Ogre@@PBU123@0PAU123@AAV?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreEdgeListBuilder.cpp
