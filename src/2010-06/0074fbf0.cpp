// from server: 100% by auto
// roc 2010-06 0074fbf0  unit: RBX::Humanoid  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0074fbf0
//
// 0074fbf0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0074fbf4  8b542408             mov edx, dword ptr [esp + 8]
// 0074fbf8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074fbfc  3bca                 cmp ecx, edx
// 0074fbfe  7438                 je 0x74fc38
// 0074fc00  56                   push esi
// 0074fc01  85c0                 test eax, eax
// 0074fc03  7428                 je 0x74fc2d
// 0074fc05  d901                 fld dword ptr [ecx]
// 0074fc07  d918                 fstp dword ptr [eax]
// 0074fc09  d94104               fld dword ptr [ecx + 4]
// 0074fc0c  d95804               fstp dword ptr [eax + 4]
// 0074fc0f  d94108               fld dword ptr [ecx + 8]
// 0074fc12  d95808               fstp dword ptr [eax + 8]
// 0074fc15  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0074fc18  89700c               mov dword ptr [eax + 0xc], esi
// 0074fc1b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0074fc1e  897010               mov dword ptr [eax + 0x10], esi
// 0074fc21  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0074fc24  897014               mov dword ptr [eax + 0x14], esi
// 0074fc27  8b7118               mov esi, dword ptr [ecx + 0x18]
// 0074fc2a  897018               mov dword ptr [eax + 0x18], esi
// 0074fc2d  83c11c               add ecx, 0x1c
// 0074fc30  83c01c               add eax, 0x1c
// 0074fc33  3bca                 cmp ecx, edx
// 0074fc35  75ca                 jne 0x74fc01
// 0074fc37  5e                   pop esi
// 0074fc38  c3                   ret 
// library ogre-1.4.9/OgreEdgeListBuilder.cpp (function ??$_Uninit_copy@PBUCommonVertex@EdgeListBuilder@Ogre@@PAU123@V?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@std@@@std@@YAPAUCommonVertex@EdgeListBuilder@Ogre@@PBU123@0PAU123@AAV?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreEdgeListBuilder.cpp
