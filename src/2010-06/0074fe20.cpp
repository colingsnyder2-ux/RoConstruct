// from server: 100% by auto
// roc 2010-06 0074fe20  unit: RBX::Humanoid  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0074fe20
//
// 0074fe20  8b542408             mov edx, dword ptr [esp + 8]
// 0074fe24  85d2                 test edx, edx
// 0074fe26  763e                 jbe 0x74fe66
// 0074fe28  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0074fe2c  8b442404             mov eax, dword ptr [esp + 4]
// 0074fe30  56                   push esi
// 0074fe31  85c0                 test eax, eax
// 0074fe33  7428                 je 0x74fe5d
// 0074fe35  d901                 fld dword ptr [ecx]
// 0074fe37  d918                 fstp dword ptr [eax]
// 0074fe39  d94104               fld dword ptr [ecx + 4]
// 0074fe3c  d95804               fstp dword ptr [eax + 4]
// 0074fe3f  d94108               fld dword ptr [ecx + 8]
// 0074fe42  d95808               fstp dword ptr [eax + 8]
// 0074fe45  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0074fe48  89700c               mov dword ptr [eax + 0xc], esi
// 0074fe4b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0074fe4e  897010               mov dword ptr [eax + 0x10], esi
// 0074fe51  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0074fe54  897014               mov dword ptr [eax + 0x14], esi
// 0074fe57  8b7118               mov esi, dword ptr [ecx + 0x18]
// 0074fe5a  897018               mov dword ptr [eax + 0x18], esi
// 0074fe5d  4a                   dec edx
// 0074fe5e  83c01c               add eax, 0x1c
// 0074fe61  85d2                 test edx, edx
// 0074fe63  77cc                 ja 0x74fe31
// 0074fe65  5e                   pop esi
// 0074fe66  c3                   ret 
// library ogre-1.4.9/OgreEdgeListBuilder.cpp (function ??$_Uninit_fill_n@PAUCommonVertex@EdgeListBuilder@Ogre@@IU123@V?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@std@@@std@@YAXPAUCommonVertex@EdgeListBuilder@Ogre@@IABU123@AAV?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreEdgeListBuilder.cpp
