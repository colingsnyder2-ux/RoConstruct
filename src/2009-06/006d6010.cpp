// from server: 100% by auto
// roc 2009-06 006d6010  unit: RBX::Mechanism  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6010
//
// 006d6010  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d6014  8b542408             mov edx, dword ptr [esp + 8]
// 006d6018  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006d601c  3bca                 cmp ecx, edx
// 006d601e  7438                 je 0x6d6058
// 006d6020  56                   push esi
// 006d6021  85c0                 test eax, eax
// 006d6023  7428                 je 0x6d604d
// 006d6025  d901                 fld dword ptr [ecx]
// 006d6027  d918                 fstp dword ptr [eax]
// 006d6029  d94104               fld dword ptr [ecx + 4]
// 006d602c  d95804               fstp dword ptr [eax + 4]
// 006d602f  d94108               fld dword ptr [ecx + 8]
// 006d6032  d95808               fstp dword ptr [eax + 8]
// 006d6035  8b710c               mov esi, dword ptr [ecx + 0xc]
// 006d6038  89700c               mov dword ptr [eax + 0xc], esi
// 006d603b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 006d603e  897010               mov dword ptr [eax + 0x10], esi
// 006d6041  8b7114               mov esi, dword ptr [ecx + 0x14]
// 006d6044  897014               mov dword ptr [eax + 0x14], esi
// 006d6047  8b7118               mov esi, dword ptr [ecx + 0x18]
// 006d604a  897018               mov dword ptr [eax + 0x18], esi
// 006d604d  83c11c               add ecx, 0x1c
// 006d6050  83c01c               add eax, 0x1c
// 006d6053  3bca                 cmp ecx, edx
// 006d6055  75ca                 jne 0x6d6021
// 006d6057  5e                   pop esi
// 006d6058  c3                   ret 
// library ogre-1.4.9/OgreEdgeListBuilder.cpp (function ??$_Uninit_copy@PBUCommonVertex@EdgeListBuilder@Ogre@@PAU123@V?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@std@@@std@@YAPAUCommonVertex@EdgeListBuilder@Ogre@@PBU123@0PAU123@AAV?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreEdgeListBuilder.cpp
